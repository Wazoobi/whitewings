//////////////////////////////////////////////////////////////////////////
// Filename: CCamera.h
//
// Author: David Seabolt
//
// Purpose: To encapsulate and properly cull and display a level
//////////////////////////////////////////////////////////////////////////

//----------------------------------
//#include's
#include "CTileManager.h"
#include "CLevel.h"
#include "CPlayer.h"
#include "CGame.h"

#ifndef CCAMERA_H_ 
#define CCAMERA_H_

//---------------------------------
// Macros

#define TILE_WIDTH 32
#define TILE_HEIGHT 32


class CCamera
{
	//-------------------
	// Player information
	CPlayer* m_pPlayer;
	//-------------------

	//---------------------------------------
	// Variables for storing current position
	float m_fXPos;
	float m_fYPos;
	//----------------------------------------
	
public:

	//////////////////////////////////////////////////////////////////////////
	// Function: CPlayer* GetPlayer()
	//
	// Parameters: None
	//
	// Purpose: To return the current pointer to the Player
	//////////////////////////////////////////////////////////////////////////

	CPlayer* GetPlayer() {return m_pPlayer;}

	//////////////////////////////////////////////////////////////////////////
	// Function: SetPlayer(CPlayer* pPlayer)
	//
	// Parameters: CPlayer* pPlayer - the current player pointer
	//
	// Purpose: To set the pointer to the player
	//////////////////////////////////////////////////////////////////////////

	void SetPlayer(CPlayer* pPlayer) {m_pPlayer = pPlayer;}

	//////////////////////////////////////////////////////////////////////////
	// Function: float GetCameraPosX()
	//
	// Parameters: None
	//
	// Purpose: To return the camera's current position
	//////////////////////////////////////////////////////////////////////////

	float GetCameraPosX() {return m_fXPos;}

	//////////////////////////////////////////////////////////////////////////
	// Function: SetCameraPosX()
	//
	// Parameters: float X - the new X position for the camera
	//
	// Purpose: To set the current X position of the camera
	//////////////////////////////////////////////////////////////////////////

	void SetCameraPosX(float X) {m_fXPos = X;}

	//////////////////////////////////////////////////////////////////////////
	// Function: float GetCameraPosY()
	//
	// Parameters: None
	//
	// Purpose: To return the camera's current Y position
	//////////////////////////////////////////////////////////////////////////

	float GetCameraPosY() {return m_fYPos;}

	//////////////////////////////////////////////////////////////////////////
	// Function: SetCameraPosY()
	//
	// Parameters: float Y - the new camera Y position
	//
	// Purpose: To set the camera's current Y position
	//////////////////////////////////////////////////////////////////////////

	void SetCameraPosY(float Y) {m_fYPos = Y;}

	//////////////////////////////////////////////////////////////////////////
	// Function: RenderLevel(CLevel* pLevel)
	//
	// Parameters: CLevel* pLevel - the current level we are on
	//			   int levelWidth - the current level's width
	//			   int levelHeight - the current level's height
	//
	// Purpose: to cull and render the current tiles on screen
	//////////////////////////////////////////////////////////////////////////

	void RenderLevel(CLevel::Tile*** pRenderArrays, int levelWidth, int levelHeight);

	//////////////////////////////////////////////////////////////////////////
	// Function: ReleaseCamera()
	//
	// Parameters: None
	//
	// Purpose: To release any memory allocated by this instance
	//////////////////////////////////////////////////////////////////////////

	void ReleaseCamera();

	
};

#endif