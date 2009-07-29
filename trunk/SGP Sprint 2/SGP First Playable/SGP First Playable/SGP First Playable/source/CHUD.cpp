#include "CHUD.h"

#include "SGD Wrappers/CSGD_Direct3D.h"
#include "SGD Wrappers/SGD_Math.h"

CHUD::CHUD(void)
{
	nFontID = CSGD_TextureManager::GetInstance()->LoadTexture("resource/graphics/JFR_Fonts.png",D3DCOLOR_ARGB(255, 0,0,0) );	
}

CHUD::~CHUD(void)
{
}

CHUD* CHUD::GetInstance()
{
	static CHUD instance;
	return &instance;
}

bool CHUD::DrawBar(int nPosX,  int nPosY, float fCurValue, float fMaxValue, int nWidth, int nHeight, int nRed, int nGreen, int nBlue)
{

	RECT temp;

	temp.top = nPosY;
	temp.bottom = nPosY + nHeight;
	temp.left = nPosX;
	temp.right = nPosX + nWidth;

	
	CSGD_Direct3D::GetInstance()->DrawRect(temp,255,255,255);
	temp.right = Lerp(nPosX,nPosX + nWidth,fCurValue/fMaxValue);
	CSGD_Direct3D::GetInstance()->DrawRect(temp,nRed,nGreen,nBlue);

	CSGD_Direct3D::GetInstance()->SpriteBegin();

	return true;
}

bool CHUD::DrawCounter(int nValue, int nImageID, int nPosX, int nPosY, float fScaleX, float fScaleY)
{
	char temp[5];

	sprintf_s(temp, sizeof(temp),"X%d", nValue);

	CSGD_TextureManager::GetInstance()->Draw(nImageID, nPosX, nPosY, fScaleX,fScaleY);

	BitmapFontManager::GetInstance()->DrawString((string)temp,nFontID,nPosX + CSGD_TextureManager::GetInstance()->GetTextureWidth(nImageID),nPosY,fScaleX,fScaleY);

	return true;
}

bool CHUD::DrawActions(string szLeftBumperAction, string szRightBumberAction)
{
	BitmapFontManager::GetInstance()->DrawString(szLeftBumperAction,nFontID, 5, 550,0.75f,0.75f);

	BitmapFontManager::GetInstance()->DrawString(szRightBumberAction,nFontID, 800 - (28 * szRightBumberAction.length()),550,0.75f,0.75f);

	return true;
}