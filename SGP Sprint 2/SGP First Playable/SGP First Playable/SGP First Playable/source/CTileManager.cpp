//////////////////////////////////////////////////////////////////////////
// Filename: CTileManager.cpp
//
// Author: David Seabolt
//
// Purpose: To define any functions declared in the CTileManager.h
//////////////////////////////////////////////////////////////////////////

//-------------------------------------
// #include's
#include "CCamera.h"
#include "CLevel.h"
#include "SGD Wrappers/CSGD_TextureManager.h"
#include "SGD Wrappers/CSGD_DirectInput.h"
#include "SGD Wrappers/CSGD_Direct3D.h"
#include "CEvent.h"
#include "CSGD_EventSystem.h"
#include "CFlyer.h"
#include "CWalker.h"
#include "CMessageManager.h"
#include "CObjectManager.h"



void CTileManager::Update(CPlayer* pPlayer)
{

#if 0
	//CSGD_DirectInput* m_pDI = CSGD_DirectInput::GetInstance();
	//if (m_pDI->KeyDown(DIK_LEFT))
	//{
	//	//if the camera isn't past the start of the level
	//	if (m_pCamera->GetCameraPosX() - 1 >= 0)
	//		m_pCamera->SetCameraPosX(m_pCamera->GetCameraPosX() -1 );
	//	else
	//		m_pCamera->SetCameraPosX(0);
	//}

	//if (m_pDI->KeyDown(DIK_RIGHT))
	//{
	//	//if the camera isn't past the end of the level
	//	if ( ((m_pCamera->GetCameraPosX() + CGame::GetInstance()->GetScreenWidth()) + 1) < (m_pLevels[GetCurrentLevel() - 1]->GetLevelWidth()*TILE_WIDTH) )
	//		m_pCamera->SetCameraPosX(m_pCamera->GetCameraPosX() + 1);
	//	else
	//		m_pCamera->SetCameraPosX((m_pLevels[GetCurrentLevel() - 1]->GetLevelWidth()*TILE_WIDTH) - CGame::GetInstance()->GetScreenWidth() - TILE_WIDTH);
	//}

	//if (m_pDI->KeyDown(DIK_UP))
	//{
	//	//if the camera isn't at the top of the level
	//	if (m_pCamera->GetCameraPosY() - 1 >= 0)
	//		m_pCamera->SetCameraPosY(m_pCamera->GetCameraPosY() - 1);
	//	else
	//		m_pCamera->SetCameraPosY(0);
	//}

	//if (m_pDI->KeyDown(DIK_DOWN))
	//{
	//	//if the camera isn't at the bottom of the level
	//	if (  ((m_pCamera->GetCameraPosY() + CGame::GetInstance()->GetScreenHeight()) + 1) < (m_pLevels[GetCurrentLevel() - 1]->GetLevelHeight()*TILE_HEIGHT) )
	//		m_pCamera->SetCameraPosY(m_pCamera->GetCameraPosY() + 1);
	//	else
	//		m_pCamera->SetCameraPosY((m_pLevels[GetCurrentLevel() - 1]->GetLevelHeight()*TILE_HEIGHT) - CGame::GetInstance()->GetScreenHeight() - TILE_HEIGHT);
	//}

	//if the camera isn't past the start of the level

#endif

	//-------------------------------------------------------------------------------------------------------------------------------------
	// Camera Updates

	float newPosX = (pPlayer->GetPosX() ) - (CGame::GetInstance()->GetScreenWidth()/2);
	float newPosY = (pPlayer->GetPosY() ) - (CGame::GetInstance()->GetScreenHeight())/2;

	//XCameraPos Possibilities
	if (newPosX >= 0 && newPosX + CGame::GetInstance()->GetScreenWidth() < (m_pLevels[GetCurrentLevel() -1]->GetLevelWidth()*TILE_WIDTH))
		m_pCamera->SetCameraPosX(newPosX);
	else if(newPosX < 0)
		m_pCamera->SetCameraPosX(0);
	else
		m_pCamera->SetCameraPosX((m_pLevels[GetCurrentLevel() - 1]->GetLevelWidth()*TILE_WIDTH) - CGame::GetInstance()->GetScreenWidth());

	//YCameraPos Possibilities
	if(newPosY >= 0 && newPosY + CGame::GetInstance()->GetScreenHeight() < (m_pLevels[GetCurrentLevel() - 1]->GetLevelHeight()*TILE_HEIGHT))

		m_pCamera->SetCameraPosY(newPosY);
	else if(newPosY < 0)
		m_pCamera->SetCameraPosY(0);
	else
		m_pCamera->SetCameraPosY((m_pLevels[GetCurrentLevel() - 1]->GetLevelHeight()*TILE_HEIGHT) - CGame::GetInstance()->GetScreenHeight());

	//--------------------------------------------------------------------------------------------------------------------------------------



}

