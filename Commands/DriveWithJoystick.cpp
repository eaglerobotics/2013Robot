// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "DriveWithJoystick.h"
#include "../SubSystems/DriveTrain.h"
#define DEADBAND (0.1)

#define SLOW_PERCENTAGE (0.5)
#define DEMO_SCALE_SPEED (0.8)
extern bool DemoSpeed;
DriveWithJoystick::DriveWithJoystick() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::driveTrain);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
// Called just before this Command runs the first time
void DriveWithJoystick::Initialize() {
	
}
// Called repeatedly when this Command is scheduled to run
void DriveWithJoystick::Execute() {
	
	Joystick *leftStick = Robot::oi->getLeftStick();
	Joystick *rightStick = Robot::oi->getRightStick();
	
	float leftaxis = leftStick->GetAxis(Joystick::kYAxis);
	float rightaxis = rightStick->GetAxis(Joystick::kYAxis);
		
	if((leftaxis < DEADBAND) && (leftaxis > -DEADBAND))
		leftaxis = 0;
	
	if((rightaxis < DEADBAND) && (rightaxis > -DEADBAND))
		rightaxis = 0;
	
	
	// Code for the slow mode if either button "2" on the driver sticks is pressed.
	leftButton2 = Robot::oi->getLeftStick()->GetRawButton(2);
	rightButton2 = Robot::oi->getRightStick()->GetRawButton(2);
	
	if((leftButton2 == true) || (rightButton2 == true))
	{
		leftaxis *= SLOW_PERCENTAGE;
		rightaxis *= SLOW_PERCENTAGE;
	}

	if (DemoSpeed == true)
	{
		printf("true");
		leftaxis *=  DEMO_SCALE_SPEED;
		rightaxis *= DEMO_SCALE_SPEED;
	}

	Robot::driveTrain->tankDrive(leftaxis, rightaxis);
	
}
// Make this return true when this Command no longer needs to run execute()
bool DriveWithJoystick::IsFinished() {
	return false;
}
// Called once after isFinished returns true
void DriveWithJoystick::End() {
	
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveWithJoystick::Interrupted() {
}
