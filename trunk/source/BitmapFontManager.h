#pragma once

#include "SGD Wrappers/CSGD_TextureManager.h"
#include <iostream>
#include <fstream>
using namespace std;


struct CHARRECT
{
	char character;
	RECT bounding;
	int Offset;
};
struct FONT
{
	vector<CHARRECT> CharRects;
	int FontNumber;
};
class BitmapFontManager
{
private:
	int m_nNumFonts ;
	vector<FONT> m_vFonts;
	
	
public:
	BitmapFontManager(void);
	~BitmapFontManager(void);
	static BitmapFontManager *GetInstance(void);
	bool LoadBinary(int nFontImageID);
	bool DrawString(string szText, int nFontImageID, int nPosX, int nPosY, float fScaleX = 1, float fScaleY = 1, DWORD dwTransparencyColor = D3DCOLOR_ARGB(255, 255, 255,255));

};
