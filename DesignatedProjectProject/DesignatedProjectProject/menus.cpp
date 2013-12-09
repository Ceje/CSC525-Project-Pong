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
extern int controls[];
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
void removeControl(int i){
	for(int j=0; j<4;j++){
		if(controls[j]%i==0){
			controls[j]=controls[j]/i;
			
		}
		//cout<< controls[j]<<":";
	}
	cout<<"\n";
}
void addControl(int i, int p){
	controls[i]=controls[i]*p;
	//cout<<"control "<<i<<": "<<controls[i];
}
void playerControlMenu(int i){
	int winID=glutGetWindow();
	//bare integer is player number
	//i is control mode ranges from 0 to 3 
	//i=4 reserved for custom keys
	if(winID==windows[7]){
		removeControl(2);
		addControl(i, 2);
	}
	else if(winID==windows[8]){
		removeControl(3);
		addControl(i, 3);
	}
	else if(winID=windows[9]){
		//playerControlChange(2,i);
	}
	else if(winID=windows[10]){
		//playerControlChange(3,i);
	}
	glutSetWindow(windows[12]);
	gameControls();
	glutSetWindow(windows[6]);
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

void paddleDirChange(int i, int j){
	if(i>-1){
		if(controls[i]%2==0){
			g1.p1.setDir(j);
		}
		if(controls[i]%3==0){
			g1.p2.setDir(j);
		}
	}
}

void handleKeyUp(unsigned char key, int x, int y)
{
	int i=0;
    switch (key)
    {
	case 'w':
	case 's':
	    {
			i=0;
		break;
	    }
	case 'a':
	case 'd':
	    {
		i=1;
		break;
	    }
	case 'i':
	case 'k':
	    {
		i=2;
		break;
	    }
	case 'j':
	case 'l':
	    {
		i=3;
		break;
	    }
    }
	paddleDirChange(i,0);
}


void handleKeypress(unsigned char key, int x, int y)
{
	int i=-1;
	int j=-1;
    switch (key)
    {
	case 27: //Escape Key
	    {
		//tearDown();
		exit(0); //Exit the program
	    }
	case 'w':
		j=1;
	case 's':
	    {
			i=0;
		break;
	    }
	case 'a':
		j=1;
	case 'd':
	    {
		i=1;
		break;
	    }
	case 'i':
		j=1;
	case 'k':
	    {
		i=2;
		break;
	    }
	case 'j':
		j=1;
	case 'l':
	    {
		i=3;
		break;
	    }
	default:
		g1.b1.setSpeed(3);
		//std::cout << key << std::endl;
    }
	paddleDirChange(i,j);
    //drawScene();
}