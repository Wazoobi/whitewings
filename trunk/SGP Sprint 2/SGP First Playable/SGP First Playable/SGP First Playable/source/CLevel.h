//////////////////////////////////////////////////////////////////////////
// Filename: CLevel
//
// Author: David Seabolt
//
// Purpose: To encapsulate all data pertaining to the level
//////////////////////////////////////////////////////////////////////////

#ifndef CLEVEL_H_
#define CLEVEL_H_

//---------------
//#include's 
#include "CGame.h"
#include "CBase.h"



class CLevel
{

public:
	//////////////////////////////////////////////////////////////////////////
	// Structure: Tile
	//
	// Members:
	//			-bool m_bIsCollideable - checks to see if the Tile is Collideable
	//			-short m_shTileImageIndex - the "index" in the image to draw from
	//
	// Purpose: A quick structure to decide what to draw
	//////////////////////////////////////////////////////////////////////////

	struct Tile
	{
		Tile()
		{
			m_bIsCollideable = false;
			m_shTileImageIndex = 0;
			m_shX = 0;
			m_shY = 0;
		}

		bool m_bIsCollideable;
		short m_shX;
		short m_shY;
		short m_shTileImageIndex;
	};

	//////////////////////////////////////////////////////////////////////////
	// Structure: Trigger
	//
	// Members:
	//
	// Purpose: A structure to encapsulate the Trigger Tile Data
	//////////////////////////////////////////////////////////////////////////

	struct Trigger
	{
		short m_X;
		short m_Y;
		char* m_szEventString;
	};

private:

	//------------------
	// Level Sizes
	short m_shLvlWidth;
	short m_shLvlHeight;
	//------------------
	
	//----------------------
	// Tile Arrays for Level
	Tile*** m_LevelArrays;
	//----------------------

	//----------------------
	// Trigger Arrays
	Trigger* m_TriggerArray;
	short m_shTotalTriggers;
	//----------------------

	//---------------------
	// Image ID for TileSet
	short m_shTileSetID;
	//---------------------

public:
	
	//////////////////////////////////////////////////////////////////////////
	// Function: LoadLevel(char* filename, short levelNumber)
	//
	// Parameters: char* filename - The file that we are loading from (MUST BE A BINARY FILE)
	//			   short levelNumber - The number of the level
	//
	// Purpose: To load in a binary file and store it in a Tile Array to render and interact with later
	//////////////////////////////////////////////////////////////////////////

	void LoadLevel(char* filename, short levelNumber);

	//////////////////////////////////////////////////////////////////////////
	// Function: short GetLevelWidth()
	//
	// Parameters: None 
	//
	// Purpose: To return the current width of the level
	//
	// Note: This will return the level size in TILES not PIXELS
	//////////////////////////////////////////////////////////////////////////

	short GetLevelWidth() {return m_shLvlWidth;}

	//////////////////////////////////////////////////////////////////////////
	// Function SetLevelWidth(short LevelWidth)
	//
	// Parameters: short LevelWidth - the level's new width in TILES not PIXELS
	//
	// Purpose: To set the new width of the level
	//////////////////////////////////////////////////////////////////////////

	void SetLevelWidth(short levelWidth) {m_shLvlWidth = levelWidth;}

	//////////////////////////////////////////////////////////////////////////
	// Function: short GetLevelHeight()
	//
	// Parameters: None
	//
	// Purpose: To get the height of the level
	//
	// NOTE: THIS RETURNS WIDTH IN TILES NOT PIXELS
	//////////////////////////////////////////////////////////////////////////

	short GetLevelHeight() {return m_shLvlHeight;}

	//////////////////////////////////////////////////////////////////////////
	// Function: SetLevelHeight(short levelHeight)
	//
	// Parameters: short levelHeight - the new height of the level IN TILES NOT PIXELS
	//
	// Purpose: To set the the new height of the level
	//////////////////////////////////////////////////////////////////////////

	void SetLevelHeight(short levelHeight) {m_shLvlHeight = levelHeight;}

	//////////////////////////////////////////////////////////////////////////
	// Function: short GetTotalTriggers()
	//
	// Parameters: None
	//
	// Purpose: To get the total number of Triggers in this level
	//////////////////////////////////////////////////////////////////////////

	short GetTotalTriggers() {return m_shTotalTriggers;}

	//////////////////////////////////////////////////////////////////////////
	// Function: SetTotalTriggers( short TotalTriggers)
	//
	// Parameters: short TotalTriggers
	//
	// Purpose: To set the total number of Triggers
	//////////////////////////////////////////////////////////////////////////

	void SetTotalTriggers(short TotalTriggers) {m_shTotalTriggers = TotalTriggers;}

	//////////////////////////////////////////////////////////////////////////
	// Function: Tile*** GetRenderArrays()
	//
	// Parameters: None
	//
	// Purpose: To return the level's Tile arrays the have rendered tiles
	//////////////////////////////////////////////////////////////////////////

	Tile*** GetRenderArrays();
	

	//////////////////////////////////////////////////////////////////////////
	// Function: short GetLevelImageID()
	//
	// Parameters: None
	//
	// Purpose: To return the Image ID of this level's tileset
	//////////////////////////////////////////////////////////////////////////

	short GetLevelImageID() {return m_shTileSetID;}

	//////////////////////////////////////////////////////////////////////////
	// Function: SetLevelImageID()
	//
	// Parameters: None
	//
	// Purpose: To set the Image ID of this level's tileset
	//////////////////////////////////////////////////////////////////////////

	void SetLevelImageID(short ID) {m_shTileSetID = ID;}

	//////////////////////////////////////////////////////////////////////////
	// Function: ReleaseLevel()
	//
	// Parameters: None
	//
	// Purpose: To release any memory used by this instance
	//////////////////////////////////////////////////////////////////////////

	void ReleaseLevel();

	//////////////////////////////////////////////////////////////////////////
	// Function: Trigger* GetTriggers()
	//
	// Parameters: None
	//
	// Purpose: To return the current levels trigger array
	//////////////////////////////////////////////////////////////////////////

	Trigger* GetTriggers() {return m_TriggerArray;}
};

#endif