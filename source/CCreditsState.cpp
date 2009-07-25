//////////////////////////////////////////////////////////////////////////
//	File Name	:	"CCreditsState.h"
//
//	Author		:	Juno Madden (JM)
//
//	Purpose		:	To encapsulate all code for showing the credits.
//////////////////////////////////////////////////////////////////////////

#include "CCreditsState.h"
#include "CMainMenuState.h"
#include "COptionsState.h"

CCreditsState::CCreditsState(void)
{
	// Get pointers to the SGD singletons
	m_pD3D = CSGD_Direct3D::GetInstance();
	m_pTM = CSGD_TextureManager::GetInstance();
	m_pDI = CSGD_DirectInput::GetInstance();
	m_pFM = CFontManager::GetInstance();

	pGame = CGame::GetInstance();
}

CCreditsState::~CCreditsState(void)
{

}

CCreditsState* CCreditsState::GetInstance(void)
{
	// Lazy Instantiation
	static CCreditsState instance;
	return &instance;
}

void CCreditsState::Enter(void)
{	
	//TODO: Change Background
	m_nBackgroundID = m_pTM->LoadTexture("resource/graphics/JuM_MissileCommand_BasicBackground.bmp");
}

void CCreditsState::Exit(void)
{
	m_pTM->UnloadTexture(m_nBackgroundID);
}

// split up Execute() into the 3 main steps of a game
bool CCreditsState::Input(void)
{
	if(m_pDI->CheckBufferedKeysEx() || CSGD_DirectInput::GetInstance()->JoystickButtonPressed(DIR_A,0))
	{
		pGame->PopState();
	}

	return true;
}

void CCreditsState::Update(float fElapsedTime)
{

}

void CCreditsState::Render(void)
{
	//TODO: Change Background
	m_pTM->Draw(m_nBackgroundID,0, 0, 1, 1, 0, 0, 0, 0, D3DCOLOR_ARGB(255, 0, 0, 0));

}