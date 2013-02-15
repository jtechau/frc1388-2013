// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "Shooter.h"
#include "../Robotmap.h"
#define VOLTAGE_OUT (7.31)
#define INCREMENT (0.1)	
Shooter::Shooter() : Subsystem("Shooter")
{
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	shooterMotor = RobotMap::shootershooterMotor;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	
	// default value for the shooter voltage
	voltageOut = VOLTAGE_OUT;
	
	shooterMotor->ChangeControlMode(CANJaguar::kVoltage);
	shooterMotor->SetPID(1.6, 0.0596, 0.1);
	shooterMotor->SetSpeedReference(CANJaguar::kSpeedRef_Encoder);
	shooterMotor->ConfigEncoderCodesPerRev(4);
	shooterMotor->ConfigMaxOutputVoltage(12);
	shooterMotor->SetVoltageRampRate(0.0);
	shooterMotor->EnableControl();
	shooterMotor->Set(3500);
	printf("PID Initialized! \n");
	
	
}
    
void Shooter::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
void Shooter::runTheShooter()
{
	
}
void Shooter::stopTheShooter()
{
	voltageOut = 0;
	shooterMotor->Set(voltageOut);
}
void Shooter::increaseVoltage()
{
	voltageOut = voltageOut + INCREMENT;	
	
	shooterMotor->Set(voltageOut);
}
void Shooter::decreaseVoltage()
{
	voltageOut = voltageOut - INCREMENT;		
	
	shooterMotor->Set(voltageOut);
}
void Shooter::runConstVoltage()
{			
	shooterMotor->Set(VOLTAGE_OUT);
}
