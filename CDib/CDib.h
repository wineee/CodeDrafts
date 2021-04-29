#ifndef CDIB_H
#define CDIB_H

#pragma pack(1)
//设置结构体的边界对齐为1个字节，也就是所有数据在内存中是连续存储的。

typedef unsigned short WORD;
typedef unsigned long DWORD;
typedef long LONG;
typedef unsigned char BYTE;

// 位图文件头结构
typedef struct tagBITMAPFILEHEADER {
  WORD bfType; // 位图文件类型，是0x4D42
  DWORD bfSize; // 文件占用几字节
  WORD bfReserved1; // 保留字， 必须是0
  WORD bfReserved2; // 0
  DWORD bfOffBits;  // 位图数据起始位置，相对文件头偏移量
} BITMAPFILEHEADER;

// 位图信息头结构
typedef struct tagBITMAPINFOHEADER {
  DWORD biSize; // 本结构占用字节数
  LONG biWidth; // 位图宽度
  LONG biHeight; // 位图高度
  WORD biPlanes; // 目标设备级别， 一定是1
  WORD biBitCount; // 单个像素需要位数，1-双色，4-16色，8-256色，24-真彩色
  DWORD biCompression; // 压缩类型 0-不压缩 1-BI_RLE8, 2-BI_RLE4
  DWORD biSizeImage; // 位图大小，字节
  LONG biXPelsPerMeter; // 水平分辨率，每米像素数
  LONG biYPelsPerMeter; // 垂直分辨率
  DWORD biClrUsed; // 位图实际使用的颜色表中的颜色数
  DWORD biClrImportant; // 位图的显示过程中重要颜色数
} BITMAPINFOHEADER;

// 位图颜色表项
typedef struct tagRGBQUAD {
  BYTE rgbBlue; // 蓝色亮度 0～255
  BYTE rgbGreen;
  BYTE rgbRed;
  BYTE rgbReserved; // 固定为0
} RGBQUAD;

class CDib {
 public:
  CDib();
  ~CDib();
  bool Load( const char * filename); // 打开 BMP 文件
  bool Save( const char * filename); // 保存 BMP 文件
  bool Create( int nWidth, int nHeight, int nColor); // 建立默认 BMP 结构
  void Circle(); // 画圆
 private:
  void SetPixelColor(int i, int j); // 画圆时设置像素点颜色
  int GetNumOfColors(); // 获取颜色表表项数目
  void SetColor(RGBQUAD *rgb, BYTE r, BYTE g, BYTE b); // 设置一个颜色表表项
  BITMAPFILEHEADER m_BitMapFileHeader; 
  BITMAPINFOHEADER *m_pBitMapInfoHeader;
  RGBQUAD *m_pRgbQuad; // 指向颜色表
  BYTE *m_pData; // 像素阵列
  BYTE *pDib;
};

#endif
