#include <iostream>
#include "menus.h"
#include "windows.h"
#include <string>
using namespace std;



extern int mWidth, mHeight;
extern int windows[15];

void gameMenu(int i){
	gameWindow(i);
}

void exitMenu(int i){
	if(i==2){
		quadMenu();
		glutDestroyWindow(windows[6]);
	}
	if(i==0){
		exit(0);
	}
}