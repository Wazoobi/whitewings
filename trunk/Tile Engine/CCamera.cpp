//////////////////////////////////////////////////////////////////////////
// Filename: CCamera.cpp
//
// Author: David Seabolt
//
// Purpose: To define and implement any non inlined functions in the CCamera.h
//////////////////////////////////////////////////////////////////////////


//-------------------------------------------
// # include's
#include "CCamera.h"
#include "SGD Wrappers/CSGD_TextureManager.h"
//-------------------------------------------

//--------------------
//Forward Declarations
CLevel level;
//--------------------

//--------------------------
//Macros
#define RENDER_LAYER_TOTAL 5
//--------------------------

void CCamera::RenderLevel(CLevel::Tile*** pRenderArrays, int levelWidth, int levelHeight)
{
	//////////////////////////////////////////////////////////////////////////
	// The Basic Algorithm
	//
	// Access the level's TileMap at the current level
	//
	// Then you want to iterate through each layer starting with the layer furthest back
	//
	// During each iteration you will check what tiles are viewable by dividing the camera's position
	//		by the tile width and height
	//
	// Then you will iterate through the array at i * TILE_WIDTH, i being the camera's X position / TILE_WIDTH - 1
	//
	// Then you will iterate through the array at j * TILE_HEIGHT, j being the camera's Y position / TILE_HEIGHT - 1
	//
	// You iterate until you are at ((CamPosX/TILE_WIDTH) - 1) + ((m_nScreenWidth + TILE_WIDTH)/TILE_WIDTH) and until
	//		((CamPosY/TILE_HEIGHT) - 1) + ((m_nScreenHeight + TILE_HEIGHT) / TILE_HEIGHT)
	//////////////////////////////////////////////////////////////////////////


	//------------------------------------------------------------------------------------------------------
	// Loop Iterators
	short i;														//I init here to prevent the loops to 
	short j;														//from doing the math every loop cycle
	short XMax;														//because that would get expensive quick
	short YMax;

	//======================================================================================================
	// initialize based on the position in the world
	if(GetCameraPosX() >= 0)												//we start at n - 1 if not at the
		i		= (short)(GetCameraPosX()/TILE_WIDTH) - 1;					//beginning of the level to prevent
	else																	//"tile tearing" while rendering
		i		= 0;

	if(GetCameraPosY() >= 0)
		j		= (short)(GetCameraPosY()/TILE_HEIGHT) - 1;					//but if we are at a position at the
	else																	//beginning we can't read into data 
		j		= 0;														//that doesn't exist so adjust for it

	if(GetCameraPosX() + CGame::GetInstance()->GetScreenWidth() < levelWidth*TILE_WIDTH)
		YMax	= (short)(GetCameraPosX()/TILE_WIDTH) + (short)(CGame::GetInstance()->GetScreenWidth()/TILE_WIDTH) + 1;
	else
		YMax = levelWidth;

	if(GetCameraPosY() + CGame::GetInstance()->GetScreenHeight() < levelHeight*TILE_HEIGHT)
		XMax	= (short)(GetCameraPosY()/TILE_HEIGHT) + (short)(CGame::GetInstance()->GetScreenHeight()/TILE_HEIGHT) + 1;
	else
		XMax = levelHeight;

	//======================================================================================================
	//------------------------------------------------------------------------------------------------------


	//----------------------------------------------------------------------------------------------------------
	// The loop (triply nested... /sigh)

	RECT toDrawAt; //the rect of where we will be drawing at

	for (int curLayer = 0; curLayer < RENDER_LAYER_TOTAL; ++curLayer)
	{
		if((GetCameraPosX()/TILE_WIDTH - 1) >= 0)												
			i = (short)(GetCameraPosX()/32) - 1;					
		else																	
			i = 0;

		for ( i ; i < YMax; ++i )
		{

			if((GetCameraPosY()/TILE_HEIGHT - 1) >= 0)
				j = (short)(GetCameraPosY()/TILE_HEIGHT) - 1;					
			else																	
				j = 0;

			for ( j ; j < XMax; ++j )
			{
				if (pRenderArrays[curLayer][i][j].m_shTileImageIndex != -1)
				{
					toDrawAt.left		= (LONG)pRenderArrays[curLayer][i][j].m_shX;		//At loop time decide the
					toDrawAt.top		= (LONG)pRenderArrays[curLayer][i][j].m_shY;		//section. 
					toDrawAt.right		= (LONG)toDrawAt.left + TILE_WIDTH;					//TODO find a way to optimize
					toDrawAt.bottom		= (LONG)toDrawAt.top + TILE_HEIGHT;

					if(!pRenderArrays[curLayer][i][j].m_bIsCollideable)
						CSGD_TextureManager::GetInstance()->Draw(pRenderArrays[curLayer][i][j].m_shTileImageIndex,
							(i * TILE_WIDTH) - GetCameraPosX(), j * TILE_WIDTH - GetCameraPosY(), 1, 1, &toDrawAt);
					
				}
			}
		}
	}

	//---------------------------------------------------------------------------------------------------------

}

