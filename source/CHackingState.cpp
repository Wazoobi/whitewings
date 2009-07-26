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

#include "CPlayer.h"

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
	//TODO: Change Background
	m_nBackgroundID = m_pTM->LoadTexture("resource/graphics/JuM_MissileCommand_BasicBackground.bmp");
	nAvatarImageID = m_pTM->LoadTexture("resource/graphics/JuM_CrossHair.bmp", D3DCOLOR_XRGB(0,0,0));
	fPosX = pGame->GetScreenWidth()/2;
	fPosY = pGame->GetScreenHeight()/2;
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
	if((m_pDI->KeyDown(DIK_Z) || m_pDI->JoystickGetRStickDirDown(DIR_LEFT,0)) && fPosX > (nWidth))
		fPosX = (fPosX-fVelX*fElapsedTime);

	if((m_pDI->KeyDown(DIK_X) || m_pDI->JoystickGetRStickDirDown(DIR_RIGHT,0)) && fPosX < (pGame->GetScreenWidth()-nWidth))
		fPosX = (fPosX+fVelX*fElapsedTime);
}

void CHackingState::Render(void)
{
	//TODO: Change Background
	//m_pTM->Draw(m_nBackgroundID,0, 0, 1, 1, 0, 0, 0, 0, D3DCOLOR_ARGB(255, 0, 0, 0));
	m_pTM->Draw(nAvatarImageID, fPosX-nWidth/2, fPosY-nHeight/2);
}