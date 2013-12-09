#include "projIO.h"

using namespace std;
extern fstream file;
extern string openFile;
extern string codeText[];
extern int fileNum;
void nextLines(){
	if(file.eof()==0){
		clearBuffer();
		for(int i=0;i<30;i++){
			if(file.eof()==0){
				getline(file,codeText[i]);
			}
		}
	}
	else{
		fileSwitch();
	}
}

void fileSwitch(){
	file.close();
	fileNum++;
	if(fileNum>3){
		fileNum=0;
	}
	switch(fileNum){
	case 0:
		openFile="menus.cpp";
		break;
	case 1:
		openFile="drawFunc.cpp";
		break;
	case 2:
		openFile="Ball.cpp";
		break;
	case 3:
		openFile="Paddle.cpp";
	}
	clearBuffer();
	initCode();
}

void clearBuffer(){
	for(int i=0; i<30;i++){
		codeText[i]=" ";
	}
}

int initCode(){
	file.open (openFile);

    if(file.is_open())
    {
		nextLines();
		return 0;	
    }
    else
    {
		cout<<"well shnitzle";
		return 1; // denotes failure to open file.
    }

}