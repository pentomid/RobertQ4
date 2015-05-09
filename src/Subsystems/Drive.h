#ifndef Drive_H
#define Drive_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Drive: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Talon* left;
	Talon* right;
public:
	Drive();
	void InitDefaultCommand();
	void arcadeDrive(float move, float rotate); //interprates joystick to motion
	float max(float x,float y);
};

#endif
