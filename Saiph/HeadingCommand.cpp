#include "precompiled_header"
#include "HeadingCommand.h"

void HeadingCommand::SetHeading(float _heading) { heading = _heading;}
float HeadingCommand::GetHeading()const { return heading; }
void HeadingCommand::Execute() { GetTarget()->SetHeading(heading); }
