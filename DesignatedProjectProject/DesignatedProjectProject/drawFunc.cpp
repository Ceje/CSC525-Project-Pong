#include "drawFunc.h"

using namespace std;

extern int mWidth, mHeight;
extern int windows[15];
extern float cubeR;
extern int textPos[];
extern int codePos[];
extern float exitR;
extern string fillerText[];
extern float infoCubeAngle[];
extern bool infoCubeInside;
extern int cameraTop;
extern Pong g1;
extern string codeText[];
extern string blerbText[];
extern string openFile;
void initQuadMenu()
{
	glEnable(GL_DEPTH_TEST);
    glClearColor(0,0,0,0);		//Specify Background Color: white
    glOrtho(-500, 500, -500, 500,-500,500);	//Define the boundries of the viewing area
    glutIgnoreKeyRepeat(1);		//Tells glut to ignore key repeat from holding down a key.
    //glEnable(GL_DEPTH_TEST);
}
void initPong()
{
	glClearColor(0, 0, 0, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glOrtho(-500, 500, -500, 500, -500, 500);
	glFrustum(-500, 500, -500, 500, 125, 250);
	glutIgnoreKeyRepeat(1);
	gluLookAt(0, -10, 200, 0, 0, 0, 0, 1, 0);
}
void rotateCameraLeft(){
	int distance = 1000;
	cameraTop++;
	if(infoCubeInside){
		int distance=100;
	}

	if(cameraTop>3){
		cameraTop=0;
	}
	//cout<<cameraTop<<"\n";
	setCubeCamera();
}
void setCubeCamera(){
	int distance = 1000;
	if(infoCubeInside){
		distance=100;
	}
	glMatrixMode(GL_PROJECTION_MATRIX);
	glLoadIdentity();
	glFrustum(-300, 300, -300, 300,350,1000);
	switch(abs(cameraTop)){
	case 0:
		gluLookAt(0,0,distance, 0,0,0, 0,1,0);
		break;
	case 1:
		gluLookAt(0,0,distance, 0,0,0, 1,0,0);
		break;
	case 2:
		gluLookAt(0,0,distance, 0,0,0, 0,-1,0);
		break;
	case 3:
		gluLookAt(0,0,distance, 0,0,0, -1,0,0);
		break;
	}
	drawInfoCube();

}
void rotateCameraRight(){
	int distance = 1000;
	cameraTop--;
	if(infoCubeInside){
		int distance=100;
	}
	if(cameraTop<0){
		cameraTop=3;
	}
	//cout<<cameraTop<<"\n";
	setCubeCamera();
}
void playerMenuInit(){
	glClearColor(0.9, 0.9, 0.9, 0.0);
	gluOrtho2D(-500,500,-500,500);
}

void initControlMenu(){
	glClearColor(0,0,0,0);
	gluOrtho2D(-500,500,-500,500);
}

void initInfoCube(){
	glEnable(GL_DEPTH_TEST);
	glClearColor(1,1,1,0);

	glFrustum(-300, 300, -300, 300,350,1000);
	gluLookAt(0,0,1000, 0,0,0, 0,1,0);
}

void emptyDisplay(){
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}

void cubeControls(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0,1,0);
	string line="Use 'W' 'A' 'S' and 'D' to turn the cube!";
	glRasterPos2i(-490, 400);
	for(unsigned int i=0; i < line.length(); i++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,line[i]);
	}
	line="Press 'space' to enter the cube!";
	glRasterPos2i(-490,300);
	for(unsigned int i=0; i < line.length(); i++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,line[i]);
	}
	line="Press 'e' and 'q' to turn the camera.";
	glRasterPos2i(-490,200);
	for(unsigned int i=0; i < line.length(); i++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,line[i]);
	}
	line="Left click anywhere to bring up the exit menu.";
	glRasterPos2i(-490,100);
	for(unsigned int i=0; i < line.length(); i++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,line[i]);
	}
	glFlush();
}

