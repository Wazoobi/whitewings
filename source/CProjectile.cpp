////////////////////////////////////////////////////////////////////////
//	File Name	:	"CProjectile.cpp"
//
//	Author		:	Juno Madden (JM)
//
//	Purpose		:	To encapsulate data for projectiles
////////////////////////////////////////////////////////////////////////

#include "CProjectile.h"

#include "SGD Wrappers/CSGD_TextureManager.h"

CProjectile::CProjectile(void)
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

CProjectile::~CProjectile(void)
{

}

void CProjectile::Update(float fElapsedTime)
{
	// Using the elapsed time
	SetPosX( GetPosX() + (GetVelX() * fElapsedTime) );
	SetPosY( GetPosY() + (GetVelY() * fElapsedTime) );
}

void CProjectile::Render(void)
{
	// TODO:	Render the current frames image
}

bool CProjectile::CheckCollision(CBase* pBase)
{
	// TODO:	Use the current frame of the animation instance to grab the collision rect and 
	//			compare it to the collision rect of the passed in CBase pointer's animation instance's 
	//			current frame's collision rect.
	return false;
}