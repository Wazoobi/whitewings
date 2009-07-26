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
#include "CMessageManager.h"

CHackOrb::CHackOrb(void)
{
	m_nImageID = CSGD_TextureManager::GetInstance()->LoadTexture("resource/graphics/JuM_SpecialMissile.bmp", D3DCOLOR_XRGB(0,0,0));

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
	CSGD_TextureManager::GetInstance()->Draw(m_nImageID, GetPosX(), GetPosY());
}

bool CHackOrb::CheckCollision(CBase* pBase)
{
	// TODO:	Use the current frame of the animation instance to grab the collision rect and 
	//			compare it to the collision rect of the passed in CBase pointer's animation instance's 
	//			current frame's collision rect.

	// TODO: Clean up collecting hack orbs. Currently just adds to your hack orb count and deletes the orb.
	if(CBase::CheckCollision(pBase) && pBase->GetObjectType() == OBJ_PLAYER)
	{
		CMessageManager::GetInstance()->SendMsg(new CDestroyHackOrbMessage(this));
	}

	return false;
}