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
#include "Paddle.h"

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#pragma GCC diagnostic ignored "-Wdeprecated-declarations" 
#else
#include <GL/glut.h>
#endif

void drawScene();

using namespace std;

int sHeight = 0;
int sWidth = 0;
Paddle p1(0, 25, 50);
Paddle p2(0, 25, 50);
int bx, by = 0;
int ballSpeed = 1;
int xdir = -1;
int ydir = 1;


void paddleMove()
{
    if(p1.uMotion())
    {
		p1.moveY(2);
    }
    else if(p1.dMotion())
    {
		p1.moveY(-2);
    }

    if(p2.uMotion())
    {
		p2.moveY(2);
    }
    else if(p2.dMotion())
    {
		p2.moveY(-2);
    }
}

void ballMove()
{
    if(bx == -200 || bx == 200)
    {
	bx = 0;
	by = 0;
	p1.reset();
	p2.reset();
    }

    if(bx-5 <= -170 && by-5 < p1.getY() && by+5 > p1.getY()-p1.getL())
    {
	xdir = xdir * -1;
    }
    if(bx+5 >= 170 && by-5 < p2.getY() && by+5 > p2.getY()-p2.getL())
    {
	xdir = xdir * -1;
    }
    if(by == -200 || by == 200)
    {
	ydir = ydir * -1;
    }
    if(xdir==-1)
    {
	bx-=ballSpeed;
    }
    else
    {
	bx+=ballSpeed;
    }
    if(ydir==-1)
    {
	by-=ballSpeed;
    }
    else if(ydir == 1)
    {
	by+=ballSpeed;
    }
}

// OpenGL functions *******************************************************
void timerCallback(int value)
{
    paddleMove();
    ballMove();
    drawScene();
    glutTimerFunc(2, timerCallback, 0);
}

void handleKeyUp(unsigned char key, int x, int y)
{
    switch (key)
    {
	case 'w':
	    {
		p1.stop('u');
		break;
	    }
	case 's':
	    {
		p1.stop('d');
		break;
	    }
	case 'o':
	    {
		p2.stop('u');
		break;
	    }
	case 'l':
	    {
		p2.stop('d');
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
		p1.start('u');
		break;
	    }
	case 's':
	    {
		p1.start('d');
		break;
	    }
	case 'o':
	    {
		p2.start('u');
		break;
	    }
	case 'l':
	    {
		p2.start('d');
		break;
	    }
    }
    //drawScene();
}

void initRendering()
{
    glClearColor(1, 1, 1, 0);		//Specify Background Color: white
    gluOrtho2D(-sWidth/2, sWidth/2, -sHeight/2-50, sHeight/2-50);	//Define the boundries of the viewing area
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
	glVertex2i(-170, p1.getY());
	glVertex2i(-170, p1.getY()-p1.getL());
	glVertex2i(-190, p1.getY()-p1.getL());
	glVertex2i(-190, p1.getY());

	glVertex2i(170, p2.getY()-p2.getL());
	glVertex2i(170, p2.getY());
	glVertex2i(190, p2.getY());
	glVertex2i(190, p2.getY()-p2.getL());

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
    //glutInitWindowSize(400, 400);
	sWidth = glutGet(GLUT_SCREEN_WIDTH);
	sHeight = glutGet(GLUT_SCREEN_HEIGHT);
	glutInitWindowSize(sWidth, sHeight-100);

    glutCreateWindow("Proj Test");
    initRendering();

    glutDisplayFunc(drawScene);
    glutKeyboardFunc(handleKeypress);
    glutKeyboardUpFunc(handleKeyUp);

	std::cout << glutGet(GLUT_SCREEN_WIDTH) << 'X' << glutGet(GLUT_SCREEN_HEIGHT) << std::endl;

    glutTimerFunc(2, timerCallback, 0);

    glutMainLoop();
    // End OpenGL ********************************************

    return 0;
}

