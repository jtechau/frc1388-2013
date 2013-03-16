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
#define CLIMBER_POWER_IN 0.6
#define CLIMBER_POWER_OUT 0.6
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
void Climber::TapesInOut(float opstickx, bool opTapesIn, bool opTapesOut, bool TapesEnabled, bool tapeLimitLeft, bool tapeLimitRight){
		
	if (opTapesIn == true )
		{
		
		if (tapeLimitLeft == false && tapeLimitRight == false){
				climberMotor->Set(-CLIMBER_POWER_IN);
			}
			else {
				climberMotor->Set(0);
			}
														  //Change as necessary.
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
void Climber::TapesUpDown(float opsticky, bool opTapesIn, bool opTapesOut, bool TapesEnabled)
	{        
	
		//code to determine movement permission of servos
	if (opTapesIn == true){
			TapesEnabled = false;
		}
		else if(opTapesOut == true ){
			TapesEnabled = true;
		}
	//end movement position code
	
		float makepositive = 1.2;
		
		float scalingfactor = .4; //take the value range from 0-2 to 1/4 of that to be between 0-1 for input
		opsticky = (opsticky + makepositive)*scalingfactor;		
		
	//	if (TapesEnabled == false){
		
		
		//	tapeAngleLeft->SetOffline();       
		//	tapeAngleRight->SetOffline();
		
	//	}
	//	else { //TapesEnabled == true
			
			tapeAngleLeft->Set(opsticky);
			
			tapeAngleRight->Set(1 - opsticky); // mirror servo output in other direction
	//	}
	}
