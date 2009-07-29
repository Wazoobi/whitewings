////////////////////////////////////////////////////////////////////////
//	File Name	:	"CBullet.cpp"
//
//	Author		:	Juno Madden (JM)
//
//	Purpose		:	To encapsulate data for bullets fired by the 
//					enemies
////////////////////////////////////////////////////////////////////////

#include "CBullet.h"

#include "CEnemy.h"
#include "CPlayer.h"

#include "CMessageManager.h"

#include "SGD Wrappers/CSGD_TextureManager.h"
#include "CTileManager.h"

CBullet::CBullet(void)
{
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

CBullet::~CBullet(void)
{

}

void CBullet::Update(float fElapsedTime)
{
	// Using the elapsed time
	SetPosX( GetPosX() + (GetVelX() * fElapsedTime) );
	SetPosY( GetPosY() + (GetVelY() * fElapsedTime) );
}

void CBullet::Render(void)
{
	// TODO:	Render the current frames image
	CSGD_TextureManager::GetInstance()->Draw(m_nImageID, GetPosX() - CTileManager::GetInstance()->GetCamera()->GetCameraPosX(),
		GetPosY() - CTileManager::GetInstance()->GetCamera()->GetCameraPosY());
}

bool CBullet::CheckCollision(CBase* pBase)
{
	// TODO:	Use the current frame of the animation instance to grab the collision rect and 
	//			compare it to the collision rect of the passed in CBase pointer's animation instance's 
	//			current frame's collision rect.

	if(CBase::CheckCollision(pBase))
	{
		if(pBase->GetObjectType() == OBJ_PLAYER)
		{
			CMessageManager::GetInstance()->SendMsg(new CDestroyBulletMessage(this));
			if(!CPlayer::GetInstance()->GetInvulnerable())
			{
				CPlayer::GetInstance()->SetHealth(CPlayer::GetInstance()->GetHealth()-10);
				CPlayer::GetInstance()->SetInvulnerable(true);
			}
		}

		if(pBase->GetObjectType() == OBJ_ENEMY)
		{
			CEnemy *pEnemy = (CEnemy*)pBase;
			if(pEnemy->GetState() == HACKED)
				CMessageManager::GetInstance()->SendMsg(new CDestroyBulletMessage(this));
		}
	}



	return false;
}