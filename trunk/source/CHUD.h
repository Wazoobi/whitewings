#pragma once

#include "BitmapFontManager.h"

class CHUD
{
private:
	int nFontID;
public:
	CHUD(void);
	~CHUD(void);
	
	static CHUD *GetInstance(void);

	bool DrawBar(int nPosX,  int nPosY, float fCurValue, float fMaxValue, int nWidth = 100, int nHeight = 2, int nRed = 255, int nGreen = 255, int nBlue = 255);

	bool DrawCounter(int nValue, int nImageID, int nPosX, int nPosY, float fScaleX, float fScaleY);

	bool DrawActions(string szLeftBumperAction, string szRightBumberAction);
};
