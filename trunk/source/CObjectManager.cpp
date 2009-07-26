////////////////////////////////////////////////
//	File	:	"CObjectManager.cpp"
//
//	Author	:	
//
//	Purpose	:	To contain and manage all of our game objects.
/////////////////////////////////////////////////

#include "CObjectManager.h"
#include "CBase.h"
#include <algorithm>

CObjectManager::CObjectManager(void)
{
}

CObjectManager::~CObjectManager(void)
{
}

CObjectManager* CObjectManager::GetInstance(void)
{
	// Lazy Instantiation
	static CObjectManager instance;
	return &instance;
}

void CObjectManager::DeleteInstance()
{
	
}

void CObjectManager::UpdateObjects(float fElapsedTime)
{
	vector<CBase*>::iterator iter = m_vObjectList.begin();

	while(iter != m_vObjectList.end())
	{
		(*iter)->Update(fElapsedTime);
		iter++;
	}
}

void CObjectManager::RenderObjects(void)
{
	for (unsigned int i=0; i < m_vObjectList.size(); i++)
		m_vObjectList[i]->Render();
}

void CObjectManager::AddObject(CBase* pObject)
{
	//	Check for valid object pointer
	if (pObject == NULL)
		return;

	//	Add object to object list
	m_vObjectList.push_back(pObject);

	//	Add my reference to it.
	pObject->AddRef();
}

void CObjectManager::RemoveObject(CBase* pObject)
{
	//	Check for valid object pointer
	if (pObject == NULL)
		return;

	for (vector<CBase*>::iterator iter = m_vObjectList.begin();
		 iter != m_vObjectList.end();
		 iter++)
	{
		// if this is the object we are looking for.
		if ((*iter) == pObject)
		{
			// Remove my reference to this object.
			(*iter)->Release();

			// Remove the object from the list
			iter = m_vObjectList.erase(iter);
			break;
		}
	}
}

void CObjectManager::RemoveAllObjects(void)
{
	//	Call Release() on all objects.
	for (unsigned int i=0; i < m_vObjectList.size(); i++)
	{
		m_vObjectList[i]->Release();
	}

	//	Collapse the vector
	m_vObjectList.clear();
}
void CObjectManager::CheckCollisions()
{
	// TODO: Rewrite This
	
	for(unsigned int i = 0; i < m_vObjectList.size(); i++)
		for(unsigned int j = 0; j < m_vObjectList.size(); j++)
			if(m_vObjectList[i]->GetObjectType() != m_vObjectList[j]->GetObjectType())
				if(m_vObjectList[i]->CheckCollision(m_vObjectList[j]))
					continue;
}

void CObjectManager::SortObjects(void)
{
	std::sort(m_vObjectList.begin(), m_vObjectList.end(), ZSort);
}

bool ZSort(CBase* _a, CBase* _b)
{
	//TODO : Correct this for z-sorting
	//TODO : Rewrite this
	//return _a->GetDepth() < _b->GetDepth();
	return true;
}