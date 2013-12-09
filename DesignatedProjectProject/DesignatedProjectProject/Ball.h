#ifndef _BALL_H
#define _BALL_H

#include <stdlib.h>
#include <iostream>
#include <string>

class Ball
{
	int bX;
	int bY;
	int speed;
	int oSpeed;
	int xBound;
	int yBound;
	int xDir;
	int yDir;
	int rad;

	void setDir();
	void moveY();
	void moveX();

	public:
		Ball();
		Ball(int x, int y, int xb, int yb, int r);
		void move();
		int getSpeed();
		void setSpeed(int s);
		int getoSpeed();
		void setoSpeed(int ospd);
		int getDir(char ax);
		void changeDir(char ax);
		void reset();
		int getX();
		void setX(int x);
		int getY();
		void setY(int y);
		void setBound(int x, int y);
		void setRad(int r);
		int getRad();
		int getVtx(std::string crn, std::string axs);

};
#endif
