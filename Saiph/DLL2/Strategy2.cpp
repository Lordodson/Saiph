#include "Strategy2.h"

Strategy2::Strategy2() { return; }
void Strategy2::Deflect(float& x) { x = -x; }
void Strategy2::Destroy() { delete this; }

__declspec(dllexport) IDeflectionStrategy* CreateStrategy() { return new Strategy2(); }