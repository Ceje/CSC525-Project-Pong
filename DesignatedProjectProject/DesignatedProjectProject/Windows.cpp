#include "windows.h"

using namespace std;

extern int mWidth, mHeight;
extern int windows[15];
extern int activeWindow;

void controlList(int i){

}
void closeQuadMenu(){
	activeWindow=1;
	for(int i=4;i>=0;i--){
		glutDestroyWindow(windows[i]);
	}
	glutSetWindow(windows[6]);
}
void codeWindow(int button, int state, int x, int y){
	glutDestroyWindow(windows[12]);
	glutInitWindowSize(mWidth*0.6, mHeight/4);
    glutInitWindowPosition(1200, 20);
	windows[12]=glutCreateWindow("Controls!");
	initControlMenu();
	glutDisplayFunc(codeControls);
	glutInitWindowSize(mWidth, mHeight);
	glutInitWindowPosition(100,20);
	windows[6]=glutCreateWindow("FREE SAMPLES!");
	initControlMenu();
	glutDisplayFunc(codeDisplay);
	glutKeyboardFunc(codeKeys);
	glutCreateMenu(exitMenu);
	glutAddMenuEntry("Exit to menu",2);
	glutAddMenuEntry("Return to program",1);
	glutAddMenuEntry("Exit",0);
	glutAttachMenu(0);
	closeQuadMenu();
	glutTimerFunc(500,codeTimer,0);

	
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
void playerScoreBoard(int window, int x, int y, int width, int height){
	windows[window]=glutCreateSubWindow(windows[6],x,y,width, height);
	playerMenuMenu();
	playerMenuInit();
	glutDisplayFunc(playerMenuDisplay);
}

void threeWayGUI(){
	playerScoreBoard(7,0,0,mWidth/4, 40);

	playerScoreBoard(8,(mWidth-(mWidth/4)),0,mWidth/4,40);

	playerScoreBoard(9,0,(mHeight-40),mWidth/4,40);

}
void quadGUI(){
	playerScoreBoard(7,0,0,mWidth/4, 40);

	playerScoreBoard(8,(mWidth-(mWidth/4)),0,mWidth/4,40);

	playerScoreBoard(9,0,(mHeight-40),mWidth/4,40);

	playerScoreBoard(10,(mWidth-(mWidth/4)),(mHeight-40),mWidth/4,40);
}
void classicGUI(){
	playerScoreBoard(7,0,0,mWidth/4, 40);

	playerScoreBoard(8,(mWidth-(mWidth/4)),0,mWidth/4,40);
}
void timerHUD(){
	windows[11]=glutCreateSubWindow(windows[6],mWidth/3,0,mWidth/3,80);
	playerMenuInit();
	glutDisplayFunc(timerDisplay);
}

void gameWindow(int gamemode){

	glutDestroyWindow(windows[12]);
	glutInitWindowSize(mWidth*3/4, mHeight/4);
    glutInitWindowPosition(1100, 20);
	windows[12]=glutCreateWindow("Controls!");
	initControlMenu();
	glutDisplayFunc(gameControls);

	glutInitWindowSize(mWidth, mHeight);
	glutInitWindowPosition(100,20);
	windows[6]=glutCreateWindow("PLAYBALL!");
	initPong();
	
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
	glutKeyboardFunc(handleKeypress);
	glutKeyboardUpFunc(handleKeyUp);
	closeQuadMenu();
	glutSetWindow(windows[6]);
	activeWindow = windows[6];
	//std::cout << "pretimer" << std::endl;
	glutTimerFunc(10, pongTimer, 0);
	//std::cout << "posttimer" << std::endl;
}

void gameDestroy(){
		for(int i=11;i>5;i--){
			glutDestroyWindow(windows[i]);
		}
		glutSetWindow(windows[0]);
}
void cubeWindow(int button, int state, int x, int y){
	glutDestroyWindow(windows[12]);
	glutInitWindowSize(mWidth/2, mHeight/4);
    glutInitWindowPosition(1200, 20);
	windows[12]=glutCreateWindow("Controls!");
	initControlMenu();
	glutDisplayFunc(cubeControls);

	//cout<<"initializing cube\n";
    glutInitWindowSize(mWidth, mHeight);
    glutInitWindowPosition(100, 20);
	//cout<<"building cube\n";
	windows[6]=glutCreateWindow("THE CUBE OF INFORMATION!");
	initInfoCube();
	glutDisplayFunc(drawInfoCube);
	//cout<<"cube menu\n";
	glutCreateMenu(exitMenu);
	glutAddMenuEntry("Exit to menu",2);
	glutAddMenuEntry("Return to program",1);
	glutAddMenuEntry("Exit",0);
	glutAttachMenu(0);
	glutKeyboardFunc(infoCubeKeys);
	closeQuadMenu();

	glutSetWindow(windows[6]);
}
void pongWindow(int button, int state, int x, int y){
	gameWindow(0);
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
	glutMouseFunc(pongWindow);

	windows[2]=glutCreateSubWindow(windows[0],mWidth/2,-mWidth/2,mWidth/2,mWidth/2);
	initQuadMenu();
	glutDisplayFunc(quadMenuDisplay);
	glutMouseFunc(cubeWindow);
	glutTimerFunc(4,cubeTimer,0);

	windows[3]=glutCreateSubWindow(windows[0],-mWidth/2,mWidth/2,mWidth/2,mWidth/2);
	initQuadMenu();
	glutDisplayFunc(quadMenuDisplay);
	glutMouseFunc(codeWindow);
	glutTimerFunc(500,textTimer,0);
	
	windows[4]=glutCreateSubWindow(windows[0],mWidth/2,mWidth/2,mWidth/2,mWidth/2);
	initQuadMenu();
	glutDisplayFunc(quadMenuDisplay);
	glutCreateMenu(exitMenu);
	glutAddMenuEntry("Exit",0);
	glutAddMenuEntry("Return to program",1);
	glutAttachMenu(0);
	glutTimerFunc(4,wordSpinTimer,0);
	
	activeWindow=0;

}