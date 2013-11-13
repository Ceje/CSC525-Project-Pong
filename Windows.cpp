#include <iostream>
#include <string>
#include "drawFunc.h"
#include "windows.h"
#include "menus.h"
using namespace std;

extern int mWidth, mHeight;
extern int windows[15];

void rotateCube(unsigned char key, int x, int y){}
void controlList(int i){

}
void closeQuadMenu(){
	for(int i=4;i>=0;i--){
		glutDestroyWindow(windows[i]);
	}
	glutDestroyWindow(windows[12]);
	glutSetWindow(windows[6]);
}
void codeWindow(int button, int state, int x, int y){
	glutInitWindowSize(mWidth, mHeight);
	glutInitWindowPosition(100,20);
	windows[6]=glutCreateWindow("FREE SAMPLES!");
	initQuadMenu();
	glutDisplayFunc(emptyDisplay);
	glutCreateMenu(exitMenu);
	glutAddMenuEntry("Exit to menu",2);
	glutAddMenuEntry("Return to program",1);
	glutAddMenuEntry("Exit",0);
	glutAttachMenu(0);
	closeQuadMenu();


	glutInitWindowSize(mWidth/2, mHeight/4);
    glutInitWindowPosition(1200, 20);
	windows[12]=glutCreateWindow("Controls!");
	initControlMenu();
	glutDisplayFunc(extraControls);
}
void playerMenuMenu(){
	glutCreateMenu(playerColorMenu);
	glutAddMenuEntry("Black",0);
	glutAddMenuEntry("White",1);
	glutAddMenuEntry("Red",2);
	glutAddMenuEntry("Blue",3);
	glutAddMenuEntry("Green",4);
	//glutAddMenuEntry("Custom",5);
	glutAttachMenu(0);

	glutCreateMenu(playerControlMenu);
	glutAddMenuEntry("W/S",0);
	glutAddMenuEntry("A/D",1);
	glutAddMenuEntry("I/K",2);
	glutAddMenuEntry("J/L",3);
	//glutAddMenuEntry("Custom",4);
	glutAttachMenu(2);
}
void threeWayGUI(){
	windows[7]=glutCreateSubWindow(windows[6],0,0,mWidth/4, 40);
	playerMenuMenu();
	playerMenuInit();
	glutDisplayFunc(playerMenuDisplay);

	windows[8]=glutCreateSubWindow(windows[6],(mWidth-(mWidth/4)),0,mWidth/4,40);
	playerMenuInit();
	glutDisplayFunc(playerMenuDisplay);

	windows[9]=glutCreateSubWindow(windows[6],0,(mHeight-40),mWidth/4,40);
	playerMenuInit();
	glutDisplayFunc(playerMenuDisplay);
}
void quadGUI(){
	windows[7]=glutCreateSubWindow(windows[6],0,0,mWidth/4, 40);
	playerMenuInit();
	glutDisplayFunc(playerMenuDisplay);

	windows[8]=glutCreateSubWindow(windows[6],(mWidth-(mWidth/4)),0,mWidth/4,40);
	playerMenuInit();
	glutDisplayFunc(playerMenuDisplay);

	windows[9]=glutCreateSubWindow(windows[6],0,(mHeight-40),mWidth/4,40);
	playerMenuInit();
	glutDisplayFunc(playerMenuDisplay);

	windows[10]=glutCreateSubWindow(windows[6],(mWidth-(mWidth/4)),(mHeight-40),mWidth/4,40);
	playerMenuInit();
	glutDisplayFunc(playerMenuDisplay);

}
void classicGUI(){
	windows[7]=glutCreateSubWindow(windows[6],0,0,mWidth/4, 40);
	playerMenuInit();
	glutDisplayFunc(playerMenuDisplay);

	windows[8]=glutCreateSubWindow(windows[6],(mWidth-(mWidth/4)),0,mWidth/4,40);
	playerMenuInit();
	glutDisplayFunc(playerMenuDisplay);
}
void timerHUD(){
	windows[11]=glutCreateSubWindow(windows[6],mWidth/3,0,mWidth/3,80);
	playerMenuInit();
	glutDisplayFunc(timerDisplay);
}
void gameWindow(int gamemode){
	glutInitWindowSize(mWidth, mHeight);
	glutInitWindowPosition(100,20);
	windows[6]=glutCreateWindow("PLAYBALL!");
	initQuadMenu();
	
	switch(gamemode){
	case 1:
		//doubles
		glutDisplayFunc(doubles);
		classicGUI();
		break;
	case 2:
		//3way
		glutDisplayFunc(threeway);
		threeWayGUI();
		break;
	case 3:
		//quad
		glutDisplayFunc(quad);
		quadGUI();
		break;
	default:
		//default
		glutDisplayFunc(classic);
		classicGUI();
		
	}
	
	timerHUD();
	glutSetWindow(windows[6]);
	glutCreateMenu(exitMenu);
	glutAddMenuEntry("Exit to menu",2);
	glutAddMenuEntry("Return to program",1);
	glutAddMenuEntry("Exit",0);
	glutAttachMenu(2);
	closeQuadMenu();


	glutInitWindowSize(mWidth*3/4, mHeight/4);
    glutInitWindowPosition(1100, 20);
	windows[12]=glutCreateWindow("Controls!");
	initControlMenu();
	glutDisplayFunc(gameControls);

}
void gameDestroy(){
		for(int i=11;i>5;i--){
			glutDestroyWindow(windows[i]);
		}
		glutSetWindow(windows[0]);
}
void cubeWindow(int button, int state, int x, int y){
	
	//cout<<"initializing cube\n";
    glutInitWindowSize(mWidth, mHeight);
    glutInitWindowPosition(100, 20);
	//cout<<"building cube\n";
	windows[6]=glutCreateWindow("THE CUBE OF INFORMATION!");
	initQuadMenu();
	glutDisplayFunc(emptyDisplay);
	//cout<<"cube menu\n";
	glutCreateMenu(exitMenu);
	glutAddMenuEntry("Exit to menu",2);
	glutAddMenuEntry("Return to program",1);
	glutAddMenuEntry("Exit",0);
	glutAttachMenu(0);
	glutKeyboardFunc(rotateCube);
	closeQuadMenu();

	glutInitWindowSize(mWidth/2, mHeight/4);
    glutInitWindowPosition(1200, 20);
	windows[12]=glutCreateWindow("Controls!");
	initControlMenu();
	glutDisplayFunc(extraControls);
}

