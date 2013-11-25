#include <iostream>
#include <string>
#include "drawFunc.h"
#include "windows.h"
#include "menus.h"
using namespace std;
extern float cubeR;
extern int windows[];
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