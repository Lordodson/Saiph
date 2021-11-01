#pragma once
#include "Observer.h"
#include <list>
#include <iostream>

class Subject
{
public:
	std::list<Observer*> observe;

	virtual ~Subject() = 0;
	void Attach(Observer* _observe);
	void Detach(Observer* _observe);
	void NotifyObservers(Observer::ObserverEvent _ObservedEvent);
};

