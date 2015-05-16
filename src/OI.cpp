#include "OI.h"

OI::OI()
{
	Joystick* driveStick = new Joystick(JOYSTICK_PORT); //creates joystick
	// Process operator interface input here.
}

Joystick* getStick()
{
	return driveStick;
}
