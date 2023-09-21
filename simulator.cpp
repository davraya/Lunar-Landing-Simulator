#include "simulator.h"



// I'm not sure why it is complaining
Simulator::Simulator(const Point& ptUpperRight):
LM(ptUpperRight),
ground(ptUpperRight)

{
   for (int i = 0; i < 250; i++)
   {
      double maxX = ptUpperRight.getX();
      double maxY = ptUpperRight.getY();
      double randomX = random(0, (int)maxX);
      double minY = ground.getGround(randomX);
      double randomY = random((int)minY, (int)maxY);
      unsigned char phase = random(0, 255);
      Star star = Star(randomX, randomY, phase);
      stars.push_back(star);
   }
}

void Simulator::run(const Interface* pUI, void* p) {

   ogstream gout;

   // move the ship around
   LM.move(pUI);

   ground.draw(gout);

   if (ground.onPlatform(LM.getPosition(), 20) && LM.getVelocity() < 4)
   {
      LM.canMove = false;
      gout.setPosition(Point(100, 300));
      gout << "Armstrong, we made it!" << endl;
   }
   else if (ground.hitGround(LM.getPosition(), 20))
   {
      LM.canMove = false;
      LM.setAngle(180.0);
      gout.setPosition(Point(100, 300));
      gout << "Armstrong, We have a problem!" << endl;
   }

   // draw the lander and its flames
   gout.drawLander(LM.getPosition(), LM.getAngle());
   gout.drawLanderFlames(LM.getPosition(), LM.getAngle(),
      pUI->isDown(), pUI->isLeft(), pUI->isRight());

   // put some text on the screen
   gout.setPosition(Point(10.0, 380.0));
   gout << "Fuel:     " << fixed << setprecision(2) << LM.getFuel() << " lbs" << "\n"
      << "Altitude: " << fixed << setprecision(2) << LM.getAltitude() << " meters" << "\n"
      << "Speed:   " << fixed << setprecision(2) << LM.getVelocity() << " m/s" << "\n" << endl;

   // draw our little stars
   for (auto star : stars)
      gout.drawStar(star.getPosition(), star.getNewPhase());
}





