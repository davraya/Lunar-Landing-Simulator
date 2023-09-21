#include "star.h"
using namespace std;

Star::Star(double x, double y, unsigned char phase) {
   position = Point(x, y);
   this->phase = phase;
}

unsigned char Star::getNewPhase(){
   this->phase = random(0, 255);
   return this->phase;
}