#pragma once
class Observers
{
public:
	enum ObservedEvent { ACTIVATE, SUBJECT_DEATH };
	virtual void Notification(ObservedEvent _ObservedEvent);
};

