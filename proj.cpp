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
#include "Ball.h"

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#pragma GCC diagnostic ignored "-Wdeprecated-declarations" 
#else
#include <GL/glut.h>
#endif

using namespace std;

int sHeight = 400;
int sWidth = 600;
Paddle p1 = Paddle();
Paddle p2 = Paddle();
Ball b1 = Ball();

void drawScene();


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
    if(b1.getSpeed() == 0)
    {
		p1.reset();
		p2.reset();
    }

    if(b1.getX()-5 <= p1.getX() && b1.getY()-5 < p1.getY()+p1.getL()/2 && b1.getY()+5 > p1.getY()-p1.getL()/2)
    {
		b1.changeDir('x');
    }
    if(b1.getX()+5 >= p2.getX() && b1.getY()-5 < p2.getY()+p2.getL()/2 && b1.getY()+5 > p2.getY()-p2.getL()/2)
    {
		b1.changeDir('x');
    }
	b1.moveX(b1.getSpeed());
	b1.moveY(b1.getSpeed());
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
	default:
		b1.setSpeed(1);
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
    glClear(GL_COLOR_BUFFER_BIT);

    glPointSize(1);
    glLineWidth(1);

    glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
	glVertex2i(p1.getX(), p1.getY()+p1.getL()/2);
	glVertex2i(p1.getX(), p1.getY()-p1.getL()/2);
	glVertex2i(p1.getX()-20, p1.getY()-p1.getL()/2);
	glVertex2i(p1.getX()-20, p1.getY()+p1.getL()/2);

	glVertex2i(p2.getX(), p2.getY()+p2.getL()/2);
	glVertex2i(p2.getX(), p2.getY()-p2.getL()/2);
	glVertex2i(p2.getX()+20, p2.getY()-p2.getL()/2);
	glVertex2i(p2.getX()+20, p2.getY()+p2.getL()/2);

	glVertex2i(b1.getX()-5, b1.getY()+5);
	glVertex2i(b1.getX()-5, b1.getY()-5);
	glVertex2i(b1.getX()+5, b1.getY()-5);
	glVertex2i(b1.getX()+5, b1.getY()+5);
    glEnd();

    glFlush();
}

// The Main function of the program***********************************************************
int main(int argc, char** argv)
{
      // OpenGL Startup ****************************************
    glutInit(&argc, argv);
    //glutInitWindowSize(400, 400);
	sWidth = glutGet(GLUT_SCREEN_WIDTH)-40;
	sHeight = glutGet(GLUT_SCREEN_HEIGHT) - 100;
	glutInitWindowSize(sWidth, sHeight);

    glutCreateWindow("Proj Test");
    initRendering();

	p1.setX((-sWidth/2)+30);
	p1.setY(0);
	p1.setBound(sHeight);
	p2.setX((sWidth/2)-30);
	p2.setY(0);
	p2.setBound(sHeight);
	b1 = Ball(0, 0, sWidth, sHeight);

    glutDisplayFunc(drawScene);
    glutKeyboardFunc(handleKeypress);
    glutKeyboardUpFunc(handleKeyUp);

	std::cout << glutGet(GLUT_SCREEN_WIDTH) << 'X' << glutGet(GLUT_SCREEN_HEIGHT) << std::endl;

    glutTimerFunc(2, timerCallback, 0);

    glutMainLoop();
    // End OpenGL ********************************************

    return 0;
}

