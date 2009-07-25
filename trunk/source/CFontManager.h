//////////////////////////////////////////////////////////////////////////
//	File Name	:	"CFontManager.h"
//
//	Author		:	Juno Madden (JM)
//
//	Purpose		:	To encapsulate all bitmap font related code.
//////////////////////////////////////////////////////////////////////////

#pragma once

#include "SGD Wrappers/CSGD_TextureManager.h"
#include <string>
using std::string;

class CFontManager
{
	int m_nWidth;
	int m_nHeight;
	int m_nCellWidth;
	int m_nCellHeight;
	int m_nStartingCharacter;
	int m_nRow;
	int m_nColumn;
	int m_nMapPosition;

	int m_nImageID;

	CFontManager(void);
	~CFontManager(void);
	CFontManager(const CFontManager&) {}
	CFontManager& operator=(const CFontManager&) {}

public:

	//////////////////////////////////////////////////////////////////////////
	//	Function	:	Get Instance
	//
	//	Purpose		:	Grants global access to the singleton.
	//////////////////////////////////////////////////////////////////////////
	static CFontManager * GetInstance();

	//////////////////////////////////////////////////////////////////////////
	//	Function	:	Draw
	//
	//	Purpose		:	Renders the desired string using bitmap fonts.
	//////////////////////////////////////////////////////////////////////////
	void Draw(string szToWrite, int nPosX, int nPosY, float fScaleX = 1.0f, float fScaleY = 1.0f, D3DCOLOR dColor = 0xFFFFFFFF);
};
