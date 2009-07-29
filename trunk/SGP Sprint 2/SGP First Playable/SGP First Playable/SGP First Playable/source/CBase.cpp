////////////////////////////////////////////////////////////////////////
//	File Name	:	"CBase.cpp"
//
//	Author		:	Juno Madden (JM)
//
//	Purpose		:	To contain all the shared data and functionality of 
//					our game objects.
////////////////////////////////////////////////////////////////////////

#include "CBase.h"

#include "SGD Wrappers/CSGD_TextureManager.h"
#include "CTileManager.h"

#define OFFSET_X CTileManager::GetInstance()->GetCamera()->GetCameraPosX()
#define OFFSET_Y CTileManager::GetInstance()->GetCamera()->GetCameraPosY()

CBase::CBase(void)
{
	m_nDisplayDepth = 1;	// Z-sorting
	m_uiRefCount = 1;		// Always start with a reference to yourself
	m_uiType = OBJ_BASE;
	SetPosX(0.0f);
	SetPosY(0.0f);
	SetVelX(0.0f);
	SetVelY(0.0f);
}

CBase::~CBase(void)
{

}

void CBase::Update(float fElapsedTime)
{
	// Using the elapsed time
	SetPosX( GetPosX() + (GetVelX() * fElapsedTime) );
	SetPosY( GetPosY() + (GetVelY() * fElapsedTime) );
}

void CBase::Render(void)
{
	// TODO:	Render the current frames image
}

RECT CBase::GetRect(void) const
{
	RECT objectRectangle;
	//if(GetObjectType() != 4)
	//{
	//	float X = GetPosX() - CTileManager::GetInstance()->GetCamera()->GetCameraPosX();
	//	float Y = GetPosY() - CTileManager::GetInstance()->GetCamera()->GetCameraPosY();
	//	SetRect(&objectRectangle, X, Y, X+32, Y+32);
	//}
	//else
		SetRect(&objectRectangle, GetPosX(), GetPosY(), GetPosX() + 32, GetPosY() + 32);

	return objectRectangle;
}

bool CBase::CheckCollision(CBase* pBase)
{
	// TODO:	Use the current frame of the animation instance to grab the collision rect and 
	//			compare it to the collision rect of the passed in CBase pointer's animation instance's 
	//			current frame's collision rect.

	RECT temp;
	if(IntersectRect(&temp,&GetRect(),&pBase->GetRect()))
		return true;
	else
		return false;

	return false;
}