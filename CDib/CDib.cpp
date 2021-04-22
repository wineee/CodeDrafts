#include <cstdio>
#include <fstream>
#include "CDib.h"

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
  if (sizeof(RGBQUAD) * numberOfColors != colorTableSize) {
    delete[] pDib;
    pDib = nullptr;
    throw "Sizeof RGB QUAD Error!";
  }

  m_pData = pDib + sizeof(BITMAPINFOHEADER) + colorTableSize;
  return true;
}

int CDib::GetNumOfColors() {
  int numberOfColors = 0;
  if (m_pBitMapInfoHeader->biClrUsed)
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


bool CDib::Create() {
  if (pDib) delete [] pDib;
  int colorTableSize = 0;
  if (nColor == 1) {
     
  }
}

int main() {
  
  return 0;
}
