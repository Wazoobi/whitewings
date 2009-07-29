//////////////////////////////////////////////////////////////////////////
//	File Name	:	"CFontManager.cpp"
//
//	Author		:	Juno Madden (JM)
//
//	Purpose		:	To encapsulate all bitmap font related code.
//////////////////////////////////////////////////////////////////////////

#include "CFontManager.h"

CFontManager::CFontManager(void)
{
	m_nWidth = 16;
	m_nHeight = 16;
	m_nCellWidth = 32;
	m_nCellHeight = 32;
	m_nStartingCharacter = ' ';
	m_nRow = 0;
	m_nColumn = 0;
	m_nMapPosition = 0;

	m_nImageID = CSGD_TextureManager::GetInstance()->LoadTexture("resource/graphics/JuM_DoB_font.bmp", D3DCOLOR_XRGB(0,0,0));
}

CFontManager::~CFontManager(void)
{
}

CFontManager* CFontManager::GetInstance()
{
	static CFontManager instance;
	return &instance;
}

void CFontManager::Draw(string szToWrite, int nPosX, int nPosY, float fScaleX, float fScaleY, D3DCOLOR dColor)
{
	for( int i = 0; i < szToWrite.size(); ++i )
	{
		m_nMapPosition = toupper(szToWrite[i]) - m_nStartingCharacter;
		m_nRow = m_nMapPosition / m_nWidth;
		m_nColumn = m_nMapPosition % m_nWidth;
		RECT todraw;
		todraw.top = m_nRow * m_nCellHeight;
		todraw.bottom = todraw.top + m_nCellHeight;
		todraw.left = m_nColumn * m_nCellWidth;
		todraw.right = todraw.left + m_nCellWidth;

		CSGD_TextureManager::GetInstance()->Draw(m_nImageID, nPosX + i*m_nCellWidth*fScaleX, nPosY, fScaleX, fScaleY, &todraw, 0, 0, 0, dColor);
	}
}