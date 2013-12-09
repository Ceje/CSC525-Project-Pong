#ifndef _PROJIO_H
#define _PROJIO_H

#include <iostream>
#include <string>
#include "drawFunc.h"
#include "windows.h"
#include "menus.h"
#include <cmath>
#include "Pong.h"
#include <fstream>

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void nextLines();
void clearBuffer();
void fileSwitch();
int initCode();

#endif