void quadMenu(){
	glutInitWindowSize(mWidth, mHeight);
    glutInitWindowPosition(100, 20);

	windows[0]=glutCreateWindow("The Mighty Pong!");
    initQuadMenu();
    glutDisplayFunc(emptyDisplay);

	glutInitWindowSize(mWidth/2, mHeight/4);
    glutInitWindowPosition(1200, 20);
	windows[12]=glutCreateWindow("Controls!");
	initControlMenu();
	glutDisplayFunc(menuControls);
	

	windows[1]=glutCreateSubWindow(windows[0],-mWidth/2,-mWidth/2,mWidth/2,mWidth/2);
	initQuadMenu();
	glutDisplayFunc(quadMenuDisplay);
	glutCreateMenu(gameMenu);
	glutAddMenuEntry("Classic",0);
	glutAddMenuEntry("Doubles",1);
	glutAddMenuEntry("3-way",2);
	glutAddMenuEntry("Quad",3);
	glutAttachMenu(0);

	windows[2]=glutCreateSubWindow(windows[0],mWidth/2,-mWidth/2,mWidth/2,mWidth/2);
	initQuadMenu();
	glutDisplayFunc(quadMenuDisplay);
	glutMouseFunc(cubeWindow);

	windows[3]=glutCreateSubWindow(windows[0],-mWidth/2,mWidth/2,mWidth/2,mWidth/2);
	initQuadMenu();
	glutDisplayFunc(quadMenuDisplay);
	glutMouseFunc(codeWindow);
	
	windows[4]=glutCreateSubWindow(windows[0],mWidth/2,mWidth/2,mWidth/2,mWidth/2);
	initQuadMenu();
	glutDisplayFunc(quadMenuDisplay);
	glutCreateMenu(exitMenu);
	glutAddMenuEntry("Exit",0);
	glutAddMenuEntry("Return to program",1);
	glutAttachMenu(0);

}