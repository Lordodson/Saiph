#include "Stratergy2.h"

Stratergy2::Stratergy2() { return; }

void Stratergy2::Deflect(float& x)
{
	x = x * 12;
}

void Stratergy2::Destroy()
{
	delete this;
}

__declspec(dllexport) IDeflectionStrategy* CreateStrategy()
{
	return new Strategy2();
}