/*************************************************************************************
 * Authors:	    CJ Done, Jacob Allen
 *Course:	    CSC 525/625
 *Modified By:	    CJ Done, Jacob Allen
 *Last Mod Date:    
 *Description:	    
 *Notes:	    N/A
 *Files:	    hw4.cpp, IOFunc.h, IOFunc.cpp, drawFunc.h, drawFunc.cpp (hwProj.sln)
 *IDE/Compiler:	    Visual Studio 2012 / GNU C++ Compiler g++ (with make)
 *Instructions for Compilation / Execution:
 *  Posix complient systems:
 *	1.  cd /source/directory/
 *	2.  make
 *	3.  ./hw4
 *  Windows Systems
 *	1.  Double click on hwProj.sln to open the project
 *	2.  Press Ctrl+F7 to compile
 *	3.  Press Ctrl+Shift+B to build (compile and link)
 *	4.  Press Ctrl+F5 to execute
 *************************************************************************************/


#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include "drawFunc.h"
#include "windows.h"
#include "menus.h"
#include "timers.h"
#include "Pong.h"


#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#else
#include <GL/glut.h>
#endif

using namespace std;
int mWidth=1000;
int mHeight=1000;
int windows[15];
float cubeR=0;
int textPos[]={0,0};
int line=0;
int lnCount=0;
float exitR=0;
float infoCubeAngle[]={0,0,0};
float infoCubeOld[]={0,0,0};
int infoCubeRot=0;
bool infoCubeNegative=false;
bool infoCubeTurned=false;
bool infoCubeTurning=false;
bool infoCubeInside=false;
int activeWindow=0;
string fillerText[]={"bob","Steve", "larry", "Lerooooooooooooooooooooooooooy"};
Pong g1 = Pong();


int main(int argc, char** argv)
{ 

#ifdef __APPLE__
    //path = "/tmp/typed.txt";
#else
    //path = "C:\\\\TEMP\\typed.txt";
#endif

    //fileInit(path); // full path to the file that we want to write to.

    //cout << "main " << Xc << endl;

    glutInit(& argc, argv);
    glutInitWindowSize(mWidth, mHeight);

	g1 = Pong(mWidth, mHeight*3/4);

    glutInitWindowPosition(100, 20);
	glutInitDisplayMode(GLUT_DEPTH);
	glEnable(GL_DEPTH_TEST);
	lnCount=4;
    quadMenu();
	
    glutMainLoop();
    return 0;
}