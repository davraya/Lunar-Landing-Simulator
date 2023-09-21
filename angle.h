#pragma once
#include <ostream>
#include <math.h>
#include <cmath>

using namespace std;

/*************************
 * An Angle class that store and angle and allow changes
 *************************/
class Angle
{
public:
	Angle(double angel):
		radians(angel){}

	void setAngle(double angle);

	double getAngle() { return this->radians; };

	void updateAngle(double angle);

private:
	double getRadians();

	void normalize();

	double radians;
};