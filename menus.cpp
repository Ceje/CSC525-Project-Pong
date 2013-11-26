#include <iostream>
#include "menus.h"
#include "windows.h"
#include <string>
#include "timers.h"
using namespace std;



extern int mWidth, mHeight;
extern int windows[15];
extern float infoCubeR[];

void gameMenu(int i){
	gameWindow(i);
}
void playerColorMenu(int i){
	int winID=glutGetWindow();
	float color[3];
	switch(i){
	case 0:
		color[0]=0;
		color[1]=0;
		color[2]=0;
		break;
	case 1:
		color[0]=1;
		color[1]=1;
		color[2]=1;
		break;
	case 2:
		color[0]=1;
		color[1]=0;
		color[2]=0;
		break;
	case 3:
		color[0]=0;
		color[1]=1;
		color[2]=0;
		break;
	case 4:
		color[0]=0;
		color[1]=0;
		color[2]=1;
		break;
	case 5:
		//getCustomColor
		break;
	}
	if(winID=windows[7]){
		//playerColor[0]=color;
	}
	if(winID=windows[8]){
		//playerColor[1]=color;
	}
	if(winID=windows[9]){
		//playerColor[2]=color;
	}
	if(winID=windows[10]){
		//playerColor[3]=color;
	}
}

void exitMenu(int i){
	if(i==3){
		glutDestroyWindow(windows[12]);
		quadMenu();
		gameDestroy();
	}
	else if(i==2){
		glutDestroyWindow(windows[12]);
		quadMenu();
		glutDestroyWindow(windows[6]);
		glutSetWindow(windows[0]);
	}
	else if(i==0){
		exit(0);
	}
}

void playerControlMenu(int i){
	int winID=glutGetWindow();
	//bare integer is player number
	//i is control mode ranges from 0 to 3 
	//i=4 reserved for custom keys
	if(winID=windows[7]){
		//playerControlChange(0,i)
	}
	if(winID=windows[8]){
		//playerControlChange(1,i);
	}
	if(winID=windows[9]){
		//playerControlChange(2,i);
	}
	if(winID=windows[10]){
		//playerControlChange(3,i);
	}
}

void infoCubeKeys(unsigned char key, int x, int y){
	switch(key){
		case 'w':
			infoCubeR[1]=1;
			infoCubeR[2]=0;
			infoCubeR[3]=0;
			break;
		case 'a':
			infoCubeR[1]=0;
			infoCubeR[2]=-1;
			infoCubeR[3]=0;
			break;
		case 's':
			infoCubeR[1]=-1;
			infoCubeR[2]=0;
			infoCubeR[3]=0;
			break;
		case 'd':
			infoCubeR[1]=0;
			infoCubeR[2]=1;
			infoCubeR[3]=0;
			break;
		default:
			infoCubeR[1]=0;
			infoCubeR[2]=0;
			infoCubeR[3]=0;
			break;
	}
	infoCubeR[0]=0;
	glutTimerFunc(25,infoCubeTurn,0);
}