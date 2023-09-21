#include "point.h"
#include "uiDraw.h" // we need this for the random method
using namespace std;


class Star : public Point {

public:
   Star(double x, double y, unsigned char phase);

   unsigned char getNewPhase();

   Point getPosition() { return position;}

private:
   unsigned char phase;
   Point position;
};