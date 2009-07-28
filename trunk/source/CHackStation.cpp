////////////////////////////////////////////////////////////////////////
//	File Name	:	"CBase.cpp"
//
//	Author		:	Juno Madden (JM)
//
//	Purpose		:	To contain all the shared data and functionaly of 
//					our game objects.
////////////////////////////////////////////////////////////////////////

#include "CHackStation.h"

#include "SGD Wrappers/CSGD_TextureManager.h"

CHackStation::CHackStation(void)
{
	m_nImageID = CSGD_TextureManager::GetInstance()->LoadTexture("resource/graphics/HackTerminal.bmp");

	m_uiHackType = DOOR;

	m_nDisplayDepth = 1;	// Z-sorting
	m_uiRefCount = 1;		// Always start with a reference to yourself
	m_uiType = OBJ_HACKSTATION;
	SetPosX(0.0f);
	SetPosY(0.0f);
	SetVelX(0.0f);
	SetVelY(0.0f);

	m_nTerminalSignature = 0;
}

CHackStation::~CHackStation(void)
{

}

void CHackStation::Update(float fElapsedTime)
{
	// Using the elapsed time
}

void CHackStation::Render(void)
{
	// TODO:	Render the current frames image
	CSGD_TextureManager::GetInstance()->Draw(m_nImageID, GetPosX(), GetPosY());
}

bool CHackStation::CheckCollision(CBase* pBase)
{
	// TODO:	Use the current frame of the animation instance to grab the collision rect and 
	//			compare it to the collision rect of the passed in CBase pointer's animation instance's 
	//			current frame's collision rect.
	return false;
}