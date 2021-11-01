#pragma once
#include "LevelState.h"
#include "Model/Ship.h"
#include "stdlib.h"

class BaseCommand
{
private:
	Ship* target;
	float timeDelayExe;
public:
	Ship* GetTarget() const;
	float GetTimeDelayExe() const;
	void SetTarget(Ship* _target);
	void SetTimeDelayExe(float _timeDelayExe);
	void virtual Execute() = 0;
};

