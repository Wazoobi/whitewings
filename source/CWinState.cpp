////////////////////////////////////////////////////////////////////////////////
//	File Name	:	"CWinState.cpp"
//
//	Author		:	Ricky Crane (RC)
//
//	Purpose		:	To Display Game Win status and transistion between states.
///////////////////////////////////////////////////////////////////////////////

#include "CWinState.h"
#include "CMainMenuState.h"
#include "CGamePlayState.h"

#include "BitmapFontManager.h"


CWinState::CWinState(void)
{
	// Get pointers to the SGD singletons
	m_pD3D = CSGD_Direct3D::GetInstance();
	m_pTM = CSGD_TextureManager::GetInstance();
	m_pDI = CSGD_DirectInput::GetInstance();
	pGame = CGame::GetInstance();

	SetStateType(WIN);
}

CWinState::~CWinState(void)
{

}

CWinState* CWinState::GetInstance(void)
{
	// Lazy Instantiation
	static CWinState instance;
	return &instance;
}

void CWinState::Enter(void)
{
	m_nBackgroundID = m_pTM->LoadTexture("resource/graphics/WW_HowToPlay1.png");
	m_nFontImageID = m_pTM->LoadTexture("resource/graphics/JFR_Fonts.png",D3DCOLOR_ARGB(255, 0,0,0) );
}

void CWinState::Exit(void)
{
	m_pTM->UnloadTexture(m_nBackgroundID);
}

// split up Execute() into the 3 main steps of a game
bool CWinState::Input(void)
{

	if(m_pDI->KeyPressed(DIK_RETURN) || CSGD_DirectInput::GetInstance()->JoystickButtonPressed(DIR_A,0))
	{
		pGame->ClearStates();
		pGame->PushState(CMainMenuState::GetInstance());
	}

	return true;
}

void CWinState::Update(float fElapsedTime)
{

}

void CWinState::Render(void)
{
	m_pTM->Draw(m_nBackgroundID,0, 0, 1.57f, 1.18f,0,0,0,0,D3DCOLOR_ARGB(255,0,0,0));	//Showing HowTo Screen in black TODO: Add Background 

	BitmapFontManager::GetInstance()->DrawString("MISSION COMPLETE", m_nFontImageID,150,100,0.75f,0.75f);
	BitmapFontManager::GetInstance()->DrawString("PRESS ENTER TO RETURN", m_nFontImageID,150,200,0.75f,0.75f);

}