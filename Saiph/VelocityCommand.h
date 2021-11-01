#pragma once
#include "BaseCommand.h"
#include "SaiphApp.h"

class VelocityCommand : public BaseCommand
{
private:
	float vel1;
	float vel2;
public:
	void SetVel1(float _vel1);
	float GetVel1()const;
	void SetVel2(float _vel2);
	float GetVel2()const;
	void Execute();
};

