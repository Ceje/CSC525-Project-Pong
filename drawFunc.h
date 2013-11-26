//drawFunc.h
//this file just contains the function declarations
//the implementations will be in drawFunc.cpp
#include <cmath>
#include <string>
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
void doubles();
void threeway();
void classic();
void playerMenuInit();
void playerMenuDisplay();
void timerDisplay();
void initControlMenu();
void menuControls();
void gameControls();
void extraControls();
void drawTimedText();
void drawRotatingCube();
void displayExit();
void draw3dText(float tx,float ty,float tz,float ra, float rx,float ry,float rz, float sx, float sy, float sz, std::string words, float indent);