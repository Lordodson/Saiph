#include "precompiled_header"
#include "BaseCommand.h"

void BaseCommand::SetTarget(Ship* _ship) { target = _ship; }
Ship* BaseCommand::GetTarget()const { return target; }
void BaseCommand::SetTimeDelayExe(float _timeDelayExe) { timeDelayExe = _timeDelayExe; }
float BaseCommand::GetTimeDelayExe()const { return timeDelayExe; }
