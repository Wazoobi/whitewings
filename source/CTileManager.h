//////////////////////////////////////////////////////////////////////////
// Filename: TileManager.h
//
// Author: David Seabolt
//
// Purpose: To encapsulate all level data and interactions thereof
//////////////////////////////////////////////////////////////////////////


#ifndef CTILEMANAGER_H_
#define CTILEMANAGER_H_

//----------------------------------
// #include's
#include "CLevel.h"
#include "CCamera.h"


class CTileManager
{

	//----------------------------------------------
	//Encapsulation of TOE
	CTileManager()	{;}
	CTileManager(const CTileManager&) {;}
	CTileManager& operator=(const CTileManager&) {;}
	//----------------------------------------------



	//---------------------------------------------------------------------------------------------------------
	// Level Variables
	short m_shCurrentLevel;
	char** m_szFilenames;
	CLevel** m_pLevels;
	//----------------------------------------------------------------------------------------------------------

	//------------------------------------
	// Camera Variables
	CCamera* m_pCamera;
	CPlayer* m_pPlayer;
	//------------------------------------

	


protected:



public:

	//////////////////////////////////////////////////////////////////////////
	// Function: GetInstance
	//
	// Parameters: None
	//
	// Purpose: To return the current instance of the TileManager
	//////////////////////////////////////////////////////////////////////////

	static CTileManager* GetInstance()
	{
		static CTileManager* m_pInstance = new CTileManager();
		return m_pInstance;
	}

	//////////////////////////////////////////////////////////////////////////
	// Function: ReleaseManager
	//
	// Parameters: None
	//
	// Purpose: To clean up any memory allocated by the manager
	//////////////////////////////////////////////////////////////////////////

	void ReleaseManager();


	//////////////////////////////////////////////////////////////////////////
	// Function: GetCurrentLevel()
	//
	// Parameters: None
	//
	// Purpose: To return the current Level
	//////////////////////////////////////////////////////////////////////////

	short GetCurrentLevel() {return m_shCurrentLevel;}

	//////////////////////////////////////////////////////////////////////////
	// Function: SetCurrentLevel()
	//
	// Parameters: short level - the current level, must be <= max amount of levels
	//
	// Purpose: To set the current level being played
	//////////////////////////////////////////////////////////////////////////

	void SetCurrentLevel(short level) {m_shCurrentLevel = level;}

	//////////////////////////////////////////////////////////////////////////
	// Function: GetCurrentLevelFilePath()
	//
	// Parameters: short currentLevel - the current level being played
	//
	// Purpose: To get the current level's filepath to load from
	//////////////////////////////////////////////////////////////////////////

	char* GetCurrentLevelFilePath(short currentLevel) {return m_szFilenames[currentLevel - 1];}

	//////////////////////////////////////////////////////////////////////////
	// Function: SetCurrentLevelFilePath()
	//
	// Parameters: short currentLevel - the current level being played
	//
	// Purpose: To set the current level's filepath that the level will load from
	//////////////////////////////////////////////////////////////////////////

	void SetCurrentLevelFilePath(short currentLevel);
	
	//////////////////////////////////////////////////////////////////////////
	// Function: Update()
	//
	// Parameters: CPlayer* pPlayer - a pointer to the avatar
	//
	// Purpose: Update any level specific information
	//////////////////////////////////////////////////////////////////////////

	void Update(CPlayer* pPlayer);

	//////////////////////////////////////////////////////////////////////////
	// Function: Render()
	//
	// Parameters: None
	//
	// Purpose: To render the level
	//////////////////////////////////////////////////////////////////////////

	void Render();

	//////////////////////////////////////////////////////////////////////////
	// Function: InitManager()
	//
	// Parameters: None
	//
	// Purpose: To instantiate information pertaining to the manager
	//////////////////////////////////////////////////////////////////////////

	void InitManager();

	//////////////////////////////////////////////////////////////////////////
	// Function: CCamera* GetCamera()
	//
	// Parameters: None
	//
	// Purpose: To return the current instance of the camera
	//////////////////////////////////////////////////////////////////////////

	CCamera* GetCamera() {return m_pCamera;}

	//////////////////////////////////////////////////////////////////////////
	// Function: CheckLevelCollisions
	//
	// Parameters: CBase* pObject, CCamera* pCamera
	//
	// Purpose: To check to see if the object has collided with the level and send messages accordingly
	//////////////////////////////////////////////////////////////////////////

	void CheckLevelCollisions(CBase* pObject, CCamera* pCamera);

};

#endif