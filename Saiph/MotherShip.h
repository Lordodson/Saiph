#pragma once
#include "Model/Ship.h"
#include "AbstractState.h"
#include "BaseCommand.h"

#include <vector>
#include <stdlib.h>

using std::vector;

class MotherShip : public Ship
{
public:
	MotherShip(const Ship& _ship);
	~MotherShip();
	vector<Ship*> shadow;
	vector<BaseCommand*> orders;
	void ShadowAdd(Ship* _shadow);
	void Heartbeat(float _it);
private:
	void CleanUp();
	void Orders(float _it);
}; 

