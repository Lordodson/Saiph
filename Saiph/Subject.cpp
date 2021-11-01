#include "precompiled_header"
#include "Subject.h"



Subject::~Subject() {
	NotifyObservers(Observer::SUBJECT_DEATH);
	observe.clear();
}

void Subject::Attach(Observer* _observe)
{
	observe.push_back(_observe);
}

void Subject::Detach(Observer* _observe)
{
	observe.remove(_observe);
}

void Subject::NotifyObservers(Observer::ObserverEvent _ObservedEvent) {
	for (auto iter = observe.begin(); iter != observe.end(); ++iter) {
		(*iter)->Notification(_ObservedEvent);
	}
}