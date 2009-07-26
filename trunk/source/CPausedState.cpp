//////////////////////////////////////////////////////////////////////////
//	File Name	:	"CPausedState.cpp"
//
//	Author		:	Juno Madden (JM)
//
//	Purpose		:	To encapsulate all code for the paused state.
//////////////////////////////////////////////////////////////////////////

#include "CPausedState.h"
#include "CMainMenuState.h"
#include "CGamePlayState.h"
#include "COptionsState.h"

CPausedState::CPausedState(void)
{
	// Get pointers to the SGD singletons
	m_pD3D = CSGD_Direct3D::GetInstance();
	m_pTM = CSGD_TextureManager::GetInstance();
	m_pDI = CSGD_DirectInput::GetInstance();
	pGame = CGame::GetInstance();

	currentSelection = 0;

	SetStateType(PAUSED);
}

CPausedState::~CPausedState(void)
{

}

CPausedState* CPausedState::GetInstance(void)
{
	// Lazy Instantiation
	static CPausedState instance;
	return &instance;
}

void CPausedState::Enter(void)
{
	m_nImageID = m_pTM->LoadTexture("resource/graphics/JuM_SGD_MenuCursor.png");
	//TODO: Change Background
	//m_nBackgroundID = m_pTM->LoadTexture("resource/graphics/JuM_MissileCommand_BasicBackground.bmp");
}

void CPausedState::Exit(void)
{
	//m_pTM->UnloadTexture(m_nBackgroundID);
	m_pTM->UnloadTexture(m_nImageID);
	currentSelection = 0;
}

// split up Execute() into the 3 main steps of a game
bool CPausedState::Input(void)
{
	if(m_pDI->KeyPressed(DIK_UP) || CSGD_DirectInput::GetInstance()->JoystickGetLStickDirPressed(DIR_UP,0))
	{
		if(currentSelection == 0)
			currentSelection = 1;
		else
			currentSelection--;
	}

	if(m_pDI->KeyPressed(DIK_DOWN) || CSGD_DirectInput::GetInstance()->JoystickGetLStickDirPressed(DIR_DOWN,0))
	{
		if(currentSelection == 1)
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
			break;
		case 1:
			pGame->PopState();
			pGame->PopState();
			pGame->PushState(CMainMenuState::GetInstance());
			break;

		}
	}

	if(m_pDI->KeyPressed(DIK_ESCAPE) || CSGD_DirectInput::GetInstance()->JoystickButtonPressed(DIR_START,0))
		pGame->PopState();

	return true;
}

void CPausedState::Update(float fElapsedTime)
{

}

void CPausedState::Render(void)
{	
	//TODO: Change Background
	//m_pTM->Draw(m_nBackgroundID,0, 0, 1, 1, 0, 0, 0, 0, D3DCOLOR_ARGB(120, 0, 0, 0));
	m_pTM->Draw(m_nImageID, 100, 200 + currentSelection*35);
	CFontManager::GetInstance()->Draw("Paused", 150, 100, 0.5f, 0.5f);
	CFontManager::GetInstance()->Draw("Resume", 150, 200, 0.5f, 0.5f);
	CFontManager::GetInstance()->Draw("Exit", 150, 235, 0.5f, 0.5f);
}