//////////////////////////////////////////////////////////////////////////
//	File Name	:	"COptionsState.cpp"
//
//	Author		:	Juno Madden (JM)
//
//	Purpose		:	To encapsulate all code for the options menu.
//////////////////////////////////////////////////////////////////////////

#include "COptionsState.h"
#include "CMainMenuState.h"

COptionsState::COptionsState(void)
{
	// Get pointers to the SGD singletons
	m_pD3D = CSGD_Direct3D::GetInstance();
	m_pTM = CSGD_TextureManager::GetInstance();
	m_pDS = CSGD_DirectSound::GetInstance();
	m_pWM = CSGD_WaveManager::GetInstance();
	m_pDI = CSGD_DirectInput::GetInstance();
	currentSelection = 0;

	m_nBackgroundID = 0;

	pGame = CGame::GetInstance();

	SetStateType(OPTIONS);
}

COptionsState::~COptionsState(void)
{

}

COptionsState* COptionsState::GetInstance(void)
{
	// Lazy Instantiation
	static COptionsState instance;
	return &instance;
}

void COptionsState::Enter(void)
{
	// Load common resources used by the game
	m_nImageID = m_pTM->LoadTexture("resource/graphics/JuM_SGD_MenuCursor.png");
	
	//TODO: Change Background
	//m_nBackgroundID = m_pTM->LoadTexture("resource/graphics/JuM_MissileCommand_BasicBackground.bmp");
	m_nSoundID1 = m_pWM->LoadWave("resource/sound/JuM_SGD_TankShot.wav");
	m_nSoundID2 = m_pWM->LoadWave("resource/sound/JuM_SGD_BGM.wav");

	m_pWM->SetVolume(m_nSoundID2,pGame->GetBGMVolume());
	m_pWM->SetPan(m_nSoundID2,pGame->GetRightPan() * 2 - 100);
	m_pWM->Play(m_nSoundID2, DSBPLAY_LOOPING);
}

void COptionsState::Exit(void)
{
	m_pWM->Stop(m_nSoundID2);
	m_pWM->Stop(m_nSoundID1);
	m_pWM->UnloadWave(m_nSoundID2);
	m_pWM->UnloadWave(m_nSoundID1);

	m_pTM->UnloadTexture(m_nImageID);
	//m_pTM->UnloadTexture(m_nBackgroundID);
}

// split up Execute() into the 3 main steps of a game
bool COptionsState::Input(void)
{
	if(m_pDI->KeyPressed(DIK_UP) || CSGD_DirectInput::GetInstance()->JoystickGetLStickDirPressed(DIR_UP,0))
	{
		if(currentSelection == 0)
			currentSelection = 3;
		else
			currentSelection--;
	}

	if(m_pDI->KeyPressed(DIK_DOWN) || CSGD_DirectInput::GetInstance()->JoystickGetLStickDirPressed(DIR_DOWN,0))
	{
		if(currentSelection == 3)
			currentSelection = 0;
		else
			currentSelection++;
	}

	if(m_pDI->KeyDown(DIK_LEFT) || CSGD_DirectInput::GetInstance()->JoystickGetLStickDirDown(DIR_LEFT,0))
	{

		switch (currentSelection)
		{
		case 0:
			if (pGame->GetSFXVolume() > 0)
			{
				pGame->SetSFXVolume(pGame->GetSFXVolume() - 1);
				m_pWM->SetVolume(m_nSoundID1,pGame->GetSFXVolume());
				m_pWM->Play(m_nSoundID1);
			}
			break;
		case 1:
			if (pGame->GetBGMVolume() > 0)
			{
				pGame->SetBGMVolume(pGame->GetBGMVolume() - 1);
				m_pWM->SetVolume(m_nSoundID2,pGame->GetBGMVolume());
			}
			break;
		case 2:
			if(pGame->GetLeftPan() < 100)
			{
				pGame->SetLeftPan(pGame->GetLeftPan() + 1);
				pGame->SetRightPan(pGame->GetRightPan() - 1);
				m_pWM->SetPan(m_nSoundID1,pGame->GetRightPan() * 2 - 100);
				m_pWM->SetPan(m_nSoundID2,pGame->GetRightPan() * 2 - 100);

			}
			break;
		}
	}

	if(m_pDI->KeyDown(DIK_RIGHT) || CSGD_DirectInput::GetInstance()->JoystickGetLStickDirDown(DIR_RIGHT,0))
	{
		switch (currentSelection)
		{
		case 0:
			if (pGame->GetSFXVolume() < 100)
			{
				pGame->SetSFXVolume(pGame->GetSFXVolume() + 1);
				m_pWM->SetVolume(m_nSoundID1,pGame->GetSFXVolume());
				m_pWM->Play(m_nSoundID1);

			}
			break;
		case 1:
			if (pGame->GetBGMVolume() < 100)
			{
				pGame->SetBGMVolume(pGame->GetBGMVolume() + 1);
				m_pWM->SetVolume(m_nSoundID2,pGame->GetBGMVolume());

			}
			break;
		case 2:
			if(pGame->GetLeftPan() > 0)
			{
				pGame->SetLeftPan(pGame->GetLeftPan() - 1);
				pGame->SetRightPan(pGame->GetRightPan() + 1);
				m_pWM->SetPan(m_nSoundID1,pGame->GetRightPan() * 2 - 100);
				m_pWM->SetPan(m_nSoundID2,pGame->GetRightPan() * 2 - 100);
			}
			break;
		}



	}

	if(m_pDI->KeyPressed(DIK_RETURN) || CSGD_DirectInput::GetInstance()->JoystickButtonPressed(DIR_A,0))
	{
		if (currentSelection == 3)
		{
			pGame->PopState();
			pGame->PushState(CMainMenuState::GetInstance());
		}

	}

	return true;
}

void COptionsState::Update(float fElapsedTime)
{

}

void COptionsState::Render(void)
{
	//TODO: Change Background
	//m_pTM->Draw(m_nBackgroundID,0, 0, 1, 1, 0, 0, 0, 0, D3DCOLOR_ARGB(255, 0, 0, 0));

	m_pTM->Draw(m_nImageID, 30, 200 + currentSelection * 35);
	CFontManager::GetInstance()->Draw("Options Menu:", 75, 100);
	
	char buffer[256];
	sprintf_s(buffer,256,"Change SFX Volume   <%i>",pGame->GetSFXVolume());
	CFontManager::GetInstance()->Draw(buffer, 80, 200, 0.5f, 0.5f);
	
	sprintf_s(buffer,256,"Change Music Volume <%i>",pGame->GetBGMVolume());
	CFontManager::GetInstance()->Draw(buffer, 80, 235, 0.5f, 0.5f);

	sprintf_s(buffer,256,"Music Pan L-R       L<%i> - R<%i>",pGame->GetLeftPan(), pGame->GetRightPan());
	CFontManager::GetInstance()->Draw(buffer, 80, 270, 0.5f, 0.5f);

	CFontManager::GetInstance()->Draw("Back", 80, 305, 0.5f, 0.5f);
}