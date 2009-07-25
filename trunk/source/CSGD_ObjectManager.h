////////////////////////////////////////////////
//	File	:	"CSGD_ObjectManager.h"
//
//	Author	:	David Brown (DB)
//
//	Purpose	:	To contain and manage all of our game objects.
/////////////////////////////////////////////////

#pragma once
#include <vector>
using std::vector;

class CBase;

class CSGD_ObjectManager
{
private:
	vector<CBase*> m_vObjectList;
	static CSGD_ObjectManager *instance;

public:
	CSGD_ObjectManager(void);
	~CSGD_ObjectManager(void);

	static CSGD_ObjectManager* GetInstance(void);
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