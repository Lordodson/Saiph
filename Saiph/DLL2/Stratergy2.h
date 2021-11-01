#pragma once
#include "../Model/IDeflectionStrategy.h"

class Stratergy2 :
    public IDeflectionStrategy
{
public:
	Strategy2();
	void Deflect(float& x);
	void Destroy();
};

extern "C" __declspec(dllexport) IDeflectionStrategy * CreateStrategy();