void CTileManager::Render()
{
	m_pCamera->RenderLevel(m_pLevels[GetCurrentLevel() - 1]->GetRenderArrays(), m_pLevels[GetCurrentLevel() - 1]->GetLevelWidth(),
		m_pLevels[GetCurrentLevel() - 1]->GetLevelHeight());

	for (int i = 0; i < 3; i++)
	{
		if (m_pSpawnPoints[i].m_fX > m_pCamera->GetCameraPosX() && 
			m_pSpawnPoints[i].m_fX < m_pCamera->GetCameraPosX() + CGame::GetInstance()->GetScreenWidth() && 
			m_pSpawnPoints[i].m_fY > m_pCamera->GetCameraPosY() && 
			m_pSpawnPoints[i].m_fY < m_pCamera->GetCameraPosY() + CGame::GetInstance()->GetScreenHeight() &&
			m_pSpawnPoints[i].m_bIsActive)
		{
			//CMessageManager::GetInstance()->SendMsg(new CCreateStunShotMessage(this));

			m_pSpawnPoints[i].m_eEnemyToSpawn->SetVelY(100);

			CObjectManager::GetInstance()->AddObject(m_pSpawnPoints[i].m_eEnemyToSpawn);
			m_pSpawnPoints[i].m_bIsActive = false;
		}
	}
}

void CTileManager::InitManager()
{
	m_pCamera = new CCamera();
	m_pLevels = new CLevel*[5];
	for (int i = 0; i < 5; ++i)
	{
		m_pLevels[i] = new CLevel();
	}

	m_pLevels[0]->LoadLevel("resource/data/level.bin", 1);
	m_pLevels[0]->SetLevelImageID(CSGD_TextureManager::GetInstance()->LoadTexture("resource/graphics/DaS_TestTileSet.bmp"));

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < m_pLevels[0]->GetLevelWidth(); ++j)
		{
			for (int k = 0; k < m_pLevels[0]->GetLevelHeight(); ++k)
			{
				if(m_pLevels[0]->GetRenderArrays()[i][j][k].m_shX < 10000)
				{
					m_pLevels[0]->GetRenderArrays()[i][j][k].m_shTileImageIndex = m_pLevels[0]->GetLevelImageID();
				}
			}
		}
	}

	m_pSpawnPoints = new SpawnPoint[3];

	CWalker* pWalker = new CWalker();
	m_pSpawnPoints[0].m_fX = 150;
	m_pSpawnPoints[0].m_fY = 300;
	m_pSpawnPoints[0].m_eEnemyToSpawn = (CEnemy*)pWalker;
	m_pSpawnPoints[0].m_bIsActive = true;

	CFlyer* pFlyer = new CFlyer();
	m_pSpawnPoints[1].m_fX = 500;
	m_pSpawnPoints[1].m_fY = 800;
	m_pSpawnPoints[1].m_eEnemyToSpawn = (CEnemy*)pFlyer;
	m_pSpawnPoints[1].m_bIsActive = true;

	CWalker* pWalkers = new CWalker();
	m_pSpawnPoints[2].m_fX = 800;
	m_pSpawnPoints[2].m_fY = 800;
	m_pSpawnPoints[2].m_eEnemyToSpawn = (CEnemy*)pWalkers;
	m_pSpawnPoints[2].m_bIsActive = true;

	SetCurrentLevel(1);

}

