#pragma once

#include <iomanip>  
#include <vector>
#include "point.h"
#include "uiInteract.h"
#include "uiDraw.h"
#include "ground.h"
#include "lander.h"
#include "star.h"
#include <map>

using namespace std;

/*************************************************************************
 * Demo
 * Test structure to capture the LM that will move around the screen
 *************************************************************************/
class Simulator
{
public:
   Simulator(const Point& ptUpperRight);
   // this is just for test purposes.  Don't make member variables public!
   

   void run(const Interface* pUI, void* p);

private:
   Lander LM;           // location of the LM on the screen
   Point ptUpperRight;   // size of the screen
   vector<Star> stars;
   Ground ground;
};