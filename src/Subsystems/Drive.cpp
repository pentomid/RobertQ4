#include "Drive.h"
#include "../RobotMap.h"

Drive::Drive() :
		Subsystem("Drive"),
		left(new Talon(MOTOR_LEFT)),
		right(new Talon(MOTOR_RIGHT))
{

}

float Drive::max(float x,float y) //determines which value is larger
{
	return (x > y ? x : y);
}

void Drive::arcadeDrive(float move, float rotate)
{
	float leftMotorOutput;
	float rightMotorOutput;

	if (move > 0.0) //converts joystick values to motor voltage values
	{
		if (rotate > 0.0)
		{
			leftMotorOutput = move - rotate;
			rightMotorOutput = max(move,rotate);
		}
		else
		{
			leftMotorOutput = max(move,-rotate);
			rightMotorOutput = move + rotate;
		}
	}
	else
	{
		if (rotate > 0.0)
		{
			leftMotorOutput = - max(-move,rotate);
			rightMotorOutput = move + rotate;
		}
		else
		{
			leftMotorOutput = move - rotate;
			rightMotorOutput = - max(-move,-rotate);
		}
	}
	left->Set(leftMotorOutput); //sends motor value to motor controller
	right->Set(rightMotorOutput); //sends motor value to motor controller
}

void Drive::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new ArcadeDrive());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