void CTileManager::CheckLevelCollisions(CBase* pObject, CCamera* pCamera)
{
	CLevel::Tile** CollisionLayer = m_pLevels[GetCurrentLevel() - 1]->GetRenderArrays()[2];
	//CLevel::Tile** TriggerLayer = m_pLevels[GetCurrentLevel() - 1]->GetRenderArrays()[3];

	RECT CollisionRect = pObject->GetRect();										//The objects collision RECT
	RECT CollisionType = {0,0,0,0};													//The RECT that will result from the collision check
	RECT CollisionCheck = {0,0,0,0};												//The RECT to be drawn at the location in the tile array
	RECT TriggerCheck = {0,0,0,0};													//The RECT to check for triggers with

	for (int i = (int)((pCamera->GetCameraPosX()/TILE_WIDTH)); i < ((pCamera->GetCameraPosX()/TILE_WIDTH)) + (CGame::GetInstance()->GetScreenWidth()/TILE_WIDTH); ++i)
	{
		for (int j = (int)((pCamera->GetCameraPosY()/TILE_HEIGHT)); j < ((pCamera->GetCameraPosY()/TILE_HEIGHT)) + (CGame::GetInstance()->GetScreenHeight()/TILE_HEIGHT); ++j)
		{
			for(int h = 0; h < m_pLevels[GetCurrentLevel() - 1]->GetTotalTriggers(); ++h)
				if(i * TILE_WIDTH == m_pLevels[GetCurrentLevel() - 1]->GetTriggers()[h].m_X
					&& j * TILE_HEIGHT == m_pLevels[GetCurrentLevel() - 1]->GetTriggers()[h].m_Y)
				{
					TriggerCheck.left = i * TILE_WIDTH  - m_pCamera->GetCameraPosX();
					TriggerCheck.top = j * TILE_HEIGHT - m_pCamera->GetCameraPosY();
					TriggerCheck.right = TriggerCheck.left + TILE_WIDTH;
					TriggerCheck.bottom = TriggerCheck.top + TILE_HEIGHT;

					if(IntersectRect(&CollisionType, &TriggerCheck, &CollisionRect))
						CSGD_EventSystem::GetInstance()->SendEvent(m_pLevels[GetCurrentLevel() - 1]->GetTriggers()[h].m_szEventString, (void*) pObject);

				}

				if (CollisionLayer[i][j].m_bIsCollideable)
				{
					if(pObject->GetObjectType() == 4)//Player
					{
						CollisionCheck.left = i * TILE_WIDTH;// - m_pCamera->GetCameraPosX();
						CollisionCheck.top = j * TILE_HEIGHT;// - m_pCamera->GetCameraPosY();
						CollisionCheck.right = CollisionCheck.left + TILE_WIDTH;
						CollisionCheck.bottom = CollisionCheck.top + TILE_HEIGHT;
					}
					else
					{
						CollisionCheck.left = i * TILE_WIDTH;// - m_pCamera->GetCameraPosX();
						CollisionCheck.top = j * TILE_HEIGHT;// - m_pCamera->GetCameraPosY();
						CollisionCheck.right = CollisionCheck.left + TILE_WIDTH;
						CollisionCheck.bottom = CollisionCheck.top + TILE_HEIGHT;

					}


					if (IntersectRect(&CollisionType, &CollisionCheck, &CollisionRect))
					{

						if (CollisionType.top < CollisionRect.bottom && CollisionType.bottom > CollisionCheck.top &&
							CollisionType.bottom - CollisionType.top < CollisionType.right - CollisionType.left && 
							CollisionRect.top > CollisionCheck.top)
						{
							//-------------------------------------------------------------------------
							//If this is a case where the object has hit the bottom of the level's tile

							pObject->SetPosY(CollisionCheck.bottom);
							
						}
						else if(CollisionType.top < CollisionCheck.bottom && CollisionType.bottom > CollisionRect.top &&
							CollisionType.bottom - CollisionType.top < CollisionType.right - CollisionType.left)
						{
							//--------------------------------------------------------------------
							// If this is a case where the object has fallen onto the level's tile

							pObject->SetPosY(CollisionCheck.top - TILE_HEIGHT);
							if(pObject->GetObjectType() == 1) //if its an enemy
							{
								pObject->SetPosY(CollisionCheck.top - TILE_HEIGHT - 16);
							}
								pObject->SetVelY(0);

							if(pObject->GetObjectType() == 4) // if this is a player class
								CPlayer::GetInstance()->SetIsJumping(false);

						}
						else if(CollisionType.left < CollisionRect.right && CollisionType.right > CollisionCheck.left &&
							CollisionType.bottom - CollisionType.top > CollisionType.right - CollisionType.left &&
							CollisionRect.left < CollisionCheck.left)
						{

							//--------------------------------------------------------------------------------
							//If this is a case where the object has collided with the level's tile's left side

							pObject->SetPosX(CollisionCheck.left - TILE_WIDTH - 16);
							if(pObject->GetObjectType() == 1)
							{
								pObject->SetPosX(CollisionCheck.left - TILE_WIDTH - 16);
								pObject->SetVelX(pObject->GetVelX() * -1);
							}

						}
						else if(CollisionType.right > CollisionRect.left && CollisionType.left < CollisionCheck.right &&
							CollisionType.bottom - CollisionType.top > CollisionType.right - CollisionType.left)
						{
							//-------------------------------------------------------------------------------
							//If this is a case where the object has collided with the level's tile's right side

							pObject->SetPosX(CollisionCheck.right);
							if(pObject->GetObjectType() == 1)
							{
								pObject->SetPosX(CollisionCheck.right);
								pObject->SetVelX(pObject->GetVelX() * -1);
							}
						}
						else if(CollisionType.top < CollisionCheck.bottom && CollisionType.bottom > CollisionRect.top && //
							CollisionType.bottom - CollisionType.top == CollisionType.right - CollisionType.left && //if its a corner
							CollisionRect.top < CollisionCheck.top ) // to ensure that we are truly on the bottom
						{
							//----------------------------------------------------------------------------------
							//If this is a case of a top corner collision

							pObject->SetPosY(CollisionCheck.top - 32 - 16);
							pObject->SetVelY(0);
							if(pObject->GetObjectType() == 4)//if we have a player
							{
								CPlayer* pPlayer = (CPlayer*)pObject;
								pPlayer->SetIsJumping(false);
							}

						}
						else if(CollisionType.top < CollisionRect.bottom && CollisionType.bottom > CollisionCheck.top &&
							CollisionType.bottom - CollisionType.top == CollisionType.right - CollisionType.left)
						{
							//----------------------------------------------------------------------------------
							//If this is a case of a bottom corner collision

							pObject->SetPosY(CollisionCheck.bottom);
							//pObject->SetVelY(-pObject->GetVelY() );
						}						

					}
				}	
		}
	}


}

void CTileManager::ReleaseManager()
{
	delete m_pCamera;
	for (int i = 0; i < 5; ++i)
	{
		delete m_pLevels[i];
	}
}