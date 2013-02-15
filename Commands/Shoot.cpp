// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "Shoot.h"
Shoot::Shoot() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(Robot::feeder);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
// Called just before this Command runs the first time
void Shoot::Initialize()
{
	printf("disc shot\n");
	
	timer.Reset();
	timer.Start();
}
// Called repeatedly when this Command is scheduled to run
void Shoot::Execute()
{
	Robot::feeder->Feed();	
	
}
// Make this return true when this Command no longer needs to run execute()
bool Shoot::IsFinished()
{	
	bool trigger = Robot::oi->returnRightTrigger();
	timeCount = timer.Get();
	printf("Time: %f \n", timeCount);
	if((trigger == false) && (timeCount > 0.6))
		return true;
	else
		return false;
//	printf("Time: %f", timer.Get());
	
//	if(timer.Get() > 0.5)
//		return true;
//	else
//		return false;	
}
// Called once after isFinished returns true
void Shoot::End()
{
	printf("The End! \n");
	Robot::feeder->Reset();
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Shoot::Interrupted()
{
	Shoot::End();
}
