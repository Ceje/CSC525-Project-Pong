#include <iostream>
#include "drawFunc.h"
#include <string>
using namespace std;



extern int mWidth, mHeight;
extern int windows[15];
extern float cubeR;
extern int textPos[];
extern float exitR;
extern string fillerText[];



void initQuadMenu()
{
    glClearColor(0,0,0,0);		//Specify Background Color: white
    glOrtho(-500, 500, -500, 500,-500,500);	//Define the boundries of the viewing area
    glutIgnoreKeyRepeat(1);		//Tells glut to ignore key repeat from holding down a key.
    //glEnable(GL_DEPTH_TEST);
}
void playerMenuInit(){
	glClearColor(.9,.9,.9,0);
	gluOrtho2D(-500,500,-500,500);
}
void initControlMenu(){
	glClearColor(0,0,0,0);
	gluOrtho2D(-500,500,-500,500);
}

void emptyDisplay(){
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}
void extraControls(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0,1,0);
	string line="Use WASD to navigate the content!";
	glRasterPos2i(-450, 400);
	for(int i=0;i<line.length();i++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,line[i]);
	}
	line="Left click anywhere to bring up the exit menu.";
	glRasterPos2i(-450,300);
	for(int i=0;i<line.length();i++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,line[i]);
	}
	glFlush();
}
void gameControls(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0,1,0);
	string line="Left click a player score to change their color!";
	glRasterPos2i(-450, 400);
	for(int i=0;i<line.length();i++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,line[i]);
	}
	line="Right click a player score to change their controls!";
	glRasterPos2i(-450,300);
	for(int i=0;i<line.length();i++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,line[i]);
	}
	line="Right click the game to bring up the exit menu.";
	glRasterPos2i(-450,200);
	for(int i=0;i<line.length();i++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,line[i]);
	}
	/*
	line="Left click the game to pause!";
	glRasterPos2i(-450,100);
	for(int i=0;i<line.length();i++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,line[i]);
	}
	line="Player 1 controls:"+getPlayerControls(0);
	glRasterPos2i(-450,0);
	for(int i=0;i<line.length();i++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,line[i]);
	}
	line="Player 2 controls:"+getPlayerControls(1);
	glRasterPos2i(-450,-100);
	for(int i=0;i<line.length();i++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,line[i]);
	}
	line="Player 3 controls:"+getPlayerControls(2);
	glRasterPos2i(-450,-200);
	for(int i=0;i<line.length();i++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,line[i]);
	}
	line="Player 4 controls:"+getPlayerControls(3);
	glRasterPos2i(-450,-300);
	for(int i=0;i<line.length();i++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,line[i]);
	}
	*/
	glFlush();
}
void menuControls(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0,1,0);
	string line="Left click an option to start!";
	glRasterPos2i(-450, 400);
	for(int i=0;i<line.length();i++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,line[i]);
	}
	glFlush();
}

