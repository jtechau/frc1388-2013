// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "Climber.h"
#include "../Robotmap.h"
#include "../Commands/Climb.h"
#define CLIMBER_POWER_IN 1.0
#define CLIMBER_POWER_OUT 1.0 //100% power currently, but untested as of 3/30.

Climber::Climber() : Subsystem("Climber"){
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	climberMotor = RobotMap::climberClimberMotor;
	tapeLimitLeft = RobotMap::climberTapeLimitLeft;
	tapeLimitRight = RobotMap::climberTapeLimitRight;
	tapeAngleLeft = RobotMap::climberTapeAngleLeft;
	tapeAngleRight = RobotMap::climberTapeAngleRight;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}
    
void Climber::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	SetDefaultCommand(new Climb());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND]
}
// Put methods for controlling this subsystem(new Climber())->TapesUpDown();
// here. Call these from Commands.
void Climber::TapesInOut(float opstickx, bool opTapesIn, bool opTapesOut, bool TapesEnabled, bool tapeLimitLeft, bool tapeLimitRight, bool limitOverrideL, bool limitOverrideR){
		
	if (opTapesIn == true )
		{
		// Commented out on 3/21/2013 16:23 to disable limit switches
		// NOTE: If you'd like to disable limit switches, comment everything in these brackets out
		// and add the line : climberMotor->Set(-CLIMBER_POWER_IN); -Joel (3/22, 9:50 AM)
			if (tapeLimitLeft == true )
			{
					climberMotor->Set(-CLIMBER_POWER_IN);
			}
			else if (limitOverrideL == true || limitOverrideR == true)
			{
					climberMotor->Set(-CLIMBER_POWER_IN);
			}
			else 
			{
					climberMotor->Set(0);
			}
		}	
	else if (opTapesOut == true)
		{
			climberMotor->Set(CLIMBER_POWER_OUT);
		}
	else 
		{
			climberMotor->Set(0);
		}
}
void Climber::TapesUpDown(float opstickx, float opsticky, bool opTapesIn, bool opTapesOut, bool TapesEnabled)
	{        
	
	//scale down joystick values for servos
		float makepositive = 1.2;
		float scalingfactor = .4;      
		opsticky = (opsticky + makepositive)*scalingfactor;		
		opstickx = opstickx*.6; 		//This may need to be changed.
			
	
	//Set scaled joystick values to servo for trim operation
	if ( opstickx <= -.3 || opstickx >= .3 ){ 	//Deadband 
		
		if (opstickx >= .3){
			tapeAngleLeft->Set(opsticky); //change the y value with the x
			tapeAngleRight->Set(1-(opsticky+opstickx));
		}
		if (opstickx <= -.3){
			tapeAngleLeft->Set(opsticky + opstickx); //change the y value with the x
			tapeAngleRight->Set(1-opsticky);
		}
	}
	//Set y values to servo for normal (trimless) operation.
	else {
		tapeAngleLeft->Set(opsticky);
		tapeAngleRight->Set(1 - opsticky); 
	}
}

