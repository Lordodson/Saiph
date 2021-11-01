#include "precompiled_header"
#include "Boss.h"
#include "Ship.h"

#define SPAZ_TIME	1.0f
#define SHOT_FREQ	0.05f

Boss::Boss() : Enemy()
{
	SetJoust(false);
	SetWeaponLevel(0);
	SetScore(1000);
	SetShipID(10);
	SetWeaponID(4);
	SetShieldID(10);
	SetGeneratorID(9);
	SetPropulsionID(6);
	SetFireFrequency(1);
	SetShip(SaiphApp::CloneShipFromPrototype(GetShipID()));
	GetShip()->SetShield(SaiphApp::GetShieldFlyweight(GetShieldID()).strength);
	GetShip()->SetBattery(SaiphApp::GetGeneratorFlyweight(GetGeneratorID()).battery);
	GetShip()->SetPosition(64, BOUNDS_SIZE);
	GetShip()->SetActive(false);
	spazTime = SPAZ_TIME;
}

Boss::~Boss() {}

// interface
void Boss::AddWaypoint(const Vec2f &_waypoint) { waypoints.push_back(_waypoint); }
void Boss::Heartbeat(float _delta)
{
	unsigned int propulsionVal = 6, c = 0;
	float f = 0, heading = 0;
	Vec2f g;
	MovingObject* theMovingObject;
	PropulsionFlyweight thePropulsion;

	SetRetargetReady(true);

	// update firing
	if (RandomFloat(0, 1).GenerateValue() < GetFireFrequency())
		SetFireReady(true);
	GetShip()->SetLastFired(GetShip()->GetLastFired() + _delta);

	// update shield
	if (SaiphApp::GetShieldFlyweight(GetShieldID()).strength)
	{
		if (GetShip()->GetBattery() > SaiphApp::GetShieldFlyweight(GetShieldID()).energy * _delta)
		{
			GetShip()->SetBattery(GetShip()->GetBattery() - SaiphApp::GetShieldFlyweight(GetShieldID()).energy * _delta);
			GetShip()->SetShield(GetShip()->GetShield() + SaiphApp::GetShieldFlyweight(GetShieldID()).recharge * _delta);
			if (GetShip()->GetShield() > SaiphApp::GetShieldFlyweight(GetShieldID()).strength)
				GetShip()->SetShield(SaiphApp::GetShieldFlyweight(GetShieldID()).strength);
		}
	}

	// update battery
	GetShip()->SetBattery(GetShip()->GetBattery() + SaiphApp::GetGeneratorFlyweight(GetGeneratorID()).energy * _delta);
	if (GetShip()->GetBattery() > SaiphApp::GetGeneratorFlyweight(GetGeneratorID()).battery)
		GetShip()->SetBattery(SaiphApp::GetGeneratorFlyweight(GetGeneratorID()).battery);

	// TODO: insert your behavior algorithm code here
	//###############################################
	if (currentWaypoint >= waypoints.size()) { currentWaypoint = 0; }
	if (currentWaypoint == 1) {
		spazTime = SHOT_FREQ;
	}
	if (spazTime < 0) {

		Vec2f i = GetTarget() - GetShip()->GetPosition();
		i.Normalize();
		heading = SaiphApp::GetHeadingFromUnitVector(i);
		GetShip()->SetHeading(heading);

		Vec2f j = waypoints[currentWaypoint] - GetShip()->GetPosition();
		float f = GetShip()->GetWidth() / 2;

		if (j * j < f * f) {
			spazTime = 1.0f;
			currentWaypoint++;
		}

		j.Normalize();
		thePropulsion = SaiphApp::GetPropulsionFlyweight(propulsionVal);
		j *= thePropulsion.force;
		GetShip()->SetVelocity(j);
	}

	else {
		spazTime -= _delta;
		GetShip()->SetHeading(RandomFloat(0, 2 * PI).GenerateValue());
	}

	GetShip()->Heartbeat(_delta);
	//###############################################
}
	