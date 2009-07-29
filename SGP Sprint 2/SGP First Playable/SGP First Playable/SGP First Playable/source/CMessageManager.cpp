#include "CMessageManager.h"

CMessageManager* CMessageManager::GetInstance(void)
{
	static CMessageManager instance;
	return &instance;
}

void CMessageManager::InitMessageSystem(MESSAGEPROC pfnMessageProc)
{
	//	Error check to make sure the message proc is valid.
	if (!pfnMessageProc)
		return;

	//	Get the Msg Proc
	m_pfnMessageProc = pfnMessageProc;
}

void CMessageManager::SendMsg(CBaseMessage* pMsg)
{
	//	Make sure the message exists.
	if (!pMsg)	
		return;

	//	Send the message to the queue for processing later on.
	m_MessageQueue.push(pMsg);
}

void CMessageManager::ProcessMessages(void)
{
	//	Error check to make sure we get a message proc.
	if(!m_pfnMessageProc)
		return;

	//	go through the entire queue and process the messsages that are waiting.
	while(!m_MessageQueue.empty())
	{
		m_pfnMessageProc(m_MessageQueue.front());		//	Process the first message.
		delete m_MessageQueue.front();				//	Delete the message memory.
		m_MessageQueue.pop();						//	Go to the next message.
	}
}

void CMessageManager::ClearMessages(void)
{
	//	Clear out any messages waititng.
	while(!m_MessageQueue.empty())
	{
		delete m_MessageQueue.front();
		m_MessageQueue.pop();
	}
}

void CMessageManager::ShutdownMessageSystem(void)
{
	//	Clear out any messages waiting.
	ClearMessages();

	//	Clear the function pointer
	m_pfnMessageProc = NULL;
}