////////////////////////////////////////////////////////////////////////
//	File Name	:	"CBase.cpp"
//
//	Author		:	Juno Madden (JM)
//
//	Purpose		:	To contain all the shared data and functionaly of 
//					our game objects.
////////////////////////////////////////////////////////////////////////

#include "CHackOrb.h"

#include "SGD Wrappers/CSGD_TextureManager.h"

CHackOrb::CHackOrb(void)
{
	m_nDisplayDepth = 1;	// Z-sorting
	m_uiRefCount = 1;		// Always start with a reference to yourself
	m_uiType = OBJ_HACKORB;
	SetPosX(0.0f);
	SetPosY(0.0f);
	SetVelX(0.0f);
	SetVelY(0.0f);
}

CHackOrb::~CHackOrb(void)
{

}

void CHackOrb::Update(float fElapsedTime)
{
	// Using the elapsed time
}

void CHackOrb::Render(void)
{
	// TODO:	Render the current frames image
}

bool CHackOrb::CheckCollision(CBase* pBase)
{
	// TODO:	Use the current frame of the animation instance to grab the collision rect and 
	//			compare it to the collision rect of the passed in CBase pointer's animation instance's 
	//			current frame's collision rect.
	return false;
}