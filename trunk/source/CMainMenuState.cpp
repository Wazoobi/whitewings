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

#include "CGameOverState.h"

#include "BitmapFontManager.h"

#include "CTempState.h"

CMainMenuState::CMainMenuState(void)
{
	// Get pointers to the SGD singletons
	m_pD3D = CSGD_Direct3D::GetInstance();
	m_pTM = CSGD_TextureManager::GetInstance();
	m_pDI = CSGD_DirectInput::GetInstance();
	pGame = CGame::GetInstance();

	currentSelection = 0;

	FontID = -1;

	SetStateType(MAINMENU);
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
	m_nBackgroundID = m_pTM->LoadTexture("resource/graphics/WW_MMBackground.png");

	FontID = m_pTM->LoadTexture("resource/graphics/JFR_Fonts.png",D3DCOLOR_ARGB(255, 0,0,0) );


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
			pGame->PushState(CGameOverState::GetInstance());
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
	m_pTM->Draw(m_nBackgroundID, 0, 0, 3.125f, 2.35f);
	//m_pTM->Draw(m_nImageID, 320, 200 + currentSelection*35);
	//CFontManager::GetInstance()->Draw("Ping Attack", 100, 100);
	//CFontManager::GetInstance()->Draw("Play", 350, 200, 0.5f, 0.5f);
	//CFontManager::GetInstance()->Draw("Options", 350, 235, 0.5f, 0.5f);
	//CFontManager::GetInstance()->Draw("How To Play", 350, 270, 0.5f, 0.5f);
	//CFontManager::GetInstance()->Draw("Credits", 350, 305, 0.5f, 0.5f);
	//CFontManager::GetInstance()->Draw("Exit", 350, 340, 0.5f, 0.5f);

	BitmapFontManager::GetInstance()->DrawString("PING ATTACK",FontID,150,50,1.5f,1.5f);		//Drawn using the WhiteWing Bitmap Font Manager
	
	BitmapFontManager::GetInstance()->DrawString("PLAY",		FontID,270,200,1,1,D3DCOLOR_ARGB(255,255 * (currentSelection != 0),255,255));	
	BitmapFontManager::GetInstance()->DrawString("OPTIONS",		FontID,270,250,1,1,D3DCOLOR_ARGB(255,255 * (currentSelection != 1),255,255));		
	BitmapFontManager::GetInstance()->DrawString("HOW TO PLAY",	FontID,270,300,1,1,D3DCOLOR_ARGB(255,255 * (currentSelection != 2),255,255));	
	BitmapFontManager::GetInstance()->DrawString("CREDITS",		FontID,270,350,1,1,D3DCOLOR_ARGB(255,255 * (currentSelection != 3),255,255));	
	BitmapFontManager::GetInstance()->DrawString("EXIT",		FontID,270,400,1,1,D3DCOLOR_ARGB(255,255 * (currentSelection != 4),255,255));	

}