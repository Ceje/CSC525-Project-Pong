//drawFunc.h
//this file just contains the function declarations
//the implementations will be in drawFunc.cpp

#ifndef _DRAWFUNC_H
#define _DRAWFUNC_H

#include <iostream>
#include <cmath>
#include <string>
#include "Pong.h"

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void initQuadMenu();
void emptyDisplay();
void quadMenuDisplay();
void quad();
void codeControls();
void codeDisplay();
void doubles();
void threeway();
void classic();
void playerMenuInit();
void playerMenuDisplay();
void timerDisplay();
void initControlMenu();
void menuControls();
void gameControls();
void cubeControls();
void drawTimedText();
void drawRotatingCube();
void displayExit();
void drawInfoCube();
void changeInfoCubeView();
void initInfoCube();
void rotateCameraRight();
void rotateCameraLeft();
void setCubeCamera();
void reshape(int w, int h);
void draw3dText(float tx,float ty,float tz,float ra, float rx,float ry,float rz, float sx, float sy, float sz, std::string words, float indent);

#endif