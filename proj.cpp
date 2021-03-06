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
#include "Pong.h"

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#pragma GCC diagnostic ignored "-Wdeprecated-declarations" 
#else
#include <GL/glut.h>
#endif

using namespace std;

// timer disctrepency between win/osx
//

int sHeight = 480;
int sWidth = 640;
Pong g1 = Pong();

void myDisplayCallback();
void drawScene();

// OpenGL functions *******************************************************
void timerCallback(int value)
{
    g1.play();
    myDisplayCallback();
    glutTimerFunc(10, timerCallback, 0);
}

void handleKeyUp(unsigned char key, int x, int y)
{
    switch (key)
    {
	case 'w':
	    {
		g1.p1.setDir(0);
		break;
	    }
	case 's':
	    {
		g1.p1.setDir(0);
		break;
	    }
	case 'o':
	    {
		g1.p2.setDir(0);
		break;
	    }
	case 'l':
	    {
		g1.p2.setDir(0);
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
		g1.p1.setDir(1);
		break;
	    }
	case 's':
	    {
		g1.p1.setDir(-1);
		break;
	    }
	case 'o':
	    {
		g1.p2.setDir(1);
		break;
	    }
	case 'l':
	    {
		g1.p2.setDir(-1);
		break;
	    }
	default:
		g1.b1.setSpeed(3);
    }
    //drawScene();
}

void initRendering()
{
    glClearColor(1, 1, 1, 0);		//Specify Background Color: white
    gluOrtho2D(-sWidth/2, sWidth/2, -sHeight/2, sHeight/2);	//Define the boundries of the viewing area
    glutIgnoreKeyRepeat(1);		//Tells glut to ignore key repeat from holding down a key.
}

void drawScene()
{
    //glClear(GL_COLOR_BUFFER_BIT);

    glPointSize(1);
    glLineWidth(1);

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
	glVertex2i(g1.p1.getVtx("ft", "x"), g1.p1.getVtx("ft", "y"));
	glVertex2i(g1.p1.getVtx("fb", "x"), g1.p1.getVtx("fb", "y"));
	glVertex2i(g1.p1.getVtx("bb", "x"), g1.p1.getVtx("bb", "y"));
	glVertex2i(g1.p1.getVtx("bt", "x"), g1.p1.getVtx("bt", "y"));

	glVertex2i(g1.p2.getVtx("ft", "x"), g1.p2.getVtx("ft", "y"));
	glVertex2i(g1.p2.getVtx("fb", "x"), g1.p2.getVtx("fb", "y"));
	glVertex2i(g1.p2.getVtx("bb", "x"), g1.p2.getVtx("bb", "y"));
	glVertex2i(g1.p2.getVtx("bt", "x"), g1.p2.getVtx("bt", "y"));

	glVertex2i(g1.b1.getVtx("tl", "x"), g1.b1.getVtx("tl", "y"));
	glVertex2i(g1.b1.getVtx("bl", "x"), g1.b1.getVtx("bl", "y"));
	glVertex2i(g1.b1.getVtx("br", "x"), g1.b1.getVtx("br", "y"));
	glVertex2i(g1.b1.getVtx("tr", "x"), g1.b1.getVtx("tr", "y"));
    glEnd();

    //glFlush();
}

void myDisplayCallback()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	drawScene();
	glFlush();
}

// The Main function of the program***********************************************************
int main(int argc, char** argv)
{
    // OpenGL Startup ****************************************
    glutInit(&argc, argv);

	/******************************************* this is all of the code needed for a pong game ********************************************/
	//not including key binds and render function this is just what's needed for the game logic
	sWidth = glutGet(GLUT_SCREEN_WIDTH)-40;
	sHeight = glutGet(GLUT_SCREEN_HEIGHT) - 100;
	
	g1 = Pong(sWidth, sHeight);
	/********************************************************* End pong game code **********************************************************/

	glutInitWindowSize(sWidth, sHeight);

    glutCreateWindow("Proj Test");
    initRendering();

    glutDisplayFunc(myDisplayCallback);
    glutKeyboardFunc(handleKeypress);
    glutKeyboardUpFunc(handleKeyUp);

	std::cout << glutGet(GLUT_SCREEN_WIDTH) << 'X' << glutGet(GLUT_SCREEN_HEIGHT) << std::endl;

    glutTimerFunc(10, timerCallback, 0);

    glutMainLoop();
    // End OpenGL ********************************************

    return 0;
}

