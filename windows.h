#ifndef _WINDOWS_H
#define _WINDOWS_H

#include <iostream>
#include <string>
#include "drawFunc.h"
#include <cmath>
#include "menus.h"
#include "timers.h"

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
void gameDestroy();
void quadMenu();
void cubeWindow(int button, int state, int x, int y);
void codeWindow(int button, int state, int x, int y);
void gameWindow(int gamemode);
void doublesGUI();
void classicGUI();
void threeWayGUI();
void quadGUI();

#endif