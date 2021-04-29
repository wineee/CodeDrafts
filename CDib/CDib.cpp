//#pragma pack(1)

#include <cstdio>
#include <fstream>
#include <cstring>
#include <iostream>
#include "CDib.h"

CDib::CDib() {
  pDib = nullptr;
}

CDib::~CDib() {
  if (pDib != nullptr)
    delete [] pDib;
}

bool CDib::Load(const char *filename) {
  ::std::ifstream ifs(filename, ::std::ios::binary);
  ifs.seekg(0, ::std::ios::end); // 指向文件末尾
  DWORD size = ifs.tellg(); // 得到文件大小
  ifs.seekg(0, ::std::ios::beg); // 文件指针指向文件头
  ifs.read((char *)&m_BitMapFileHeader, sizeof(BITMAPFILEHEADER));
  if (m_BitMapFileHeader.bfType != 0x4d42) {
    throw "File Type Error!";
    return false;
  }
  if (size != m_BitMapFileHeader.bfSize) {
    throw "File Format Error!";
    return false;
  }
    
  pDib = new BYTE[size - sizeof(BITMAPFILEHEADER)];
  if (!pDib) {
    throw "Insufficient Memory!";
    return false;
  }
  ifs.read((char *)pDib, size - sizeof(BITMAPFILEHEADER));

  m_pBitMapInfoHeader = (BITMAPINFOHEADER *)pDib;
  m_pRgbQuad = (RGBQUAD *)(pDib + sizeof(BITMAPINFOHEADER));
  int colorTableSize = m_BitMapFileHeader.bfOffBits - sizeof(BITMAPFILEHEADER) - m_pBitMapInfoHeader->biSize;

  int numberOfColors = GetNumOfColors();
  if (sizeof(RGBQUAD) * numberOfColors != colorTableSize) { // 校验文件结构
    delete[] pDib;
    pDib = nullptr;
    throw "Sizeof RGB QUAD Error!";
  }

  m_pData = pDib + sizeof(BITMAPINFOHEADER) + colorTableSize;
  return true;
}

// 获取颜色数目
int CDib::GetNumOfColors() {
  int numberOfColors = 0;
  if (m_pBitMapInfoHeader->biClrUsed) // 信息头中规定了颜色表数目
    numberOfColors = m_pBitMapInfoHeader->biClrUsed;
  else {
    switch(m_pBitMapInfoHeader->biBitCount) {
    case 1: numberOfColors = 2; break; 
    case 4: numberOfColors = 16; break; 
    case 8: numberOfColors = 256;
    }
  }
  return numberOfColors;
}

// 建立一个简单的 BMP 文件结构，首先设置文件头结构 m_pBitMapInfoHeader， 然后建立存储文件后三部分的空间，并将相应数据写入。
bool CDib::Create(int nWidth, int nHeight, int nColor) {
  if (pDib != nullptr)
    delete [] pDib;
  // 设置颜色表大小
  int colorTableSize = 0;
  if (nColor == 1) 
    colorTableSize = 2 * sizeof(RGBQUAD);
  else if (nColor == 4 || nColor == 8)
    colorTableSize = 8 * sizeof(RGBQUAD);
  else
    nColor = 24;
  int bytePerLine = ((nWidth * nColor + 31) / 32) * 4;
  // 计算每行占用的字节数， +31为了向上取整
  int dataSize = nHeight * bytePerLine;
  // 计算所有像素占用的字符

  // 设置头文件结构
  m_BitMapFileHeader.bfType = 0x4d42;
  m_BitMapFileHeader.bfReserved1 = 0;
  m_BitMapFileHeader.bfReserved2 = 0;
  m_BitMapFileHeader.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + colorTableSize;
  m_BitMapFileHeader.bfSize = m_BitMapFileHeader.bfOffBits + dataSize;

  // 建立 BMP 文件后三部分的结构
  pDib = new BYTE[m_BitMapFileHeader.bfSize - sizeof(BITMAPFILEHEADER)];
  if (!pDib) {
    return false;
  }

  m_pBitMapInfoHeader = (BITMAPINFOHEADER *) pDib;
  m_pBitMapInfoHeader->biSize = sizeof(BITMAPINFOHEADER);
  m_pBitMapInfoHeader->biBitCount = nColor;
  m_pBitMapInfoHeader->biClrImportant = 1;
  m_pBitMapInfoHeader->biClrUsed = colorTableSize/sizeof(RGBQUAD);
  m_pBitMapInfoHeader->biCompression = 0;
  m_pBitMapInfoHeader->biPlanes = 1;
  m_pBitMapInfoHeader->biSizeImage = dataSize;
  m_pBitMapInfoHeader->biXPelsPerMeter = 1024;
  m_pBitMapInfoHeader->biYPelsPerMeter = 1024;
  m_pBitMapInfoHeader->biHeight = nHeight;
  m_pBitMapInfoHeader->biWidth = nWidth;

  // 设置像素数据指针
  m_pData = pDib+m_BitMapFileHeader.bfOffBits-sizeof(BITMAPFILEHEADER);

  // 设置颜色表
  m_pRgbQuad = (RGBQUAD *)(pDib + sizeof(BITMAPINFOHEADER));
  switch(nColor) {
  case 1: // 黑白双色
    SetColor(m_pRgbQuad, 0xff, 0xff, 0xff); // 白
    SetColor(m_pRgbQuad+1, 0, 0, 0); // 黑
    memset(m_pData, 0x00, dataSize); // 设置图像中每个像素颜色索引值为 0
    break;
  case 4:
  case 8: // 定义8种颜色，0xffffff,0xffff00,0xff00ff....
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 2; j++)
	for (int k = 0; k < 2; k++) {
	  SetColor(m_pRgbQuad+7-i*4-j*2-k, i*255, j*255, k*255);
	}
    memset(m_pData, 0x00, dataSize); // 设置每个像素颜色索引值为0
    break;
  default:
    memset(m_pData, 0xff, dataSize); // 设置真彩色图像全白
  }
  return true;
}