void quadMenuDisplay(){
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		glColor3f(1,1,1);
		/*glPolygonMode(GL_BACK,GL_LINE);
		glBegin(GL_QUADS);
			glVertex2i(-mWidth/2,1-mHeight/2);
			glVertex2i(-mWidth/2,1+mHeight/2);
			glVertex2i(mWidth/2,1+mHeight/2);
			glVertex2i(mWidth/2,-mHeight/2);
		glEnd();*/
		string label;
		int i=glutGetWindow();
		if(i==windows[1]){
			label="PONG!";
		}
		else if(i==windows[2]){
			label="CUBE OF INFORMATION!";
			drawRotatingCube();
		}
		else if(i==windows[3]){
			label="FREE SAMPLES!";
			drawTimedText();
		}
		else if(i==windows[4]){
			label="";
			displayExit();
		}
		glColor3f(1,1,1);
		glRasterPos2i(label.length()*-12, 0);
		for(int i=0;i<label.length();i++){
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, label[i]);
		}
	glFlush();
}
void timerDisplay(){
	glClear(GL_COLOR_BUFFER_BIT);
	
	glColor3f(0,0,0);
	glPolygonMode(GL_BACK,GL_LINE);
	glBegin(GL_QUADS);
		glVertex2i((-mWidth/2)+1,(-mHeight/2)+1);
		glVertex2i((-mWidth/2)+1,mHeight/2);
		glVertex2i(mWidth/2,mHeight/2);
		glVertex2i(mWidth/2,(-mHeight/2)+1);

		glVertex2i((-mWidth/2)+1,0);
		glVertex2i((-mWidth/2)+1,(-mHeight/2)+1);
		glVertex2i(mWidth/2,(-mHeight/2)+1);
		glVertex2i(mWidth/2,0);
	glEnd();
	string label="TIME";
	string time="0:00";
	glRasterPos2i(-100,200);
	for(int i=0;i<label.length();i++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, label[i]);
	}
	glColor3f(0,1,0);
	glRasterPos2i(time.length()*-16,-300);
	for(int i=0;i<time.length();i++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, time[i]);
	}
	glFlush();
}
void playerMenuDisplay(){
	glClear(GL_COLOR_BUFFER_BIT);
	
	glColor3f(0,0,0);
	glPolygonMode(GL_BACK,GL_LINE);
	glBegin(GL_QUADS);
		glVertex2i((-mWidth/2)+1,(-mHeight/2)+1);
		glVertex2i((-mWidth/2)+1,mHeight/2);
		glVertex2i(mWidth/2,mHeight/2);
		glVertex2i(mWidth/2,(-mHeight/2)+1);

	glEnd();
	string label;
	int winID=glutGetWindow();
	int labelPos[2];
	string score="Points:0";
	int scorePos[2];
	if(winID==windows[7]){
		
		label="Player 1";
		glBegin(GL_QUADS);
			glVertex2i(mWidth/2, mHeight/2);
			glVertex2i(0, mHeight/2);
			glVertex2i(0,-mHeight/2);
			glVertex2i(mWidth/2,-mHeight/2);	
		glEnd();
		//glColor3fv(pColor[0]);
		//score=std::toString(pScore[0]);
		labelPos[0]=-450;
		labelPos[1]=-250;
		scorePos[0]=50;
		scorePos[1]=-250;
	}
	else if(winID==windows[8]){
		
		label="Player 2";
		glBegin(GL_QUADS);
			glVertex2i(0, mHeight/2);
			glVertex2i(-mWidth/2, mHeight/2);
			glVertex2i(-mWidth/2,-mHeight/2);
			glVertex2i(0,-mHeight/2);	
		glEnd();
		//glColor3fv(pColor[1]);
		//score="Points:"+std::toString(pScore[1]);
		labelPos[0]=50;
		labelPos[1]=-250;
		scorePos[0]=-450;
		scorePos[1]=-250;
	}
	else if(winID==windows[9]){
		label="Player 3";
		glBegin(GL_QUADS);
			glVertex2i(mWidth/2, mHeight/2);
			glVertex2i(0, mHeight/2);
			glVertex2i(0,-mHeight/2);
			glVertex2i(mWidth/2,-mHeight/2);	
		glEnd();
		//glColor3fv(pColor[2]);
		//score="Points:"+std::toString(pScore[2]);
		labelPos[0]=-450;
		labelPos[1]=-250;
		scorePos[0]=50;
		scorePos[1]=-250;
	}
	else if(winID==windows[10]){
		
		label="Player 4";
		glBegin(GL_QUADS);
			glVertex2i(0, mHeight/2);
			glVertex2i(-mWidth/2, mHeight/2);
			glVertex2i(-mWidth/2,-mHeight/2);
			glVertex2i(0,-mHeight/2);	
		glEnd();
		//glColor3fv(pColor[3]);
		//score="Points:"+std::toString(pScore[3]);
		labelPos[0]=50;
		labelPos[1]=-250;
		scorePos[0]=-450;
		scorePos[1]=-250;
	}
	glRasterPos2iv(labelPos);
	for(int i=0;i<label.length();i++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, label[i]);
	}
	glColor3f(0,1,0);//may need adjusting
	glRasterPos2iv(scorePos);
	for(int i=0;i<score.length();i++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, score[i]);
	}
	glFlush();
}
void draw3dText(float tx,float ty,float tz,
				float ra, float rx,float ry,float rz, 
				float sx, float sy, float sz, 
				string words, float indent)
{
	glPushMatrix();
		glRotatef(ra,rx,ry,rz);
		glTranslatef(tx,ty,tz);
		glScalef(sx,sy,sz);
		for(int i=0;i<words.length();i++){
			if(i%(int)indent==0&&i>1){
				glTranslatef((indent*-10.5)/.1,-15/.1,0);
			}
			glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,words[i]);
		}
		
	glPopMatrix();
}
void drawTimedText(){
	int linePos[]={-450,400};
	for(int i=0; i<textPos[1];i++){
		glRasterPos2iv(linePos);

		for(int j=0; j<=fillerText[i].length();j++){
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,fillerText[i][j]);	
		}
		linePos[1]-=25;
	}
	glRasterPos2iv(linePos);
	for(int j=0; j<=textPos[0];j++){
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,fillerText[textPos[1]][j]);	
	}
}
void drawRotatingCube(){
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
		glColor3f(0,0,1);
		glRotatef(cubeR,1,1,1);
		glPushMatrix();
			int cube=300;
			glutSolidCube(cube);		
		glPopMatrix();
		glColor3f(0,1,0);
		draw3dText((-cube/2)+5,(cube/2)-15,(cube/2)+1,0,1,0,0,.1,.1,.1, "10010010101010101",2);
		draw3dText((-cube/2)+5,(cube/2)-15,(cube/2)+1,90,1,0,0,.2,.2,.2, "10010010101010101",3);
	glPopMatrix();
	glFlush();
}
void displayExit(){
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
		glColor3f(0,1,11);
		glRotatef(exitR,0,0,1);
		draw3dText(0,50,0,1,0,0,0,.5,.5,.5,"EXIT",4);
	glPopMatrix();
	glFlush();
}
void doubles(){
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}
void threeway(){
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}
void quad(){
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}
void classic(){
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}
