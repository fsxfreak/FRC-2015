#include <WPILib.h>
#include "EventRelay.hpp"
#include "Autonomous.hpp"
#include "Action.hpp"
#include "JoyButton.hpp"
#include "DriveAuto.hpp"
#include "JoystickWrapper.hpp"
#include "RobotLocation.hpp"
#include "TwoMotorGroup.hpp"
#include "Vision.hpp"
#include "ActionMap.hpp"
#include "Shifter.hpp"


class Robot: public IterativeRobot
{

private:
	EventRelay relay;
	//Autonomous auton;

	Shifter shifter;
	//Talon *talons;
	//Talon *talond;
	/*void mapJoystick()
	{

	}*/

public:
	Robot() {}

	void RobotInit()
	{
		JoyButton triggerButton(true, false, false, ButtonNames::Trigger);
		std::function<void()> callback(std::bind(&Shifter::shiftHigh, &shifter));
		Action<void()> action(callback, 0);
		relay.getMap().associate(triggerButton, action);

		JoyButton button(true, false, false, ButtonNames::Button9);
		std::function<void()> callbackShiftLow(std::bind(&Shifter::shiftLow, &shifter));
		Action<void()> actionB(callbackShiftLow, 0);
		relay.getMap().associate(button, actionB);



	}

	void AutonomousInit()
	{
		//autoDrive.move(52, .5);
		//talons = new Talon(0);
		//talond = new Talon(1);
		autoDrive.move(100, .5);
	}

	void AutonomousPeriodic()
	{
		//autoDrive.update();
		//talons->Set(.5);
		//talond->Set(.5);
		autoDrive.update();
	}

	void TeleopInit()
	{

	}

	void TeleopPeriodic()
	{
		relay.checkStates();

	}

	void DisabledInit()
	{

	}

	void DisabledPeriodic()
	{

	}
};

START_ROBOT_CLASS(Robot);
