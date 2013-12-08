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
float infoCubeAngle[]={0,0,0,0};
float infoCubeOld[]={0,0,0,0};
int infoCubeRot=0;
bool infoCubeNegative=false;
bool infoCubeTurned=false;
bool infoCubeTurning=false;
bool infoCubeInside=false;
int activeWindow=0;
int cameraTop=0;
string blerbText[]={
"Companies that do not employ  computer programmers are      willing to contract their     services for as much as $100  to $400 per hour, according to Ask IT Career Coach, a career informational website."
,"According to the Indeed       website, starting salaries in the computer programming field in January 2012 range from   $59,000 to $112,000 per year. "
,"Computer programming is a     career that can be performed  from anywhere you can carry a laptop computer and that gives you access to the Internet. "
,"Job security is an advantage  enjoyed by most computer      programmers. Computer         technology advances at a fast rate, keeping the demand for  computer programmers at a high level."
,"Intellectually challenging    work: Computer programmers are required to use their        creativity, intellect,        personal vision, problem      solving skills, & initiative." 
,"Computer Science enables      people to create their own    worlds and rules within the   programs."
,"Use your experience with      computer systems to find or   even create employment        opportunities in other fields"
,"Enjoy math? Like language?    study computer science today!"
,"Every job is a puzzle just    waiting to be solved in       computer science"
,"Learn the basis of computer   thought and implimentation in computer science"
,"Learn to automate your problems with science, COMPUTER      SCIENCE!"
,"Recursion holds the answers,  Learn it today in the field of computer science."
};


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

	g1 = Pong(mWidth, mHeight);

    glutInitWindowPosition(100, 20);
	lnCount=4;
    quadMenu();
	
    glutMainLoop();
    return 0;
}