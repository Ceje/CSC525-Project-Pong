#include "timers.h"

using namespace std;

extern float cubeR;
extern int windows[];
extern int textPos[];
extern int codePos[];
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
		glutTimerFunc(50,textTimer,0);
	
		
	}
	
	
}

void codeTimer(int i){
	line=fillerText[codePos[1]].length();
	codePos[0]++;
	if(codePos[0]==line){
		codePos[0]=-1;
		codePos[1]++;
		if(codePos[1]==lnCount){
			//getnextsetoflines();
		}
		else{
			glutSetWindow(windows[6]);
			codeDisplay();
			glutTimerFunc(50,codeTimer,0);
		}
	}
	else{
		glutSetWindow(windows[6]);
		codeDisplay();
		glutTimerFunc(50,codeTimer,0);
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
	int infoCubeTurner=abs(infoCubeAngle[0]);
	
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
		/*for(int i=0; i<4;i++){
		cout<<"Angle "<<i <<": "<<infoCubeAngle[i]<<"\n";
		}*/
		infoCubeTurning=false;
	}
}

void pongTimer(int i)
{
	if(activeWindow == windows[6])
	{
		glutSetWindow(windows[6]);
		g1.play();
		classic();
		//std::cout << "pong" << std::endl;
		glutSetWindow(windows[7]);
		playerMenuDisplay();
		glutSetWindow(windows[8]);
		playerMenuDisplay();
		
		glutTimerFunc(10, pongTimer, 0);
	}
	else
		std::cout << "Current: " << activeWindow << "Desired: " << windows[6] << std::endl;
}
