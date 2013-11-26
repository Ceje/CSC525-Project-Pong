#include <cmath>

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
void infoCubeKeys(unsigned char key, int x, int y);