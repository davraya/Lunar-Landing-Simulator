#pragma once

#include <ostream>
using namespace std;
#include "point.h"
#include "physics.h"
#include "uiInteract.h"


/*************************
 * Lander class
 *************************/
class Lander
{
public:
	Lander(const Point& ptUpperRight) :
		position(ptUpperRight.getX() - 50, ptUpperRight.getY() - 50),
		fuel(5000.0),
		physics(),
		canMove(true)
	{}

	void move(const Interface* pUI);

	double getFuel();

	double getAltitude();

	Point getPosition();

	void setAngle(double angle);

	double getAngle();

	Point computePosition(double fuel);

	double getVelocity() { return this->velocity; }

	bool canMove;

private:
	Point position;

	double fuel;

	void consumeFuel();

	Physics physics;

	bool thrustIsOn;

	double velocity;

	double acceleration;



};