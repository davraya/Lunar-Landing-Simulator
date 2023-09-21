/*************************************************************
* 1. Name:
*      David Raya, Xing Gao
* 2. Assignment Name:
*      Lab 04: Apollo 11 Visuals
* 3. Assignment Description:
*      Simulate the Apollo 11 landing
* 4. What was the hardest part? Be as specific as possible.
*      Gouting the stars.
* 5. How long did it take for you to complete the assignment?
*      4 hours
*****************************************************************/


/**********************************************************************
 * GL Simulator
 * Just a simple program to Simulatornstrate how to create an Open GL window, 
 * draw something on the window, and accept simple user input
 **********************************************************************/

#include <iomanip>  
#include "simulator.h"
using namespace std;


/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface *pUi, void * p)
{
   Simulator *pSimulator = (Simulator *)p;

   pSimulator->run(pUi, pSimulator);


}

/*********************************
 * Main is pretty sparse.  Just initialize
 * my Simulator type and call the display engine.
 * That is all!
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
   _In_ HINSTANCE hInstance, 
   _In_opt_ HINSTANCE hPrevInstance, 
   _In_ PWSTR pCmdLine, 
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char ** argv)
#endif // !_WIN32
{
   // Initialize OpenGL
   Point ptUpperRight(400.0, 400.0);
   Interface ui(0, NULL, 
                "Open GL Simulator", 
                 ptUpperRight);

   // Initialize the game class
   Simulator Simulator(ptUpperRight);

   // set everything into action
   ui.run(callBack, &Simulator);             

   return 0;
}
