#include "angle.h"


/*************************
 set angle to another value
 *************************/
void Angle::setAngle(double angle)
{
    this->radians = angle;
    this->normalize();
}

/*************************
 update angle by adding a value
 *************************/
void Angle::updateAngle(double angle)
{
    this->radians += angle;
    this->normalize();
}

double Angle::getRadians()
{
	return this->radians;
}

/*************************
 Convert the angle between 0 and 2¦Ð
 *************************/
void Angle::normalize()
{
    if (this->radians < 0) {
        double negativeRadians = fmod(this->radians, 2 * 3.1415926);
        this->radians = 2 * 3.1415926 + negativeRadians;
    }

    else {
        this->radians = fmod(this->radians, 2 * 3.1415926);
    }
}