void gameControls(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0,1,0);
	string line="Left click a player score to change their color!";
	glRasterPos2i(-450, 400);
	for(unsigned int i=0;i<line.length();i++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,line[i]);
	}
	line="Right click a player score to change their controls!";
	glRasterPos2i(-450,300);
	for(unsigned int i=0;i<line.length();i++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,line[i]);
	}
	line="Right click the game to bring up the exit menu.";
	glRasterPos2i(-450,200);
	for(unsigned int i=0;i<line.length();i++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,line[i]);
	}
	/*
	line="Left click the game to pause!";
	glRasterPos2i(-450,100);
	for(unsigned int i=0;i<line.length();i++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,line[i]);
	}
	line="Player 1 controls:"+getPlayerControls(0);
	glRasterPos2i(-450,0);
	for(unsigned int i=0;i<line.length();i++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,line[i]);
	}
	line="Player 2 controls:"+getPlayerControls(1);
	glRasterPos2i(-450,-100);
	for(unsigned int i=0;i<line.length();i++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,line[i]);
	}
	line="Player 3 controls:"+getPlayerControls(2);
	glRasterPos2i(-450,-200);
	for(unsigned int i=0;i<line.length();i++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,line[i]);
	}
	line="Player 4 controls:"+getPlayerControls(3);
	glRasterPos2i(-450,-300);
	for(unsigned int i=0;i<line.length();i++){
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
	for(unsigned int i=0;i<line.length();i++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,line[i]);
	}
	glFlush();
}
void codeControls(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0,1,0);
	string line="Press 'Space' to switch files.";
	glRasterPos2i(-490,400);
	for(unsigned int i=0; i < line.length(); i++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,line[i]);
	}
	line="Press any other key to go to the next section of code.";
	glRasterPos2i(-490,300);
	for(unsigned int i=0; i < line.length(); i++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,line[i]);
	}
	line="Left click anywhere to bring up the exit menu.";
	glRasterPos2i(-490,200);
	for(unsigned int i=0; i < line.length(); i++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,line[i]);
	}
	glFlush();
}

void codeDisplay(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0,1,0);
	glRasterPos2i(-450,475);
	for(int j=0; j<=openFile.length();j++){
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,openFile[j]);	
	}
	int linePos[]={-450,425};
	
	for(int i=0; i<codePos[1];i++){
		glRasterPos2iv(linePos);

		for(int j=0; j<=codeText[i].length();j++){
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,codeText[i][j]);	
		}
		linePos[1]-=25;
	}
	glRasterPos2iv(linePos);
	for(int j=0; j<=codePos[0];j++){
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,codeText[codePos[1]][j]);	
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
		for(unsigned int i=0;i<label.length();i++){
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
	char numstr[21];
	string time= "";
	if(g1.getTime() == -1)
	{
		time = "Player 1 Wins!";
	}
	else if(g1.getTime() == -2)
	{
		time = "Player 2 Wins!";
	}
	else
	{
		sprintf(numstr, "%d", g1.getTime());
		time = time + numstr;
	}
	glRasterPos2i(-100,200);
	for(unsigned int i=0;i<label.length();i++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, label[i]);
	}
	glColor3f(0,1,0);
	glRasterPos2i(time.length()*-16,-300);
	
	for(unsigned int i=0;i<time.length();i++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, time[i]);
	}

	//glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '4');
	//glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '0');

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
	char numstr[21]; // enough to hold all numbers up to 64-bits
	//sprintf(numstr, "%d", g1.p1.getScore());
	string score = "Points: ";
	//string score="Points:0";
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

		sprintf(numstr, "%d", g1.p1.getScore());
		score = score + numstr;
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

		sprintf(numstr, "%d", g1.p2.getScore());
		score = score + numstr;
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
	for(unsigned int i=0;i<label.length();i++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, label[i]);
	}
	glColor3f(0,1,0);//may need adjusting
	glRasterPos2iv(scorePos);
	for(unsigned int i=0;i<score.length();i++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, score[i]);
	}
	glFlush();
}

void draw3dText(float tx,float ty,float tz,float ra, float rx,float ry,float rz, float sx, float sy, float sz, string words, float indent)
{
	glPushMatrix();
		glRotatef(ra,rx,ry,rz);
		glTranslatef(tx,ty,tz);
		glScalef(sx,sy,sz);
		for(unsigned int i=0;i<words.length();i++){
			if(i%(int)indent==0&&i>1){
				glTranslatef((indent*-10.5)/.1,-15/.1,0);
			}
			glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,words[i]);
		}
		
	glPopMatrix();
}

void drawTimedText(){
	int linePos[]={-450,400,-40};
	glColor3f(0,1,0);
	for(int i=0; i<textPos[1];i++){
		glRasterPos3iv(linePos);

		for(int j=0; j<=fillerText[i].length();j++){
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,fillerText[i][j]);	
		}
		linePos[1]-=25;
	}
	glRasterPos3iv(linePos);
	for(int j=0; j<=textPos[0];j++){
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,fillerText[textPos[1]][j]);	
	}
}

void drawRotatingCube(){
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
		glColor3f(0,0,1);
		glTranslatef(0,0,-350);
		glRotatef(cubeR,1,1,1);
		glPushMatrix();
			int cube=300;
			glutSolidCube(cube);		
		glPopMatrix();
		glColor3f(0,1,0);
		draw3dText(-75,75,(cube/2)+1,0,1,0,0,.1,.1,.1, "100100101010101011001001010101010110010010101010101100100101010101011001001010101010110010010101010101",8);
		draw3dText(-75,75,(cube/2)+1,90,1,0,0,.1,.1,.1, "100100101010101011001001010101010110010010101010101100100101010101011001001010101010110010010101010101",8);
		draw3dText(-75,75,(cube/2)+1,180,1,0,0,.1,.1,.1, "100100101010101011001001010101010110010010101010101100100101010101011001001010101010110010010101010101",8);
		draw3dText(-75,75,(cube/2)+1,270,1,0,0,.1,.1,.1, "100100101010101011001001010101010110010010101010101100100101010101011001001010101010110010010101010101",8);
		draw3dText(-75,75,(cube/2)+1,-90,0,1,0,.1,.1,.1, "100100101010101011001001010101010110010010101010101100100101010101011001001010101010110010010101010101",8);
		draw3dText(-75,75,(cube/2)+1,90,0,1,0,.1,.1,.1, "100100101010101011001001010101010110010010101010101100100101010101011001001010101010110010010101010101",8);
	glPopMatrix();
	glFlush();
}

void drawInfoCube(){
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);


	glColor3f(0,0,0);
	glPushMatrix();
	//cout<<"drew grid";
		
		glRotatef(infoCubeAngle[0],1,0,0);
		glRotatef(infoCubeAngle[1],0,1,0);
		glRotatef(infoCubeAngle[2],0,0,1);
		int cube=900;
		glutSolidCube(cube);		
		glColor3f(0,1,0);
		
		glColor3f(0,1,0);
		//cout<<"drew cube";
		draw3dText((-cube/2.2),200,(cube/2)+5,0,1,0,0,.25,.25,.25, blerbText[0],30);
		draw3dText((-cube/2.2),200,(cube/2)+5,90,1,0,0,.25,.25,.25, blerbText[1],30);
		draw3dText((-cube/2.2),200,(cube/2)+5,-90,1,0,0,.25,.25,.25, blerbText[2],30);
		draw3dText((-cube/2.2),200,(cube/2)+5,90,0,1,0,.25,.25,.25, blerbText[3],30);
		draw3dText((-cube/2.2),200,(cube/2)+5,-90,0,1,0,.25,.25,.25, blerbText[4],30);
		draw3dText((-cube/2.2),200,(cube/2)+5,180,0,1,0,.25,.25,.25, blerbText[5],30);
		glPushMatrix();
			//glRotatef(180, 1,0,0);
			
			draw3dText((-cube/2.2),200,-(cube/2)+5, 0,0,0,1,.25,.25,.25, blerbText[6],30);
			draw3dText((-cube/2.2),200,-(cube/2)+5,90,1,0,0,.25,.25,.25, blerbText[7],30);
			draw3dText((-cube/2.2),200,-(cube/2)+5,-90,1,0,0,.25,.25,.25, blerbText[8],30);
			draw3dText((-cube/2.2),200,-(cube/2)+5,90,0,1,0,.25,.25,.25, blerbText[9],30);
			draw3dText((-cube/2.2),200,-(cube/2)+5,-90,0,1,0,.25,.25,.25, blerbText[10],30);
			draw3dText((-cube/2.2),200,-(cube/2)+5,180,1,0,0,.25,.25,.25, blerbText[11],30);
		glPopMatrix();
		//cout<<"drew text";
	glPopMatrix();
	glFlush();
}

void changeInfoCubeView(){
	glMatrixMode(GL_PROJECTION_MATRIX);
	glLoadIdentity();
	if(infoCubeInside==false){
		glFrustum(-300, 300, -300, 300,350,1000);
		//glOrtho(-600,600,-600,600,0,1000);
		gluLookAt(0,0,100, 0,0,0, 0,1,0);
	}
	else{
		glFrustum(-300, 300, -300, 300,350,1000);
		//glOrtho(-600,600,-600,600,0,1000);
		gluLookAt(0,0,1000, 0,0,0, 0,1,0);
	}
	infoCubeInside=!infoCubeInside;
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

	glPointSize(1);
    glLineWidth(1);

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);

	glVertex3i(g1.p1.getVtx("ft", "x"), g1.p1.getVtx("ft", "y"), 0);
	glVertex3i(g1.p1.getVtx("fb", "x"), g1.p1.getVtx("fb", "y"), 0);
	glVertex3i(g1.p1.getVtx("bb", "x"), g1.p1.getVtx("bb", "y"), 0);
	glVertex3i(g1.p1.getVtx("bt", "x"), g1.p1.getVtx("bt", "y"), 0);

	glVertex3i(g1.p1.getVtx("ft", "x"), g1.p1.getVtx("ft", "y"), 20);
	glVertex3i(g1.p1.getVtx("fb", "x"), g1.p1.getVtx("fb", "y"), 20);
	glVertex3i(g1.p1.getVtx("bb", "x"), g1.p1.getVtx("bb", "y"), 20);
	glVertex3i(g1.p1.getVtx("bt", "x"), g1.p1.getVtx("bt", "y"), 20);

	glVertex2i(g1.p2.getVtx("ft", "x"), g1.p2.getVtx("ft", "y"));
	glVertex2i(g1.p2.getVtx("fb", "x"), g1.p2.getVtx("fb", "y"));
	glVertex2i(g1.p2.getVtx("bb", "x"), g1.p2.getVtx("bb", "y"));
	glVertex2i(g1.p2.getVtx("bt", "x"), g1.p2.getVtx("bt", "y"));

	glVertex2i(g1.b1.getVtx("tl", "x"), g1.b1.getVtx("tl", "y"));
	glVertex2i(g1.b1.getVtx("bl", "x"), g1.b1.getVtx("bl", "y"));
	glVertex2i(g1.b1.getVtx("br", "x"), g1.b1.getVtx("br", "y"));
	glVertex2i(g1.b1.getVtx("tr", "x"), g1.b1.getVtx("tr", "y"));

    glEnd();

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
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPointSize(1);
    glLineWidth(1);

	//gluLookAt(10, 15, 50, 0, 0, 0, 0, 1, 0);

    glColor3f(1.0, 1.0, 1.0);

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glEnable(GL_POLYGON_OFFSET_LINE);
	glPolygonOffset(-1.f, -1.f);
	glColor3f(0.0, 1.0, 0.0);

	glBegin(GL_QUADS);			
	glVertex3i(-500, 380, 0);	//Boundry Outline
	glVertex3i(-500, -380, 0);
	glVertex3i(500, -380, 0);
	glVertex3i(500, 380, 0);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glDisable(GL_POLYGON_OFFSET_LINE);
	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_QUADS);
	
	glVertex3i(g1.p1.getVtx("ft", "x"), g1.p1.getVtx("ft", "y"), 0);
	glVertex3i(g1.p1.getVtx("fb", "x"), g1.p1.getVtx("fb", "y"), 0);
	glVertex3i(g1.p1.getVtx("bb", "x"), g1.p1.getVtx("bb", "y"), 0);
	glVertex3i(g1.p1.getVtx("bt", "x"), g1.p1.getVtx("bt", "y"), 0);

	glVertex3i(g1.p1.getVtx("fb", "x"), g1.p1.getVtx("fb", "y"), 0);
	glVertex3i(g1.p1.getVtx("ft", "x"), g1.p1.getVtx("ft", "y"), 0);
	glVertex3i(g1.p1.getVtx("ft", "x"), g1.p1.getVtx("ft", "y"), 10);
	glVertex3i(g1.p1.getVtx("fb", "x"), g1.p1.getVtx("fb", "y"), 10);

	glVertex3i(g1.p1.getVtx("bb", "x"), g1.p1.getVtx("bb", "y"), 0);
	glVertex3i(g1.p1.getVtx("fb", "x"), g1.p1.getVtx("fb", "y"), 0);
	glVertex3i(g1.p1.getVtx("fb", "x"), g1.p1.getVtx("fb", "y"), 10);
	glVertex3i(g1.p1.getVtx("bb", "x"), g1.p1.getVtx("bb", "y"), 10);

	glVertex3i(g1.p1.getVtx("ft", "x"), g1.p1.getVtx("ft", "y"), 10);
	glVertex3i(g1.p1.getVtx("fb", "x"), g1.p1.getVtx("fb", "y"), 10);
	glVertex3i(g1.p1.getVtx("bb", "x"), g1.p1.getVtx("bb", "y"), 10);
	glVertex3i(g1.p1.getVtx("bt", "x"), g1.p1.getVtx("bt", "y"), 10);

	glVertex3i(g1.p1.getVtx("ft", "x"), g1.p1.getVtx("ft", "y"), 0);
	glVertex3i(g1.p1.getVtx("bt", "x"), g1.p1.getVtx("bt", "y"), 0);
	glVertex3i(g1.p1.getVtx("bt", "x"), g1.p1.getVtx("bt", "y"), 10);
	glVertex3i(g1.p1.getVtx("ft", "x"), g1.p1.getVtx("ft", "y"), 10);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glEnable(GL_POLYGON_OFFSET_LINE);
	glPolygonOffset(-1.f, -1.f);
	glColor3f(0.0, 1.0, 0.0);

	glBegin(GL_QUADS);
	glVertex3i(g1.p1.getVtx("fb", "x"), g1.p1.getVtx("fb", "y"), 0);
	glVertex3i(g1.p1.getVtx("ft", "x"), g1.p1.getVtx("ft", "y"), 0);
	glVertex3i(g1.p1.getVtx("ft", "x"), g1.p1.getVtx("ft", "y"), 10);
	glVertex3i(g1.p1.getVtx("fb", "x"), g1.p1.getVtx("fb", "y"), 10);

	glVertex3i(g1.p1.getVtx("bb", "x"), g1.p1.getVtx("bb", "y"), 0);
	glVertex3i(g1.p1.getVtx("fb", "x"), g1.p1.getVtx("fb", "y"), 0);
	glVertex3i(g1.p1.getVtx("fb", "x"), g1.p1.getVtx("fb", "y"), 10);
	glVertex3i(g1.p1.getVtx("bb", "x"), g1.p1.getVtx("bb", "y"), 10);

	glVertex3i(g1.p1.getVtx("ft", "x"), g1.p1.getVtx("ft", "y"), 10);
	glVertex3i(g1.p1.getVtx("fb", "x"), g1.p1.getVtx("fb", "y"), 10);
	glVertex3i(g1.p1.getVtx("bb", "x"), g1.p1.getVtx("bb", "y"), 10);
	glVertex3i(g1.p1.getVtx("bt", "x"), g1.p1.getVtx("bt", "y"), 10);

	glVertex3i(g1.p1.getVtx("ft", "x"), g1.p1.getVtx("ft", "y"), 0);
	glVertex3i(g1.p1.getVtx("bt", "x"), g1.p1.getVtx("bt", "y"), 0);
	glVertex3i(g1.p1.getVtx("bt", "x"), g1.p1.getVtx("bt", "y"), 10);
	glVertex3i(g1.p1.getVtx("ft", "x"), g1.p1.getVtx("ft", "y"), 10);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glDisable(GL_POLYGON_OFFSET_LINE);
	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_QUADS);
	glVertex3i(g1.b1.getVtx("bl", "x"), g1.b1.getVtx("bl", "y"), 0); //front
	glVertex3i(g1.b1.getVtx("br", "x"), g1.b1.getVtx("br", "y"), 0);
	glVertex3i(g1.b1.getVtx("br", "x"), g1.b1.getVtx("br", "y"), 5);
	glVertex3i(g1.b1.getVtx("bl", "x"), g1.b1.getVtx("bl", "y"), 5);

	glVertex3i(g1.b1.getVtx("tr", "x"), g1.b1.getVtx("tr", "y"), 0); //back
	glVertex3i(g1.b1.getVtx("tl", "x"), g1.b1.getVtx("tl", "y"), 0);
	glVertex3i(g1.b1.getVtx("tl", "x"), g1.b1.getVtx("tl", "y"), 5);
	glVertex3i(g1.b1.getVtx("tr", "x"), g1.b1.getVtx("tr", "y"), 5);

	glVertex3i(g1.b1.getVtx("bl", "x"), g1.b1.getVtx("bl", "y"), 0); //left
	glVertex3i(g1.b1.getVtx("bl", "x"), g1.b1.getVtx("bl", "y"), 5);
	glVertex3i(g1.b1.getVtx("tl", "x"), g1.b1.getVtx("tl", "y"), 5);
	glVertex3i(g1.b1.getVtx("tl", "x"), g1.b1.getVtx("tl", "y"), 0);

	glVertex3i(g1.b1.getVtx("br", "x"), g1.b1.getVtx("br", "y"), 0); //right
	glVertex3i(g1.b1.getVtx("tr", "x"), g1.b1.getVtx("tr", "y"), 0);
	glVertex3i(g1.b1.getVtx("tr", "x"), g1.b1.getVtx("tr", "y"), 5);
	glVertex3i(g1.b1.getVtx("br", "x"), g1.b1.getVtx("br", "y"), 5);

	glVertex3i(g1.b1.getVtx("tl", "x"), g1.b1.getVtx("tl", "y"), 5); //top
	glVertex3i(g1.b1.getVtx("bl", "x"), g1.b1.getVtx("bl", "y"), 5);
	glVertex3i(g1.b1.getVtx("br", "x"), g1.b1.getVtx("br", "y"), 5);
	glVertex3i(g1.b1.getVtx("tr", "x"), g1.b1.getVtx("tr", "y"), 5);
    glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glEnable(GL_POLYGON_OFFSET_LINE);
	glPolygonOffset(-1.f, -1.f);
	glColor3f(0.0, 1.0, 0.0);

	glBegin(GL_QUADS);
	glVertex3i(g1.b1.getVtx("bl", "x"), g1.b1.getVtx("bl", "y"), 0);
	glVertex3i(g1.b1.getVtx("br", "x"), g1.b1.getVtx("br", "y"), 0);
	glVertex3i(g1.b1.getVtx("br", "x"), g1.b1.getVtx("br", "y"), 5);
	glVertex3i(g1.b1.getVtx("bl", "x"), g1.b1.getVtx("bl", "y"), 5);

	glVertex3i(g1.b1.getVtx("tl", "x"), g1.b1.getVtx("tl", "y"), 5);
	glVertex3i(g1.b1.getVtx("bl", "x"), g1.b1.getVtx("bl", "y"), 5);
	glVertex3i(g1.b1.getVtx("br", "x"), g1.b1.getVtx("br", "y"), 5);
	glVertex3i(g1.b1.getVtx("tr", "x"), g1.b1.getVtx("tr", "y"), 5);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glDisable(GL_POLYGON_OFFSET_LINE);
	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_QUADS);
	
	glVertex3i(g1.p2.getVtx("ft", "x"), g1.p2.getVtx("ft", "y"), 0);
	glVertex3i(g1.p2.getVtx("fb", "x"), g1.p2.getVtx("fb", "y"), 0);
	glVertex3i(g1.p2.getVtx("bb", "x"), g1.p2.getVtx("bb", "y"), 0);
	glVertex3i(g1.p2.getVtx("bt", "x"), g1.p2.getVtx("bt", "y"), 0);

	glVertex3i(g1.p2.getVtx("fb", "x"), g1.p2.getVtx("fb", "y"), 0);
	glVertex3i(g1.p2.getVtx("ft", "x"), g1.p2.getVtx("ft", "y"), 0);
	glVertex3i(g1.p2.getVtx("ft", "x"), g1.p2.getVtx("ft", "y"), 10);
	glVertex3i(g1.p2.getVtx("fb", "x"), g1.p2.getVtx("fb", "y"), 10);

	glVertex3i(g1.p2.getVtx("bb", "x"), g1.p2.getVtx("bb", "y"), 0);
	glVertex3i(g1.p2.getVtx("fb", "x"), g1.p2.getVtx("fb", "y"), 0);
	glVertex3i(g1.p2.getVtx("fb", "x"), g1.p2.getVtx("fb", "y"), 10);
	glVertex3i(g1.p2.getVtx("bb", "x"), g1.p2.getVtx("bb", "y"), 10);

	glVertex3i(g1.p2.getVtx("ft", "x"), g1.p2.getVtx("ft", "y"), 10);
	glVertex3i(g1.p2.getVtx("fb", "x"), g1.p2.getVtx("fb", "y"), 10);
	glVertex3i(g1.p2.getVtx("bb", "x"), g1.p2.getVtx("bb", "y"), 10);
	glVertex3i(g1.p2.getVtx("bt", "x"), g1.p2.getVtx("bt", "y"), 10);

	glVertex3i(g1.p2.getVtx("ft", "x"), g1.p2.getVtx("ft", "y"), 0);
	glVertex3i(g1.p2.getVtx("bt", "x"), g1.p2.getVtx("bt", "y"), 0);
	glVertex3i(g1.p2.getVtx("bt", "x"), g1.p2.getVtx("bt", "y"), 10);
	glVertex3i(g1.p2.getVtx("ft", "x"), g1.p2.getVtx("ft", "y"), 10);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glEnable(GL_POLYGON_OFFSET_LINE);
	glPolygonOffset(-1.f, -1.f);
	glColor3f(0.0, 1.0, 0.0);

	glBegin(GL_QUADS);
	glVertex3i(g1.p2.getVtx("fb", "x"), g1.p2.getVtx("fb", "y"), 0);
	glVertex3i(g1.p2.getVtx("ft", "x"), g1.p2.getVtx("ft", "y"), 0);
	glVertex3i(g1.p2.getVtx("ft", "x"), g1.p2.getVtx("ft", "y"), 10);
	glVertex3i(g1.p2.getVtx("fb", "x"), g1.p2.getVtx("fb", "y"), 10);

	glVertex3i(g1.p2.getVtx("bb", "x"), g1.p2.getVtx("bb", "y"), 0);
	glVertex3i(g1.p2.getVtx("fb", "x"), g1.p2.getVtx("fb", "y"), 0);
	glVertex3i(g1.p2.getVtx("fb", "x"), g1.p2.getVtx("fb", "y"), 10);
	glVertex3i(g1.p2.getVtx("bb", "x"), g1.p2.getVtx("bb", "y"), 10);

	glVertex3i(g1.p2.getVtx("ft", "x"), g1.p2.getVtx("ft", "y"), 10);
	glVertex3i(g1.p2.getVtx("fb", "x"), g1.p2.getVtx("fb", "y"), 10);
	glVertex3i(g1.p2.getVtx("bb", "x"), g1.p2.getVtx("bb", "y"), 10);
	glVertex3i(g1.p2.getVtx("bt", "x"), g1.p2.getVtx("bt", "y"), 10);

	glVertex3i(g1.p2.getVtx("ft", "x"), g1.p2.getVtx("ft", "y"), 0);
	glVertex3i(g1.p2.getVtx("bt", "x"), g1.p2.getVtx("bt", "y"), 0);
	glVertex3i(g1.p2.getVtx("bt", "x"), g1.p2.getVtx("bt", "y"), 10);
	glVertex3i(g1.p2.getVtx("ft", "x"), g1.p2.getVtx("ft", "y"), 10);
	glEnd();

	glFlush();
}
