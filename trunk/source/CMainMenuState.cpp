//////////////////////////////////////////////////////////////////////////
//	File Name	:	"CMainMenuState.cpp"
//
//	Author		:	Juno Madden (JM)
//
//	Purpose		:	To encapsulate all code for the main menu.
//////////////////////////////////////////////////////////////////////////

#include "CMainMenuState.h"
#include "CGamePlayState.h"
#include "COptionsState.h"
#include "CCreditsState.h"
#include "CHowToPlayState.h"
#include "CHackingState.h"

#include "CTempState.h"

CMainMenuState::CMainMenuState(void)
{
	// Get pointers to the SGD singletons
	m_pD3D = CSGD_Direct3D::GetInstance();
	m_pTM = CSGD_TextureManager::GetInstance();
	m_pDI = CSGD_DirectInput::GetInstance();
	pGame = CGame::GetInstance();

	currentSelection = 0;
}

CMainMenuState::~CMainMenuState(void)
{

}

CMainMenuState* CMainMenuState::GetInstance(void)
{
	// Lazy Instantiation
	static CMainMenuState instance;
	return &instance;
}

void CMainMenuState::Enter(void)
{
	m_nImageID = m_pTM->LoadTexture("resource/graphics/JuM_SGD_MenuCursor.png");


	//TODO: Change Background
	//m_nBackgroundID = m_pTM->LoadTexture("resource/graphics/JuM_City.bmp");
}

void CMainMenuState::Exit(void)
{
	m_pTM->UnloadTexture(m_nImageID);
	//m_pTM->UnloadTexture(m_nBackgroundID);
}

// split up Execute() into the 3 main steps of a game
bool CMainMenuState::Input(void)
{
	if(m_pDI->KeyPressed(DIK_UP) || CSGD_DirectInput::GetInstance()->JoystickGetLStickDirPressed(DIR_UP,0))
	{
		if(currentSelection == 0)
			currentSelection = 4;
		else
			currentSelection--;
	}

	if(m_pDI->KeyPressed(DIK_DOWN) || CSGD_DirectInput::GetInstance()->JoystickGetLStickDirPressed(DIR_DOWN,0))
	{
		if(currentSelection == 4)
			currentSelection = 0;
		else
			currentSelection++;
	}

	if(m_pDI->KeyPressed(DIK_RETURN) || CSGD_DirectInput::GetInstance()->JoystickButtonPressed(DIR_A,0))
	{
		switch(currentSelection)
		{
		case 0:
			pGame->PopState();
			//pGame->PushState(CGamePlayState::GetInstance());
			pGame->PushState(CTempState::GetInstance());
			break;
		case 1:
			pGame->PopState();
			pGame->PushState(COptionsState::GetInstance());
			break;
		case 2:
			pGame->PushState(CHowToPlayState::GetInstance());
			break;
		case 3:
			pGame->PushState(CCreditsState::GetInstance());
			break;
		case 4:
			return false;
			break;
		}
	}

	return true;
}

void CMainMenuState::Update(float fElapsedTime)
{

}

void CMainMenuState::Render(void)
{
	//TODO: Change Background stuff
	//m_pTM->Draw(m_nBackgroundID, 0, 0, 1.25f, 1.0f);
	m_pTM->Draw(m_nImageID, 100, 200 + currentSelection*35);
	CFontManager::GetInstance()->Draw("Ping Attack", 100, 100);
	CFontManager::GetInstance()->Draw("Play", 150, 200, 0.5f, 0.5f);
	CFontManager::GetInstance()->Draw("Options", 150, 235, 0.5f, 0.5f);
	CFontManager::GetInstance()->Draw("How To Play", 150, 270, 0.5f, 0.5f);
	CFontManager::GetInstance()->Draw("Credits", 150, 305, 0.5f, 0.5f);
	CFontManager::GetInstance()->Draw("Exit", 150, 340, 0.5f, 0.5f);
}