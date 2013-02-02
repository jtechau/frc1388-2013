// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "Robot.h"
#include "GitVersion.h"
#include "InsightLT/Line.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
DriveTrain* Robot::driveTrain = 0;
Feeder* Robot::feeder = 0;
Climber* Robot::climber = 0;
OI* Robot::oi = 0;
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION

/**
 * Initialize all members that need initialization.
 */
Robot::Robot():
	mDisplay(insight::TWO_ONE_LINE_ZONES),
	disp_GitVersion(),
	disp_BuildDate("Built on")
{

}

void Robot::initDisplay()
{
	mDisplay.registerData(disp_GitVersion, 1);
	mDisplay.registerData(disp_BuildDate,2);
    mDisplay.startDisplay();
    
    disp_GitVersion.setData(GIT_VERSION);
    disp_BuildDate.setData(__DATE__);
}


void Robot::RobotInit() {
	RobotMap::init();
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	driveTrain = new DriveTrain();
	feeder = new Feeder();
	climber = new Climber();
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	// This MUST be here. If the OI creates Commands (which it very likely
	// will), constructing it during the construction of CommandBase (from
	// which commands extend), subsystems are not guaranteed to be
	// yet. Thus, their requires() statements may grab null pointers. Bad
	// news. Don't move it.
	oi = new OI();
	lw = LiveWindow::GetInstance();
	// instantiate the command used for the autonomous period
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
	autonomousCommand = new AutonomousCommand();
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
	
	// Print version information		
	string gitVersion = GIT_VERSION;		
	if (strlen(GIT_TAG)) {		
		gitVersion += " (";		
		gitVersion += GIT_TAG;		
		gitVersion += ")";
		
		// Update display in the InsightLT
		disp_GitVersion.setData(gitVersion);
	}		
	// Display on NetConsole:		
	printf("\nSW version: %s\n", gitVersion.c_str());
	printf("Built on %s\n\n",__DATE__);
		
	// Display on SmartDashboard:		
	SmartDashboard::PutString("Software Version: ", gitVersion);
  }
	
void Robot::AutonomousInit() {
	if (autonomousCommand != NULL)
		autonomousCommand->Start();
}
	
void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}
	
void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to 
	// continue until interrupted by another command, remove
	// this line or comment it out.
	autonomousCommand->Cancel();
}
	
void Robot::TeleopPeriodic() {
	if (autonomousCommand != NULL)
		Scheduler::GetInstance()->Run();
}
void Robot::TestPeriodic() {
	lw->Run();
}
START_ROBOT_CLASS(Robot);
