#include "physics.h"


void Physics::computeVerticalComponent(double &num, string mode)
{
	if (mode == "a")
		this->ddy = num * cos(this->angle.getAngle());
	else if (mode == "v")
		this->dy = num * cos(this->angle.getAngle());
}

void Physics::computeHorizontalComponent(double &num, string mode)
{
	if (mode == "a")
		this->ddx = -num * sin(this->angle.getAngle());
	else if (mode == "v")
		this->dx = -num * sin(this->angle.getAngle());
}

double Physics::computeTotalComponent(double &num, string mode)
{
	if (mode == "a")
		num = sqrt(this->ddy * this->ddy + this->ddx * this->ddx);
	else if (mode == "v")
		num = sqrt(this->dy * this->dy + this->dx * this->dx);
	return num;
}

double Physics::computeAcceleration(double &acceleration)
{
	return acceleration = this->thrust / this->weight;
}

void Physics::computeVelocity()
{
	this->dx = this->dx + this->ddx * 1 / 10;
	this->dy = this->dy + this->ddy * 1 / 10;
}

Point Physics::computeDistance()
{
	this->distanceX = this->dx * 1 / 10 + 0.5 * this->ddx * 1 / 10 * 1 / 10;//computeDistance(this->dx, this->ddx, 1 / 10);
	this->distanceY = this->dy * 1 / 10 + 0.5 * this->ddy * 1 / 10 * 1 / 10;//computeDistance(this->dy, this->ddy, 1 / 10);
	return Point(distanceX, distanceY);
}




