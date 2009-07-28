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

	float newPosX = pPlayer->GetPosX() + pPlayer->GetVelX();// - (CGame::GetInstance()->GetScreenWidth()/3);
	float newPosY = pPlayer->GetPosY() + pPlayer->GetVelY();// - (CGame::GetInstance()->GetScreenHeight()/4);

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
	m_pLevels[0]->SetLevelImageID(CSGD_TextureManager::GetInstance()->LoadTexture("resource/graphics/colors.bmp"));

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

	SetCurrentLevel(1);
	
}

void CTileManager::CheckLevelCollisions(CBase* pObject, CCamera* pCamera)
{
	CLevel::Tile** CollisionLayer = m_pLevels[GetCurrentLevel() - 1]->GetRenderArrays()[2];
	CLevel::Tile** TriggerLayer = m_pLevels[GetCurrentLevel() - 1]->GetRenderArrays()[3];

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
				CollisionCheck.left = i * TILE_WIDTH  - m_pCamera->GetCameraPosX();
				CollisionCheck.top = j * TILE_HEIGHT - m_pCamera->GetCameraPosY();
				CollisionCheck.right = CollisionCheck.left + TILE_WIDTH;
				CollisionCheck.bottom = CollisionCheck.top + TILE_HEIGHT;

				

				if (IntersectRect(&CollisionType, &CollisionCheck, &CollisionRect))
				{

					if (CollisionType.top < CollisionRect.bottom && CollisionType.bottom > CollisionCheck.top &&
						CollisionType.bottom - CollisionType.top < CollisionType.right - CollisionType.left && 
						CollisionRect.top > CollisionCheck.top)
					{
						//-------------------------------------------------------------------------
						//If this is a case where the object has hit the bottom of the level's tile

						pObject->SetPosY(CollisionCheck.bottom);
						//pObject->SetVelY(-pObject->GetVelY());

						// TODO Implement this code
						/*if(pObject->GetObjectType() == OBJ_PLAYER);
						{
						CPlayer* pPlayer = (CPlayer*)pObject;
						pPlayer->SetIsJumping(false);
						}*/

					}
					else if(CollisionType.top < CollisionCheck.bottom && CollisionType.bottom > CollisionRect.top &&
						CollisionType.bottom - CollisionType.top < CollisionType.right - CollisionType.left)
					{
						//--------------------------------------------------------------------
						// If this is a case where the object has fallen onto the level's tile

	 						pObject->SetPosY(CollisionCheck.top - 32);
							CPlayer::GetInstance()->SetIsJumping(false);
					}
					else if(CollisionType.left < CollisionRect.right && CollisionType.right > CollisionCheck.left &&
						CollisionType.bottom - CollisionType.top > CollisionType.right - CollisionType.left)
					{
						
						//--------------------------------------------------------------------------------
						//If this is a case where the object has collided with the level's tile's right side

						pObject->SetPosX(CollisionCheck.right);
					}
					else if(CollisionType.right > CollisionRect.left && CollisionType.left < CollisionCheck.right &&
						CollisionType.bottom - CollisionType.top > CollisionType.right - CollisionType.left)
					{
						//-------------------------------------------------------------------------------
						//If this is a case where the object has collided with the level's tile's left side

						pObject->SetPosX(CollisionCheck.left);
					}
					else if(CollisionType.top < CollisionCheck.bottom && CollisionType.bottom > CollisionRect.top && //
						CollisionType.bottom - CollisionType.top == CollisionType.right - CollisionType.left && //if its a corner
						CollisionRect.top < CollisionCheck.top ) // to ensure that we are truly on the bottom
					{
						//----------------------------------------------------------------------------------
						//If this is a case of a top corner collision

						pObject->SetPosY(CollisionCheck.top - 32);
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