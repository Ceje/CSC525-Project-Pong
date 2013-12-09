#include "menus.h"

using namespace std;


extern int cameraTop;
extern int mWidth, mHeight;
extern int windows[15];
extern int infoCubeRot;
extern float infoCubeAngle[];
extern bool infoCubeNegative;
extern float infoCubeOld[];
extern bool infoCubeTurned;
extern bool infoCubeTurning;
extern Pong g1;
extern int codePos[];
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
	if(infoCubeTurning==false){
		if(key==' '){
			changeInfoCubeView();
			glutSetWindow(windows[6]);
			drawInfoCube();
		}
		else if(key=='q'){
			rotateCameraLeft();
		}
		else if(key=='e'){
			rotateCameraRight();
		}
		else{
			cameraTop=0;
			setCubeCamera();
			infoCubeTurning=true;
			switch(key){
				case 'w':
					infoCubeRot=0;
					infoCubeNegative=false;
					break;
				case 'a':
					infoCubeRot=1;
					infoCubeNegative=false;
					break;
				case 's':
					infoCubeRot=0;
					infoCubeNegative=true;
					break;
				case 'd':
					infoCubeRot=1;
					infoCubeNegative=true;
					break;
				default:
					infoCubeRot=1;
					infoCubeNegative=false;
					break;
			}
			for(int i=0;i<4;i++){
				infoCubeAngle[i]=(int)infoCubeAngle[i]%360;
				infoCubeOld[i]=infoCubeAngle[i];
			}
			if(infoCubeRot==1){
				int ws=abs(infoCubeAngle[0]);
				int ad=abs(infoCubeAngle[1]);
				if(ws>=180){
					infoCubeNegative=!infoCubeNegative;
				}
				
				if((ws==90||ws==270)&&!(ad==90||ad==270)){
					
					if(ad>=180){
						infoCubeNegative=!infoCubeNegative;
					}
					infoCubeRot=2;
				}
			}

			//cout<<key<<"\n";
			glutTimerFunc(25,infoCubeTurn,0);
		}
	}
}

void codeKeys(unsigned char key, int x, int y){
	switch(key){
	case ' ':
		codePos[0]=-1;
		codePos[1]=0;
		fileSwitch();
	default:
		codePos[0]=-1;
		codePos[1]=0;
		nextLines();
	}
	glutTimerFunc(50,codeTimer,0);
}

void emptyKeys(unsigned char key, int x, int y){}


void handleKeyUp(unsigned char key, int x, int y)
{
    switch (key)
    {
	case 'w':
	    {
		g1.p1.setDir(0);
		break;
	    }
	case 's':
	    {
		g1.p1.setDir(0);
		break;
	    }
	case 'o':
	    {
		g1.p2.setDir(0);
		break;
	    }
	case 'l':
	    {
		g1.p2.setDir(0);
		break;
	    }
    }
}

void handleKeypress(unsigned char key, int x, int y)
{
    switch (key)
    {
	case 27: //Escape Key
	    {
		//tearDown();
		exit(0); //Exit the program
	    }
	case 'w':
	    {
		g1.p1.setDir(1);
		break;
	    }
	case 's':
	    {
		g1.p1.setDir(-1);
		break;
	    }
	case 'o':
	    {
		g1.p2.setDir(1);
		break;
	    }
	case 'l':
	    {
		g1.p2.setDir(-1);
		break;
	    }
	default:
		g1.b1.setSpeed(3);
		//std::cout << key << std::endl;
    }
    //drawScene();
}