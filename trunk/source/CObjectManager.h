////////////////////////////////////////////////
//	File	:	"CObjectManager.h"
//
//	Author	:	
//
//	Purpose	:	To contain and manage all of our game objects.
/////////////////////////////////////////////////

#pragma once
#include <vector>
using std::vector;

class CBase;

class CObjectManager
{
private:
	vector<CBase*> m_vObjectList;

public:
	CObjectManager(void);
	~CObjectManager(void);

	static CObjectManager* GetInstance(void);
	void DeleteInstance(void);

	void UpdateObjects(float fElapsedTime);
	void RenderObjects(void);

	void AddObject(CBase* pObject);
	void RemoveObject(CBase* pObject);

	void CheckCollisions();

	void RemoveAllObjects(void);

	void SortObjects(void);
};

bool ZSort(CBase* _a, CBase* _b);