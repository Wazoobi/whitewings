////////////////////////////////////////////////////////////////////////
//	File Name	:	"CStunShot.cpp"
//
//	Author		:	Juno Madden (JM)
//
//	Purpose		:	To encapsulate data for the player's stungun
////////////////////////////////////////////////////////////////////////

#include "CStunShot.h"

#include "SGD Wrappers/CSGD_TextureManager.h"

#include "CMessageManager.h"

#include "CEnemy.h"

CStunShot::CStunShot(void)
{
	m_fLife = 0.5f;
	m_fLifeTimer = 0.0f;

	m_pOwner = NULL;

	m_nDisplayDepth = 1;	// Z-sorting
	m_uiRefCount = 1;		// Always start with a reference to yourself
	m_uiType = OBJ_BASE;
	SetPosX(0.0f);
	SetPosY(0.0f);
	SetVelX(0.0f);
	SetVelY(0.0f);

	m_nImageID = CSGD_TextureManager::GetInstance()->LoadTexture("resource/graphics/JuM_Bullet.bmp", D3DCOLOR_XRGB(0,0,0));
}

CStunShot::~CStunShot(void)
{

}

void CStunShot::Update(float fElapsedTime)
{
	m_fLifeTimer += fElapsedTime;

	if(m_fLifeTimer > m_fLife)
		CMessageManager::GetInstance()->SendMsg(new CDestroyStunShotMessage(this));

	// Using the elapsed time
	SetPosX( GetPosX() + (GetVelX() * fElapsedTime) );
}

void CStunShot::Render(void)
{
	// TODO:	Render the current frames image
	CSGD_TextureManager::GetInstance()->Draw(m_nImageID, GetPosX(), GetPosY());
}

bool CStunShot::CheckCollision(CBase* pBase)
{
	// TODO:	Use the current frame of the animation instance to grab the collision rect and 
	//			compare it to the collision rect of the passed in CBase pointer's animation instance's 
	//			current frame's collision rect.

	// TODO:	If the collision is with an enemy, change the enemies state to stunned. Destroy
	//			this instance.

	if(CBase::CheckCollision(pBase) && pBase->GetObjectType() == OBJ_ENEMY)
	{
		CMessageManager::GetInstance()->SendMsg(new CDestroyStunShotMessage(this));
		CEnemy *pEnemy = (CEnemy*)pBase;
		pEnemy->SetState(STUNNED);
	}

	return false;
}