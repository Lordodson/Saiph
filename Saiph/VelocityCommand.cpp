#include "precompiled_header"
#include "VelocityCommand.h"

void VelocityCommand::SetVel1(float _vel1) { vel1 = _vel1; }
float VelocityCommand::GetVel1()const { return vel1; }
void VelocityCommand::SetVel2(float _vel2) { vel2 = _vel2; }
float VelocityCommand::GetVel2()const { return vel2; }
void VelocityCommand::Execute() { GetTarget()->SetVelocity(vel1,vel2); }