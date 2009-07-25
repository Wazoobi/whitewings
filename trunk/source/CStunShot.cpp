////////////////////////////////////////////////////////////////////////
//	File Name	:	"CStunShot.cpp"
//
//	Author		:	Juno Madden (JM)
//
//	Purpose		:	To encapsulate data for the player's stungun
////////////////////////////////////////////////////////////////////////

#include "CStunShot.h"

#include "SGD Wrappers/CSGD_TextureManager.h"

CStunShot::CStunShot(void)
{
	m_pOwner = NULL;

	m_nDisplayDepth = 1;	// Z-sorting
	m_uiRefCount = 1;		// Always start with a reference to yourself
	m_uiType = OBJ_BASE;
	SetPosX(0.0f);
	SetPosY(0.0f);
	SetVelX(0.0f);
	SetVelY(0.0f);
}

CStunShot::~CStunShot(void)
{

}

void CStunShot::Update(float fElapsedTime)
{
	// Using the elapsed time
	SetPosX( GetPosX() + (GetVelX() * fElapsedTime) );
	SetPosY( GetPosY() + (GetVelY() * fElapsedTime) );

	// TODO:	Reset the SHOT_DELAY
}

void CStunShot::Render(void)
{
	// TODO:	Render the current frames image
}

bool CStunShot::CheckCollision(CBase* pBase)
{
	// TODO:	Use the current frame of the animation instance to grab the collision rect and 
	//			compare it to the collision rect of the passed in CBase pointer's animation instance's 
	//			current frame's collision rect.

	// TODO:	If the collision is with an enemy, change the enemies state to stunned. Destroy
	//			this instance.
	return false;
}