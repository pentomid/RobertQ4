#include "CommandBase.h"
#include "Subsystems/ExampleSubsystem.h"
#include "Commands/Scheduler.h"

// Initialize a single static instance of all of your subsystems to NULL
OI* CommandBase::oi = NULL;
Drive* drive = NULL;
// PID* pid = NULL;

CommandBase::CommandBase(char const *name) :
		Command(name)
{

}

CommandBase::CommandBase() :
		Command()
{

}

void CommandBase::init()
{
	// Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.

	oi = new OI();
	drive = new Drive();
	// pid = new PID();
}

ArcadeDrive::ArcadeDrive()
{
	Requires(drive);
}

void ArcadeDrive::Execute()
{
	float move = oi->getStick()->GetY();
	float rotate = oi->getStick()->GetZ();
	drive -> arcadeDrive(move,rotate);
}
