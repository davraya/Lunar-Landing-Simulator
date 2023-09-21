#include "lander.h"


/*************************
 * The function to move the lander
 *************************/
void Lander::move(const Interface* pUI)
{
	if (pUI->isRight())
		this->physics.angle.updateAngle(-0.1);
	if (pUI->isLeft())
		this->physics.angle.updateAngle(0.1);
	if (pUI->isDown())
		this->thrustIsOn = true;
	else
		this->thrustIsOn = false;

	if (canMove)
	{
		Point p = this->computePosition(this->getFuel());
		this->position.addX(p.getX());
		this->position.addY(p.getY());
		if (this->thrustIsOn && this->getFuel() > 0)
		{
			this->consumeFuel();
		}
	}
}

/*************************
 This function do the main caculation
 It returns a point, the x of this point is the distance between prvious x to new x
 the y of this point is the distance between prvious y to new y
 *************************/
Point Lander::computePosition(double fuel)
{
	if (this->thrustIsOn && fuel > 0)
	{
		this->acceleration = this->physics.computeAcceleration(this->acceleration);
		this->physics.computeHorizontalComponent(this->acceleration,"a");
		this->physics.computeVerticalComponent(this->acceleration,"a");
		this->physics.addDdy(this->physics.gravity);
	}
	else
	{	
		double ddx = 0;
		this->physics.setDdx(ddx);
		this->physics.setDdy(this->physics.gravity);
	}

	this->acceleration = this->physics.computeTotalComponent(this->acceleration,"a");
	this->physics.computeVelocity();
	this->velocity = this->physics.computeTotalComponent(this->velocity, "v");
	Point p = this->physics.computeDistance();
	return p;

}

double Lander::getFuel() {return this->fuel;}

double Lander::getAltitude() {return this->position.getY();}

Point Lander::getPosition() {return this->position;}

void Lander::setAngle(double angle) {this->physics.angle.setAngle(angle);}

double Lander::getAngle() {return this->physics.angle.getAngle();}

void Lander::consumeFuel() {this->fuel -= 10;}
