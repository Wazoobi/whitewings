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

#include "CTempState.h"

CHowToPlayState::CHowToPlayState(void)
{
	// Get pointers to the SGD singletons
	m_pD3D = CSGD_Direct3D::GetInstance();
	m_pTM = CSGD_TextureManager::GetInstance();
	m_pDI = CSGD_DirectInput::GetInstance();
	m_pFM = CFontManager::GetInstance();
	pGame = CGame::GetInstance();

	m_bFirstTime = true;
	m_fFirstTimeTimer = 0.0f;

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
	m_nBackgroundID = m_pTM->LoadTexture("resource/graphics/WW_HowToPlay1.png");
	m_nPlayerID = m_pTM->LoadTexture("resource/graphics/Ping.bmp");
	m_nWalkerID = m_pTM->LoadTexture("resource/graphics/Walker.bmp");
	m_nHackOrbID = m_pTM->LoadTexture("resource/graphics/JuM_SpecialMissile.bmp");
	m_nJumperID = m_pTM->LoadTexture("resource/graphics/Jumper.bmp");
	m_nFlyerID = m_pTM->LoadTexture("resource/graphics/Flyer.bmp");
	m_nTerminalID = m_pTM->LoadTexture("resource/graphics/HackTerminal.bmp");
	//m_nDoorID = m_pTM->LoadTexture("resource/graphics/Door.bmp");	Dont have the door image

}

void CHowToPlayState::Exit(void)
{
	m_pTM->UnloadTexture(m_nBackgroundID);
}

// split up Execute() into the 3 main steps of a game
bool CHowToPlayState::Input(void)
{
	if((m_pDI->CheckBufferedKeysEx() || CSGD_DirectInput::GetInstance()->JoystickButtonPressed(DIR_A,0)) && !m_bFirstTime)
	{
		pGame->PopState();
	}

	return true;
}

void CHowToPlayState::Update(float fElapsedTime)
{
	if(m_bFirstTime)
	{
		m_fFirstTimeTimer += fElapsedTime;
		if(m_fFirstTimeTimer > 5.0f)
		{
			m_bFirstTime = false;
			pGame->PopState();
			pGame->PushState(CGamePlayState::GetInstance());
		}
	}
}

void CHowToPlayState::Render(void)
{
	//TODO: Change Background
	m_pTM->Draw(m_nBackgroundID,0, 0, 1.57f, 1.18f);
	m_pTM->Draw(m_nPlayerID,500, 120);
	m_pTM->Draw(m_nWalkerID,460, 185);
	m_pTM->Draw(m_nJumperID,500, 185);
	m_pTM->Draw(m_nFlyerID,540, 185);

	m_pTM->Draw(m_nTerminalID,500, 280);

	m_pTM->Draw(m_nHackOrbID,500, 390);
	
	m_pTM->Draw(m_nTerminalID,500, 510);




}