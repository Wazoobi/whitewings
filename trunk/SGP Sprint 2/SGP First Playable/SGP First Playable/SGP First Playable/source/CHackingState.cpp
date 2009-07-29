//////////////////////////////////////////////////////////////////////////
//	File Name	:	"CHackingState.h"
//
//	Author		:	Juno Madden (JM)
//
//	Purpose		:	To encapsulate all code for the hacking mini-games.
//////////////////////////////////////////////////////////////////////////

#include "CHackingState.h"
#include "CPausedState.h"
#include "CMainMenuState.h"
#include "COptionsState.h"

#include "CSGD_EventSystem.h"

#include "CPlayer.h"

#include "CLevel.h"

CHackingState::CHackingState(void)
{
	// Get pointers to the SGD singletons
	m_pD3D = CSGD_Direct3D::GetInstance();
	m_pTM = CSGD_TextureManager::GetInstance();
	m_pDI = CSGD_DirectInput::GetInstance();
	m_pFM = CFontManager::GetInstance();

	pGame = CGame::GetInstance();

	nAvatarImageID = 0;
	fPosX = 0.0f;
	fPosY = 0.0f;
	fVelX = 0.0f;
	fVelY = 0.0f;
	m_nBackgroundID = 0;

	SetStateType(HACKING);

	m_nTerminalSignature = 0;
}

CHackingState::~CHackingState(void)
{

}

CHackingState* CHackingState::GetInstance(void)
{
	// Lazy Instantiation
	static CHackingState instance;
	return &instance;
}

void CHackingState::Enter(void)
{	

	fMover = 0;
	//TODO: Change Background
	m_nBackgroundID = m_pTM->LoadTexture("resource/graphics/MiniGameLevel.bmp");
	nAvatarImageID = m_pTM->LoadTexture("resource/graphics/JuM_CrossHair.bmp", D3DCOLOR_XRGB(0,0,0));
	fPosX = pGame->GetScreenWidth()/2;
	fPosY = 164.0f;
	fVelX = 500.0f;
	fVelY = 500.0f;
	nWidth = 32;
	nHeight = 32;
}

void CHackingState::Exit(void)
{
	m_pTM->UnloadTexture(m_nBackgroundID);
	m_pTM->UnloadTexture(nAvatarImageID);
}

// split up Execute() into the 3 main steps of a game
bool CHackingState::Input(void)
{
	if(m_pDI->KeyPressed(DIK_ESCAPE) || CSGD_DirectInput::GetInstance()->JoystickButtonPressed(DIR_START,0))
	{
		pGame->PushState(CPausedState::GetInstance());
	}

	return true;
}

void CHackingState::Update(float fElapsedTime)
{
	if((m_pDI->KeyDown(DIK_LEFT) || m_pDI->JoystickGetLStickDirDown(DIR_LEFT,0)) && fPosX > (144+nWidth+25))
		fPosX = (fPosX-fVelX*fElapsedTime);

	if((m_pDI->KeyDown(DIK_RIGHT) || m_pDI->JoystickGetLStickDirDown(DIR_RIGHT,0)) && fPosX < (pGame->GetScreenWidth()-nWidth-144-25))
		fPosX = (fPosX+fVelX*fElapsedTime);

	// TODO: Send off a mini-game win event if the player finishes the mini-game

 	if(fMover > 1848+150)
	{
		CSGD_EventSystem::GetInstance()->SendEvent("MINIGAMESUCCESS", &m_nTerminalSignature);
		CPlayer::GetInstance()->SetIsHackingTerminal(false);
		pGame->PopState();
	}
}

void CHackingState::Render(void)
{
	//TODO: Change Background
	fMover++;
	RECT hackingGameDrawRect;
	SetRect(&hackingGameDrawRect, 0, 1848-fMover, 512, 2048-fMover);
	m_pTM->Draw(m_nBackgroundID, 144, 64, 1.0f, 1.0f, &hackingGameDrawRect);
	m_pTM->Draw(nAvatarImageID, fPosX-nWidth/2, 200-16);
}