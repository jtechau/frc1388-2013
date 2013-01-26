// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
SpeedController* RobotMap::driveTrainDriveLeft = NULL;
SpeedController* RobotMap::driveTrainDriveRight = NULL;
RobotDrive* RobotMap::driveTrainRobotDrive = NULL;
CANJaguar* RobotMap::shooterShooterMotor = NULL;
Servo* RobotMap::feederFeederServo = NULL;
SpeedController* RobotMap::climberClimberMotor = NULL;
DigitalInput* RobotMap::climberTapeLimitLeft = NULL;
DigitalInput* RobotMap::climberTapeLimitRight = NULL;
Servo* RobotMap::climberTapeAngleLeft = NULL;
Servo* RobotMap::climberTapeAngleRight = NULL;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
void RobotMap::init() {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	LiveWindow* lw = LiveWindow::GetInstance();
	driveTrainDriveLeft = new Victor(1, 1);
	lw->AddActuator("DriveTrain", "DriveLeft", (Victor*) driveTrainDriveLeft);
	
	driveTrainDriveRight = new Victor(1, 2);
	lw->AddActuator("DriveTrain", "DriveRight", (Victor*) driveTrainDriveRight);
	
	driveTrainRobotDrive = new RobotDrive(driveTrainDriveLeft, driveTrainDriveRight);
	
	driveTrainRobotDrive->SetSafetyEnabled(true);
        driveTrainRobotDrive->SetExpiration(0.1);
        driveTrainRobotDrive->SetSensitivity(0.5);
        driveTrainRobotDrive->SetMaxOutput(1.0);
        
	shooterShooterMotor = new CANJaguar(2);
	
	
	feederFeederServo = new Servo(1, 6);
	lw->AddActuator("Feeder", "FeederServo", feederFeederServo);
	
	climberClimberMotor = new Victor(1, 3);
	lw->AddActuator("Climber", "ClimberMotor", (Victor*) climberClimberMotor);
	
	climberTapeLimitLeft = new DigitalInput(1, 1);
	lw->AddSensor("Climber", "TapeLimitLeft", climberTapeLimitLeft);
	
	climberTapeLimitRight = new DigitalInput(1, 2);
	lw->AddSensor("Climber", "TapeLimitRight", climberTapeLimitRight);
	
	climberTapeAngleLeft = new Servo(1, 4);
	lw->AddActuator("Climber", "TapeAngleLeft", climberTapeAngleLeft);
	
	climberTapeAngleRight = new Servo(1, 5);
	lw->AddActuator("Climber", "TapeAngleRight", climberTapeAngleRight);
	
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}
