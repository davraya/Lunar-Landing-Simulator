#pragma once
#include <ostream>
using namespace std;
#include "point.h"
#include "angle.h"
#include <math.h>


/*************************
 * The class to handle all the compute stuff
 *************************/
class Physics
{
public:
	Physics():
		thrust(45000.0),
		weight(15103.0),
		gravity(-1.625),
		angle(0.0),
		dx(0.0),
		dy(0.0),
		ddx(0.0),
		ddy(gravity)
	{}
	void computeVerticalComponent(double &change, string mode);

	void computeHorizontalComponent(double &change, string mode);

	double computeTotalComponent(double &change, string mode);

	double computeAcceleration(double& acceleration);

	void computeVelocity();

	Point computeDistance();

	void setDdy(double &ddy) { this->ddy = ddy; }

	void addDdy(double& ddy) { this->ddy += ddy; }

	void setDdx(double &ddx) { this->ddx = ddx; }

	void setDx(double &dx) { this->dx = dx; }

	void setDy(double &dy) { this->dy = dy; }

	void setDistanceX(double &distanceX) { this->distanceX = distanceX; }

	void setDistanceY(double &distanceY) { this->distanceY = distanceY; }

	double gravity;

	Angle angle;

private:
	double weight;

	double thrust;

	// Horizontal velocity
	double dx;

	// Vertical velocity
	double dy;

	// Horizontal acceleration
	double ddx;

	// Vertical acceleration
	double ddy;

	// the distance between prvious x to new x
	double distanceX;

	// the distance between prvious y to new y
	double distanceY;
	

};