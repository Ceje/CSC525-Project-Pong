#ifndef _MENUS_H
#define _MENUS_H

#include <iostream>
#include <cmath>
#include "windows.h"
#include <string>
#include "timers.h"
#include "drawFunc.h"
#include "Pong.h"
#include "projIO.h"

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void gameMenu(int i);
void exitMenu(int i);
void playerColorMenu(int i);
void playerControlMenu(int i);
void codeKeys(unsigned char key, int x, int y);
void infoCubeKeys(unsigned char key, int x, int y);
void emptyKeys(unsigned char key, int x, int y);
void handleKeypress(unsigned char key, int x, int y);
void handleKeyUp(unsigned char key, int x, int y);

#endif