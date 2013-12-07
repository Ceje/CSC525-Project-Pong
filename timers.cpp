#include "timers.h"

using namespace std;

extern float cubeR;
extern int windows[];
extern int textPos[];
extern int line;
extern int lnCount;
extern float exitR;
extern string fillerText[];
extern float infoCubeAngle[];
extern int infoCubeRot;
extern float infoCubeOld[];
extern bool infoCubeNegative;
extern bool infoCubeTurned;
extern bool infoCubeTurning;
extern int activeWindow;
extern Pong g1;


void cubeTimer(int i){
	
	
	if(activeWindow==0){//stomps warnings for bogus windows
		cubeR++;
		if(cubeR==360){
			cubeR=-1;
		}
		glutSetWindow(windows[2]);
		quadMenuDisplay();
		glutTimerFunc(25,cubeTimer,0);
	}
	
	
}

void textTimer(int i){
	
	
	if(activeWindow==0){//stomps warnings for bogus windows
		line=fillerText[textPos[1]].length();
		textPos[0]++;
		if(textPos[0]==line){
			textPos[0]=-1;
			textPos[1]++;
			if(textPos[1]==lnCount){
				textPos[1]=0;
			}
		}
		glutSetWindow(windows[3]);
		quadMenuDisplay();
		glutTimerFunc(1000,textTimer,0);
	}
	
	
}

void wordSpinTimer(int i){
	
	
	if(activeWindow==0){//stomps warnings for bogus windows
		exitR++;
		if(exitR==360){
			exitR=-1;
		}
		glutSetWindow(windows[4]);
		quadMenuDisplay();
		glutTimerFunc(25,wordSpinTimer,0);
	}
	
	
}

void infoCubeTurn(int i){
	if(infoCubeTurned&&infoCubeRot==1){
		infoCubeRot++;
		infoCubeNegative=!infoCubeNegative;
	}
	if(infoCubeNegative){
		infoCubeAngle[infoCubeRot]--;
	}
	else{
		infoCubeAngle[infoCubeRot]++;
	}
	glutSetWindow(windows[6]);
	drawInfoCube();
	if(abs(infoCubeAngle[infoCubeRot]-infoCubeOld[infoCubeRot])<90){
		glutSetWindow(windows[6]);
		glutTimerFunc(10,infoCubeTurn,0);
	}
	else{
		infoCubeTurning=false;
	}
}

void pongTimer(int i)
{
	if(activeWindow == windows[6])
	{
		g1.play();
		classic();
		//std::cout << "pong" << std::endl;
		glutSetWindow(windows[7]);
		playerMenuDisplay();
		glutSetWindow(windows[8]);
		playerMenuDisplay();
		glutSetWindow(windows[6]);
		glutTimerFunc(10, pongTimer, 0);
	}
	else
		std::cout << "Current: " << activeWindow << "Desired: " << windows[6] << std::endl;
}
