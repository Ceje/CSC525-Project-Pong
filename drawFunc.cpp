#include <iostream>
#include "drawFunc.h"
#include <string>
using namespace std;



extern int mWidth, mHeight;
extern int windows[10];



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
