#include <iostream>
#include "menus.h"
#include "windows.h"
#include <string>
using namespace std;



extern int mWidth, mHeight;
extern int windows[10];

void gameMenu(int i){
	switch(i){
	default:
		//classicGame();
		break;
	}
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