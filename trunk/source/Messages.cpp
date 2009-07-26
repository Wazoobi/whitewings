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

CCreateStunShotMessage::CCreateStunShotMessage(CPlayer* _pPlayer):CBaseMessage(MSG_CREATE_STUNSHOT)
{
	m_pPlayer = _pPlayer;
	m_pPlayer->AddRef();
}

CCreateStunShotMessage::~CCreateStunShotMessage()
{
	m_pPlayer->Release();
}

// Destroy Bullet Message
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