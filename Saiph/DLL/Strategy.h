#pragma once
#include "../Model/IDeflectionStrategy.h"
class Strategy : public IDeflectionStrategy
{
public:
	Strategy();
	void Deflect(float& x);
	void Destroy();
};

extern "C" __declspec(dllexport) IDeflectionStrategy* CreateStrategy();
