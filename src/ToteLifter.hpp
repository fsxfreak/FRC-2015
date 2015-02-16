#ifndef TOTE_LIFTER_HPP
#define TOTE_LIFTER_HPP
#include <WPILib.h>
#include <iostream>
#include <queue>
#include <fstream>
#include <ostream>
#include <string>

class ToteLifter
{
public:
	ToteLifter();
	~ToteLifter();
	void setToteLevel(int level);
	void setToteLevel1();
	void setToteLevel2();
	void setToteLevel3();
	void setToteLevel4();
	void setToteLevel5();
	void setToteLevel6();
	std::shared_ptr<Encoder> getToteEncoder();
	void update();

private:
	std::shared_ptr<Encoder> toteEncoder;
	std::shared_ptr<Talon> leftMotor;
	std::shared_ptr<Talon> rightMotor;
	bool tolerance(double left, double right, double epsilon);
	double targetDistance;
	const double toteMotorSpeed;
	const std::string encoderValueFileName;
	float distanceOffset;
};

#endif
