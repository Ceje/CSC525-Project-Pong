#ifndef _TIMERS_H
#define _TIMERS_H

#include <iostream>
#include <string>
#include "drawFunc.h"
#include "windows.h"
#include "menus.h"
#include <cmath>
#include "Pong.h"

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void cubeTimer(int i);
void textTimer(int i);
void wordSpinTimer(int i);
void infoCubeTurn(int i);
void pongTimer(int i);
void codeTimer(int i);

#endif