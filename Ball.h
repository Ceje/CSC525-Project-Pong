#ifndef _BALL_H
#define _BALL_H
#include <stdlib.h>
#include <iostream>

class Ball
{
	int bX;
	int bY;
	int speed;
	int xBound;
	int yBound;
	int xDir;
	int yDir;

	void setDir();

	public:
		Ball();
		Ball(int x, int y, int xb, int yb);
		void moveY(int val);
		void moveX(int val);
		int getSpeed();
		void setSpeed(int s);
		int getDir(char ax);
		void changeDir(char ax);
		void reset();
		int getX();
		void setX(int x);
		int getY();
		void setY(int y);
		void setBound(int x, int y);

};
#endif
