#include <iostream>
#include <string>
#include "drawFunc.h"
#include "windows.h"
#include "menus.h"
using namespace std;

extern int mWidth, mHeight;
extern int windows[15];

void rotateCube(unsigned char key, int x, int y){}
void closeQuadMenu(){
	glutDestroyWindow(windows[4]);
	//cout<<"closed quad4\n";
	glutDestroyWindow(windows[3]);
	//cout<<"closed quad3\n";
	glutDestroyWindow(windows[2]);
	//cout<<"closed quad2\n";
	glutDestroyWindow(windows[1]);
	//cout<<"closed quad1\n";
	glutDestroyWindow(windows[0]);
	//cout<<"closed quad0\n";
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
}
void threeWayGUI(){
	windows[7]=glutCreateSubWindow(windows[6],0,0,mWidth/4, 40);
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
}

void quadMenu(){
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