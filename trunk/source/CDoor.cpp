////////////////////////////////////////////////////////////////////////
//	File Name	:	"CBase.cpp"
//
//	Author		:	Juno Madden (JM)
//
//	Purpose		:	To contain all the shared data and functionality of 
//					our game objects.
////////////////////////////////////////////////////////////////////////

#include "CDoor.h"

#include "SGD Wrappers/CSGD_TextureManager.h"

CDoor::CDoor(void)
{
	m_nDisplayDepth = 1;	// Z-sorting
	m_uiRefCount = 1;		// Always start with a reference to yourself
	m_uiType = OBJ_DOOR;
	
	SetPosX(0.0f);
	SetPosY(0.0f);
	SetVelX(0.0f);
	SetVelY(0.0f);

	m_nDoorSignature = 0;

	m_bIsLocked = true;

	m_nImageID = CSGD_TextureManager::GetInstance()->LoadTexture("resource/graphics/Door.bmp");
}

CDoor::~CDoor(void)
{

}

void CDoor::Update(float fElapsedTime)
{
	// Using the elapsed time
}

void CDoor::Render(void)
{
	// TODO:	Render the current frames image

	if(m_bIsLocked)
		CSGD_TextureManager::GetInstance()->Draw(m_nImageID, GetPosX(), GetPosY(),1.0f, 1.0f, NULL, 0.0f, 0.0f, 0.0f, D3DCOLOR_ARGB(255, 255, 0, 0));
	else
		CSGD_TextureManager::GetInstance()->Draw(m_nImageID, GetPosX(), GetPosY(),1.0f, 1.0f, NULL, 0.0f, 0.0f, 0.0f, D3DCOLOR_ARGB(255, 0, 255, 0));
}

bool CDoor::CheckCollision(CBase* pBase)
{
	// TODO:	Use the current frame of the animation instance to grab the collision rect and 
	//			compare it to the collision rect of the passed in CBase pointer's animation instance's 
	//			current frame's collision rect.

	return false;
}

void CDoor::HandleEvent(CEvent* pEvent)
{
	if(pEvent->GetEventID() == "MINIGAMESUCCESS" && (int)(pEvent->GetParam()) == m_nDoorSignature)
		m_bIsLocked = false;
}