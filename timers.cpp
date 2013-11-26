#include <iostream>
#include <string>
#include "drawFunc.h"
#include "windows.h"
#include "menus.h"
using namespace std;
extern float cubeR;
extern int windows[];
extern int textPos[];
extern int line;
extern int lnCount;
extern float exitR;
extern string fillerText[];
extern float infoCubeR[];

void cubeTimer(int i){
	cubeR++;
	if(cubeR==360){
		cubeR=-1;
	}
	if(glutGetWindow()<7&&glutGetWindow()>1){//stomps warnings for bogus windows
		glutSetWindow(windows[2]);
	}
	quadMenuDisplay();
	glutTimerFunc(25,cubeTimer,0);
}

void textTimer(int i){
	line=fillerText[textPos[1]].length();
	textPos[0]++;
	if(textPos[0]==line){
		textPos[0]=-1;
		textPos[1]++;
		if(textPos[1]==lnCount){
			textPos[1]=0;
		}
	}
	if(glutGetWindow()<7&&glutGetWindow()>2){//stomps warnings for bogus windows
		glutSetWindow(windows[3]);
	}
	quadMenuDisplay();
	glutTimerFunc(1000,textTimer,0);
}

void wordSpinTimer(int i){
	exitR++;
	if(exitR==360){
		exitR=-1;
	}
	if(glutGetWindow()<7&&glutGetWindow()>3){//stomps warnings for bogus windows
		glutSetWindow(windows[4]);
	}
	quadMenuDisplay();
	glutTimerFunc(25,wordSpinTimer,0);
}

void infoCubeTurn(int i){
	infoCubeR[0]++;
	glutSetWindow(windows[6]);
	glutKeyboardFunc(NULL);
	drawInfoCube();
	if(infoCubeR[0]<90){
		glutTimerFunc(25,infoCubeTurn,0);
		glutKeyboardFunc(infoCubeKeys);
	}
}
	