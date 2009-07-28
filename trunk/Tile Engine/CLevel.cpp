#include "CLevel.h"

//-------------------------------------------------------
// #include's
#include <fstream>
#include <iostream>
#include <Windows.h>

//-------------------------------------------------------
//using statements
using namespace std;

void CLevel::LoadLevel(char *filename, short levelNumber)
{
	//////////////////////////////////////////////////////////////////////////
	// Format to load a level
	//
	//	1.) Total Layers: 5(This is negligible and is only for loading it into the editor)
	//
	//	2.) Tile Width: 32(again negligible)
	//
	//	3.) Tile Height: 32(and again)
	//
	//	4.) Level Width: #(assign this to the m_shLevelWidth (THIS IS IN TILES NOT PIXELS))
	//
	//	5.) Level Height: #(same as above but to the appropriate variable
	//
	//	6.) Layer#(Access the LevelArray according to the number)
	//
	//	7.) Alright this is where it gets down to the nitty gritty
	//		if the next word is equal -1 then
	//		the tile at this index is a default tile or transparent,
	//		OTHERWISE the next one will be the X coordinate of the the tile
	//		image
	//
	//	8.) if the previous was the void string then repeat step 8 unless its the EOF
	//		OTHERWISE this will be the Y coordinate
	//	
	//	9.) Hereafter i will assume its not a void string, so this will be the collision bool
	//
	//	10.) The next one will either be a void string or it will be the X coordinate of the Trigger
	//
	//	11.) The next will be the Y coordinate of the Trigger
	//
	//	12.) The next will be an int for the size of the following string
	//
	//	13.) The next will be the string of the event
	//
	//	14.) and restart from 7 until EOF

	ifstream Reader(filename, ios::in | ios::binary);
	
	//-------------------------------------
	// Variables that will be read in
	int TotalLayers = 0;
	int TileWidth = 0;
	int TileHeight = 0;
	int LevelWidth = 0;
	int LevelHeight = 0;
	int LayerNumber = 0;
	int toDrawFromX = 0;
	int toDrawFromY = 0;
	int currentlayer = 0;
	bool isCollideable = false;
	int triggerX = 0;
	int triggerY = 0;
	int eventStringSize = 0;
	char eventChar;
	int nullInt = -1;
	//-------------------------------------




	

	//Reader.open(filename, ios::in | ios::binary);							//Read in the global information
	Reader.read((char*)&TotalLayers, sizeof(int));							//use to initialize the array
	Reader.read((char*)&TileWidth, sizeof(int));
	Reader.read((char*)&TileHeight, sizeof(int));
	Reader.read((char*)&LevelWidth, sizeof(int));
		SetLevelWidth((short)LevelWidth);
	Reader.read((char*) &LevelHeight, sizeof(int));
		SetLevelHeight(LevelHeight);


		m_LevelArrays = new Tile**[5];												//initializing the tile array
		for (int i = 0; i < 5; ++i)
		{
			m_LevelArrays[i] = new Tile*[LevelWidth];
			for (int e = 0; e < LevelWidth; ++e)
			{
				m_LevelArrays[i][e] = new Tile[LevelHeight];
			}
		}
		
		for (int i = 0; i < 5; ++i)													//For each layer
		{
			for (int j = 0; j < LevelWidth; ++j)									//For the LevelWidth
			{
				for (int k = 0; k < LevelHeight; ++k)								//For the LevelHeight
				{
					if (Reader.eof())
						break;

					Reader.read((char*)&nullInt, sizeof(int));
					if(nullInt != -1)												//if the next bit of information is a None string
					{
							toDrawFromX = nullInt;
							m_LevelArrays[i][j][k].m_shX = toDrawFromX;				//assign it
						Reader.read((char*)&toDrawFromY, sizeof(int));				//read in the drawY
							m_LevelArrays[i][j][k].m_shY = toDrawFromY;				//assign it
						Reader.read((char*)&isCollideable, sizeof(bool));			//read in the collision bool
							m_LevelArrays[i][j][k].m_bIsCollideable = isCollideable;
						Reader.read((char*)&nullInt, sizeof(int));
						if( nullInt != -1)											//if there is no trigger
						{
							triggerX = nullInt;										//read in the Trigger's X
							Reader.read((char*)&triggerY, sizeof(int));				//read in the Trigger's Y
							Reader.read((char*)&eventStringSize, sizeof(int));		//read in the Trigger's string's stream size
								if(GetTotalTriggers() == 0)							//if this is the first event
								{
									m_TriggerArray = new Trigger[1];				//create a new array

									m_TriggerArray[GetTotalTriggers()].m_X = triggerX; //the X 
									m_TriggerArray[GetTotalTriggers()].m_Y = triggerY; //the Y
									m_TriggerArray[GetTotalTriggers()].m_szEventString = new char[eventStringSize - 1];
									for(int e = 0; e < eventStringSize; ++e)
									{
										Reader.read((char*)&eventChar, sizeof(char));							//read in the event string
										m_TriggerArray[GetTotalTriggers()].m_szEventString[e] = eventChar; 
									}
									m_TriggerArray[GetTotalTriggers()].m_szEventString[eventStringSize] = 0;																			//the string

									SetTotalTriggers(GetTotalTriggers() + 1);									//Update the trigger count
								}
								else
								{
									//Create a new trigger array of a new size
									Trigger *temp = new Trigger[GetTotalTriggers()];
									for(int o = 0; o < m_shTotalTriggers; ++o)
										temp[o] = m_TriggerArray[o];
									m_TriggerArray = new Trigger[(int)m_shTotalTriggers + 1];
									for (int o = 0; o < m_shTotalTriggers; ++o)
										m_TriggerArray[o] = temp[o];

									//assign the data
									m_TriggerArray[(int)m_shTotalTriggers].m_X = toDrawFromX;
									m_TriggerArray[(int)m_shTotalTriggers].m_Y = toDrawFromY;
									for(int e = 0; e < eventStringSize - 1; ++e)
									{
										Reader.read((char*)&eventChar, sizeof(char));							//read in the event string
										m_TriggerArray[GetTotalTriggers()].m_szEventString[e] = eventChar; 
									}

									delete temp;
									//update the trigger data
									SetTotalTriggers(m_shTotalTriggers+ 1);
								}
						}
						//else
							//Reader.read((char*)&nullInt, sizeof(int));					//There is no Trigger =/							
					}
					else
					{
						//Reader.read((char*)&nullInt, sizeof(int));
						m_LevelArrays[i][j][k].m_shX = 10000;
						m_LevelArrays[i][j][k].m_shY = 10000;
						m_LevelArrays[i][j][k].m_shTileImageIndex = -1;					//There is no tile =/
					}
				}
			}
		}
		




}

CLevel::Tile*** CLevel::GetRenderArrays()
{
	
	//CLevel::Tile*** RenderArrays = new Tile**[3];
	//RenderArrays[0] = m_LevelArrays[0];
	//RenderArrays[1] = m_LevelArrays[1];
	//RenderArrays[2] = m_LevelArrays[4];
	return m_LevelArrays;
	
}

void CLevel::ReleaseLevel()
{
	//TODO Clean up Triggers/their event strings
	//TODO Clean up Tiles
	for(int h = 0; h < 5; ++h)
	{
		for (int i = 0; i < GetLevelWidth(); ++i)
		{
			for (int j = 0; j < GetLevelHeight(); ++j)
			{
				delete &m_LevelArrays[h][i][j];
			}
			delete m_LevelArrays[h][i];
		}
		delete m_LevelArrays[h];
	}

	for (int i = 0; i < m_shTotalTriggers; ++i)
	{
		delete m_TriggerArray[i].m_szEventString;
		delete &m_TriggerArray[i];
	}
}