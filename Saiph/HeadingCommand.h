#pragma once
#include "BaseCommand.h"

class HeadingCommand : public BaseCommand
{
private:
    float heading;
public:
    float GetHeading()const;
    void SetHeading(float _heading);
    void Execute();
};

