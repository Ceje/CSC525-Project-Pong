//drawFunc.h
//this file just contains the function declarations
//the implementations will be in drawFunc.cpp
#include <cmath>

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void initQuadMenu();
void emptyDisplay();
void quadMenuDisplay();