// 设置颜色表项
void CDib::SetColor(RGBQUAD *rgb, BYTE r, BYTE g, BYTE b) {
  if (rgb) {
    rgb->rgbBlue = b;
    rgb->rgbGreen = g;
    rgb->rgbRed = r;
    rgb->rgbReserved = 0;
  }
  else
    throw "RGBQUAD unit not exist";
}

// 保存 BMP 图像
bool CDib::Save(const char *filename) {
  if (pDib == nullptr)
    return false;
  std::ofstream ofs(filename, std::ios::binary);
  if (ofs.fail()) 
    return false;
  
  // 写文件头
  ofs.write((char *)&m_BitMapFileHeader, sizeof(BITMAPFILEHEADER));
  // 剩余三部分
  ofs.write((char *)pDib, m_BitMapFileHeader.bfSize-sizeof(BITMAPFILEHEADER));
  
  ofs.close();
  return true;
}
 
// 以图像中心为圆心画圆
void CDib::Circle() {
  int nWidth = m_pBitMapInfoHeader->biWidth;
  int nHeight = m_pBitMapInfoHeader->biHeight;
  //int nColor = m_pBitMapInfoHeader->biBitCount;
  int x = nWidth / 2;
  int y = nHeight / 2;
  int radius = x>y ? y-2 : x-2; // 圆的半径
  for (int i = 0; i < nWidth; i++)
    for (int j = nHeight-1; j >= 0; j--) {
      int dist = (x-i)*(x-i) + (y-j)*(y-j); // 点（i，j） 到圆心的距离的平方
      if (dist > (radius-1)*(radius-1) && dist < (radius+1)*(radius+1)) {
	SetPixelColor(j, i); // 在 j 行 i 列画圆
      }
    }
}

// 给图像中定点上画颜色
void CDib::SetPixelColor(int i, int j) {
  int nWidth = m_pBitMapInfoHeader->biWidth;
  int nColor = m_pBitMapInfoHeader->biBitCount;
  int bytePerLine = ((nWidth*nColor + 31) / 32) * 4;
  switch(nColor) {
  case 1: // 单色,颜色索引值1
    m_pData[i * bytePerLine + j/8] |= (1<<(7-j%8));
    break;
  case 4: // 16 色，颜色索引值 7 = 0000 0111
    m_pData[i * bytePerLine + j/2] &= (0x0f << (4*(j%2))); // 清 0
    m_pData[i * bytePerLine + j/2] |= (0x07 << (4*(1-j%2))); // 设为 7
    break;
  case 8: // 256 色，颜色索引值 7 = 0000 0111
    m_pData[i * bytePerLine + j] = 7;
    break;
  default: // 真彩色，设为黑色
    BYTE *p = m_pData + i * bytePerLine + j * 3;
    *p = *(p+1) = *(p+2) = 0;
  }
}

int main() {
  int nWidth = 200;
  int nHeight = 100;
  int nColor = 4;
  CDib a;
  a.Create(nWidth, nHeight, nColor);
  a.Save("c.bmp");
  
  if (a.Load("c.bmp")) {
    std::cout << "ok!";
    a.Circle();
    a.Save("cc.bmp");
  }
  return 0;
}


