////////////////////////////////////////////////////////////////////////////////
//	File Name	:	"CGameOverState.cpp"
//
//	Author		:	Ricky Crane (RC)
//
//	Purpose		:	To Display GameOver status and transistion between states.
///////////////////////////////////////////////////////////////////////////////

#include "CGameOverState.h"
#include "CMainMenuState.h"
#include "CGamePlayState.h"

#include "BitmapFontManager.h"


CGameOverState::CGameOverState(void)
{
	// Get pointers to the SGD singletons
	m_pD3D = CSGD_Direct3D::GetInstance();
	m_pTM = CSGD_TextureManager::GetInstance();
	m_pDI = CSGD_DirectInput::GetInstance();
	pGame = CGame::GetInstance();

	SetStateType(LOSE);
}

CGameOverState::~CGameOverState(void)
{

}

CGameOverState* CGameOverState::GetInstance(void)
{
	// Lazy Instantiation
	static CGameOverState instance;
	return &instance;
}

void CGameOverState::Enter(void)
{
	m_nBackgroundID = m_pTM->LoadTexture("resource/graphics/WW_HowToPlay1.png");
	m_nFontImageID = m_pTM->LoadTexture("resource/graphics/JFR_Fonts.png",D3DCOLOR_ARGB(255, 0,0,0) );
}

void CGameOverState::Exit(void)
{
	m_pTM->UnloadTexture(m_nBackgroundID);
	currentSelection = 0;

}

// split up Execute() into the 3 main steps of a game
bool CGameOverState::Input(void)
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
			pGame->ClearStates();
			pGame->PushState(CGamePlayState::GetInstance());
			break;
		case 1:
			pGame->ClearStates();
			pGame->PushState(CMainMenuState::GetInstance());
			break;

		}
	}

	return true;
}

void CGameOverState::Update(float fElapsedTime)
{

}

void CGameOverState::Render(void)
{
	//TODO: Change Background
	m_pTM->Draw(m_nBackgroundID,0, 0, 1.57f, 1.18f,0,0,0,0,D3DCOLOR_ARGB(255,0,0,0));	//Showing HowTo Screen in black TODO: Add Background 

	BitmapFontManager::GetInstance()->DrawString("GAME OVER", m_nFontImageID,150,100,0.75f,0.75f);
	BitmapFontManager::GetInstance()->DrawString("CONTINUE", m_nFontImageID,150,200,0.75f,0.75f, D3DCOLOR_ARGB(255,255 * (currentSelection != 0),255,255));
	BitmapFontManager::GetInstance()->DrawString("EXIT"  , m_nFontImageID,150,235,0.75f,0.75f, D3DCOLOR_ARGB(255,255 * (currentSelection != 1),255,255));


}