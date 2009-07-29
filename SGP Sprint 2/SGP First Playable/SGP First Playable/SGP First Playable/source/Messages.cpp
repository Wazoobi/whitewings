//////////////////////////////////////////////////////////////////////////
//	File Name	:	"Messages.cpp"
//
//	Author		:	Juno Madden (JM)
//
//	Purpose		:	To encapsulate and define all messages used in the
//					message system.
//////////////////////////////////////////////////////////////////////////

#include "Messages.h"
#include "CPlayer.h"
#include "CStunShot.h"
#include "CHackOrb.h"
#include "CBase.h"
#include "CBullet.h"

CCreateStunShotMessage::CCreateStunShotMessage(CPlayer* _pPlayer):CBaseMessage(MSG_CREATE_STUNSHOT)
{
	m_pPlayer = _pPlayer;
	m_pPlayer->AddRef();
}

CCreateStunShotMessage::~CCreateStunShotMessage()
{
	m_pPlayer->Release();
}

CDestroyStunShotMessage::CDestroyStunShotMessage(CStunShot* _pStunShot):CBaseMessage(MSG_DESTROY_STUNSHOT)
{
	m_pStunShot = _pStunShot;
	m_pStunShot->AddRef();
}

CDestroyStunShotMessage::~CDestroyStunShotMessage()
{
	m_pStunShot->Release();
}

CDestroyHackOrbMessage::CDestroyHackOrbMessage(CHackOrb* _pHackOrb): CBaseMessage(MSG_DESTROY_HACKORB)
{
	m_pHackOrb = _pHackOrb;
	m_pHackOrb->AddRef();
}

CDestroyHackOrbMessage::~CDestroyHackOrbMessage()
{
	CPlayer::GetInstance()->SetHackOrbs(CPlayer::GetInstance()->GetHackOrbs() + 1);
	m_pHackOrb->Release();
}

CCreateBulletMessage::CCreateBulletMessage(CBase* _pOwner):CBaseMessage(MSG_CREATE_BULLET)
{
	m_pOwner = _pOwner;
	m_pOwner->AddRef();
}

CCreateBulletMessage::~CCreateBulletMessage()
{
	m_pOwner->Release();
}

CDestroyBulletMessage::CDestroyBulletMessage(CBullet* _pBullet):CBaseMessage(MSG_DESTROY_BULLET)
{
	m_pBullet = _pBullet;
	m_pBullet->AddRef();
}

CDestroyBulletMessage::~CDestroyBulletMessage()
{
	m_pBullet->Release();
}