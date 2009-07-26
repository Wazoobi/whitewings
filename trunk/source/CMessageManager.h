#pragma once

#include "Messages.h"
#include <queue>
using std::queue;

typedef void (*MESSAGEPROC)(CBaseMessage*);

class CMessageManager
{
private:
	queue<CBaseMessage*>			m_MessageQueue;				//	Stores my messages.
	MESSAGEPROC						m_pfnMessageProc;			//	Points to user defined function.

	CMessageManager() {m_pfnMessageProc = NULL;}
	~CMessageManager() {}
	CMessageManager(const CMessageManager&);
	CMessageManager& operator=(const CMessageManager&);



public:
	
	static CMessageManager* GetInstance(void);

	//	How many messages waiting to be processed.
	inline int GetNumMessages(void) { return (int)m_MessageQueue.size(); }

	//	Setup the function pointer for our messages.
	void InitMessageSystem(MESSAGEPROC pfnMessageProc);

	//	Sends the message into the queue and awaits processing later on through
	//	The ProcessMessages() function.
	void SendMsg(CBaseMessage* pMessage);

	//	Processes all the messages that are waiting inside of the queue.
	//	Normally you only call this function once per frame.
	void ProcessMessages(void);

	//	Clears any messages that may be remaining
	void ClearMessages(void);

	//	Clears any messages that may be remaining and sets the function pointer to NULL.
	void ShutdownMessageSystem(void);
};