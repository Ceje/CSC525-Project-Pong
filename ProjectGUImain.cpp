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

int mWidth=1000;
int mHeight=1000;


#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

using namespace std;

int windows[10];

void exitMenu(int i){
	if(i==0){
		exit(0);
	}
}

void initQuadMenu()
{
    glClearColor(1, 1, 1, 0);		//Specify Background Color: white
    gluOrtho2D(-500, 500, -500, 500);	//Define the boundries of the viewing area
    glutIgnoreKeyRepeat(1);		//Tells glut to ignore key repeat from holding down a key.
    //glEnable(GL_DEPTH_TEST);
}

void emptyDisplay(){
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}
void quadMenuDisplay(){
	glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(0,0,0);
		glBegin(GL_QUADS);
			glVertex2i(-mWidth/2,-mHeight/2);
			glVertex2i(-mWidth/2,mHeight/2);
			glVertex2i(mWidth/2,mHeight/2);
			glVertex2i(mWidth/2,-mHeight/2);
		glEnd();
		glColor3f(1,1,1);
		glPolygonMode(GL_BACK,GL_LINE);
		glBegin(GL_QUADS);
			glVertex2i(-mWidth/2,-mHeight/2);
			glVertex2i(-mWidth/2,mHeight/2);
			glVertex2i(mWidth/2,mHeight/2);
			glVertex2i(mWidth/2,-mHeight/2);
		glEnd();
		string label;
		int i=glutGetWindow();
		if(i==windows[1]){
			label="PONG!";
		}
		else if(i==windows[2]){
			label="CUBE OF INFORMATION!";
		}
		else if(i==windows[3]){
			label="FREE SAMPLES!";
		}
		else if(i==windows[4]){
			label="Exit";
		}
		glRasterPos2i(label.length()*-12, 0);
		for(int i=0;i<label.length();i++){
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, label[i]);
		}
	glFlush();
}

void gameMenu(int i){
	switch(i){
	default:
		//classicGame();
		break;
	}
}

void cubeWindow(int button, int state, int x, int y){

}

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
    glutInitWindowPosition(100, 20);
	
    windows[0]=glutCreateWindow("The Mighty Pong!");
    initQuadMenu();
    glutDisplayFunc(emptyDisplay);
	

	windows[1]=glutCreateSubWindow(windows[0],-mWidth/2,-mWidth/2,mWidth/2,mWidth/2);
	initQuadMenu();
	glutDisplayFunc(quadMenuDisplay);
	glutCreateMenu(gameMenu);
	glutAddMenuEntry("Classic",0);
	glutAddMenuEntry("Doubles",1);
	glutAddMenuEntry("3-way",2);
	glutAddMenuEntry("Quad",3);
	glutAttachMenu(0);

	windows[2]=glutCreateSubWindow(windows[0],-mWidth/2,mWidth/2,mWidth/2,mWidth/2);
	initQuadMenu();
	glutDisplayFunc(quadMenuDisplay);

	windows[3]=glutCreateSubWindow(windows[0],mWidth/2,-mWidth/2,mWidth/2,mWidth/2);
	initQuadMenu();
	glutDisplayFunc(quadMenuDisplay);
	glutMouseFunc(cubeWindow);

	windows[4]=glutCreateSubWindow(windows[0],mWidth/2,mWidth/2,mWidth/2,mWidth/2);
	initQuadMenu();
	glutDisplayFunc(quadMenuDisplay);
	glutCreateMenu(exitMenu);
	glutAddMenuEntry("Exit",1);
	glutAddMenuEntry("Return to program",0);
	glutAttachMenu(0);

    glutMainLoop();
    return 0;
}


