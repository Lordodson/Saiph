#include "precompiled_header"
#include "MotherShip.h"
#include "View/ViewManager.h"
#include "VelocityCommand.h"
#include "HeadingCommand.h"
#include "BaseCommand.h"

MotherShip::MotherShip(const Ship& _ship): Ship(_ship){}

MotherShip::~MotherShip() {
	CleanUp();
	for (unsigned int i = 0; i < shadow.size(); i++) {
		ViewManager::GetInstance().RemoveObject(shadow[i]);
		delete shadow[i];
		shadow[i] = nullptr;
	}
}
void MotherShip::Heartbeat(float _it) {
	Orders(_it);
	Ship::Heartbeat(_it);

	if (GetAfterburnerFlag()) {
		for (unsigned int i = 0; i < shadow.size(); ++i) {
			shadow[i]->Heartbeat(_it);

			VelocityCommand* move = new VelocityCommand();
			move->SetTarget(shadow[i]);
			move->SetVel1(GetXVelocity());
			move->SetVel2(GetYVelocity());
			move->SetTimeDelayExe(.05f * i);
			orders.push_back(move);

			HeadingCommand* decree = new HeadingCommand();
			decree->SetTarget(shadow[i]);
			decree->SetHeading(GetHeading());
			decree->SetTimeDelayExe(.05f * i);
			orders.push_back(decree);
		}
	}
	else if (!GetAfterburnerFlag()) { CleanUp(); }
}
void MotherShip::ShadowAdd(Ship* _shadow) {
	shadow.push_back(_shadow);
}
void MotherShip::CleanUp() {
	for (unsigned int i = 0; i < orders.size(); i++) {
		delete orders[i];
		orders.erase(orders.begin() + i);
	}
	for (unsigned int i = 0; i < shadow.size(); i++) {
		shadow[i]->SetPosition(GetPosition());
		shadow[i]->SetHeading(GetHeading());
		shadow[i]->SetVelocity(0, 0);
	}
}
void MotherShip::Orders(float _it) {

	for (unsigned int i = (unsigned int)_it; i < orders.size(); i++) {
		orders[i]->SetTimeDelayExe((orders[i]->GetTimeDelayExe())-_it);
		
		if (orders[i]->GetTimeDelayExe() <= 0) {
			orders[i]->Execute();
			delete orders[i];
			orders.erase(orders.begin() + i);
			i--;
		}
	}
}