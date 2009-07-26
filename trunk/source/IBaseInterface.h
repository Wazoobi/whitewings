#pragma once

class IBaseInterface
{
public:
	virtual ~IBaseInterface(void) = 0 {}

	// Updating our objects
	virtual void Update(float fElapsedTime) = 0;
	virtual void Render(void) = 0;
	
	// Reference counting
	virtual void AddRef(void) = 0;
	virtual void Release(void) = 0;
};