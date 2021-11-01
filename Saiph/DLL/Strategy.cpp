#include "Strategy.h"

Strategy::Strategy() {return;}
void Strategy::Deflect(float& x) { x = x*90;}
void Strategy::Destroy() { delete this;}

__declspec(dllexport) IDeflectionStrategy* CreateStrategy() { return new Strategy(); }
