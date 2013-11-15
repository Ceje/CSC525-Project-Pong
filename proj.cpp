/*========================================================================
 *Programmer:	    Jacob Allen
 *Network Folder:   jacob03
 *Course:	    CSC 525
 *Assignment:	    HW2
 *Modified By:	    N/A
 *Creation Date:    9/24/2013
 *Mod Date:	    9/27/2013
 *Description:	    A program to fill polygons defined from files.
 *Note:		    N/A
 *Files:	    hw2.cpp, Makefile, hwproj.sln
 *IDE/Compiler:	    VIm, GNU g++ / Microsoft Visual Studio 2012
 *Instructions for Compilation and Execution:
 *  On posix compliant machine with the GNU C-Compiler and Make installed:
 *	1.  change to the directory with source files using cd command.
 *	2.  run 'make'   to BUILD (Compile and Link)
 *	3.  type './hw2' to EXECUTE
 *  Visual Studio 2012
 *	1.  Double click on hwproj.sln to open the project.
 *	2.  Press Ctrl+F7   to COMPILE
 *	3.  Press Ctrl+Shift+B  to BUILD (Compile and Link)
 *	4.  Press Ctrl+F5   to EXECUTE
 * =====================================================================*/

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cmath>
#include <string>

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#pragma GCC diagnostic ignored "-Wdeprecated-declarations" 
#else
#include <GL/glut.h>
#endif

void drawScene();

using namespace std;

int p1 = 25;
int p2 = 25;
int bx, by = 0;
int xdir = -1;
int ydir = 1;
bool wup = true;
bool sup = true;
bool auup = true;
bool adup = true;

void paddleMove()
{
    if(!wup)
    {
	p1+=2;
    }
    else if(!sup)
    {
	p1-=2;
    }

    if(!auup)
    {
	p2+=2;
    }
    else if(!adup)
    {
	p2-=2;
    }
}

void ballMove()
{
    if(bx-5 <= -170 && by-5 < p1 && by+5 > p1-50)
    {
	xdir = xdir * -1;
    }
    if(bx+5 >= 170 && by-5 < p2 && by+5 > p2-50)
    {
	xdir = xdir * -1;
    }
    if(by == -200 || by == 200)
    {
	ydir = ydir * -1;
    }
    if(xdir==-1)
    {
	bx--;
    }
    else
    {
	bx++;
    }
    if(ydir==-1)
    {
	by--;
    }
    else if(ydir == 1)
    {
	by++;
    }
}

// OpenGL functions *******************************************************
void timerCallback(int value)
{
    paddleMove();
    ballMove();
    drawScene();
    glutTimerFunc(3, timerCallback, 0);
}

void handleKeyUp(unsigned char key, int x, int y)
{
    switch (key)
    {
	case 'w':
	    {
		wup = true;
		//cout << "w up" << endl;
		break;
	    }
	case 's':
	    {
		sup = true;
		break;
	    }
	case 'o':	//up arrow
	    {
		auup = true;
		break;
	    }
	case 'l':
	    {
		adup = true;
		break;
	    }
    }
}

void handleKeypress(unsigned char key, int x, int y)
{
    switch (key)
    {
	case 27: //Escape Key
	    {
		//tearDown();
		exit(0); //Exit the program
	    }
	case 'w':
	    {
		wup = false;
		break;
	    }
	case 's':
	    {
		sup = false;
		break;
	    }
	case 'o':
	    {
		auup = false;
		break;
	    }
	case 'l':
	    {
		adup =false;
		break;
	    }
    }
    //drawScene();
}

void initRendering()
{
    glClearColor(1, 1, 1, 0);		//Specify Background Color: white
    gluOrtho2D(-200, 200, -200, 200);	//Define the boundries of the viewing area
    glutIgnoreKeyRepeat(1);		//Tells glut to ignore key repeat from holding down a key.
    //glEnable(GL_DEPTH_TEST);
}

void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glPointSize(1);
    glLineWidth(1);
    // Draw the coordinate Axis;
    glColor3f(0, 0, 0);
    glBegin(GL_QUADS);			//Draw the x, y coordinate axies.
	glVertex2i(-170, p1);
	glVertex2i(-170, p1-50);
	glVertex2i(-190, p1-50);
	glVertex2i(-190, p1);

	glVertex2i(170, p2-50);
	glVertex2i(170, p2);
	glVertex2i(190, p2);
	glVertex2i(190, p2-50);

	glVertex2i(bx-5, by+5);
	glVertex2i(bx-5, by-5);
	glVertex2i(bx+5, by-5);
	glVertex2i(bx+5, by+5);
    glEnd();

    glFlush();
}

// The Main function of the program***********************************************************
int main(int argc, char** argv)
{
      // OpenGL Startup ****************************************
    glutInit(&argc, argv);
    glutInitWindowSize(400, 400);

    glutCreateWindow("Proj Test");
    initRendering();

    glutDisplayFunc(drawScene);
    glutKeyboardFunc(handleKeypress);
    glutKeyboardUpFunc(handleKeyUp);

    glutTimerFunc(3, timerCallback, 0);

    glutMainLoop();
    // End OpenGL ********************************************

    return 0;
}

