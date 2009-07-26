//////////////////////////////////////////////////////////////////////////
//	File Name	:	"CHowToPlayState.cpp"
//
//	Author		:	Juno Madden (JM)
//
//	Purpose		:	To encapsulate all code for the instruction screen.
//////////////////////////////////////////////////////////////////////////

#include "CHowToPlayState.h"
#include "CMainMenuState.h"
#include "CGamePlayState.h"
#include "COptionsState.h"

CHowToPlayState::CHowToPlayState(void)
{
	// Get pointers to the SGD singletons
	m_pD3D = CSGD_Direct3D::GetInstance();
	m_pTM = CSGD_TextureManager::GetInstance();
	m_pDI = CSGD_DirectInput::GetInstance();
	m_pFM = CFontManager::GetInstance();
	pGame = CGame::GetInstance();

	SetStateType(HOWTOPLAY);
}

CHowToPlayState::~CHowToPlayState(void)
{

}

CHowToPlayState* CHowToPlayState::GetInstance(void)
{
	// Lazy Instantiation
	static CHowToPlayState instance;
	return &instance;
}

void CHowToPlayState::Enter(void)
{
	//TODO: Change Background
	m_nBackgroundID = m_pTM->LoadTexture("resource/graphics/JuM_MissileCommand_BasicBackground.bmp");
}

void CHowToPlayState::Exit(void)
{
	m_pTM->UnloadTexture(m_nBackgroundID);
}

// split up Execute() into the 3 main steps of a game
bool CHowToPlayState::Input(void)
{
	if(m_pDI->CheckBufferedKeysEx() || CSGD_DirectInput::GetInstance()->JoystickButtonPressed(DIR_A,0))
	{
		pGame->PopState();
	}

	return true;
}

void CHowToPlayState::Update(float fElapsedTime)
{

}

void CHowToPlayState::Render(void)
{
	//TODO: Change Background
	m_pTM->Draw(m_nBackgroundID,0, 0, 1, 1, 0, 0, 0, 0, D3DCOLOR_ARGB(255, 0, 0, 0));
}