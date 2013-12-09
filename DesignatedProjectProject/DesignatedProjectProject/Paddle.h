#ifndef _PADDLE_H
#define _PADDLE_H

#include <stdlib.h>
#include <iostream>
#include <string>

class Paddle
{
	int pX;
	int pY;
	int initY;
	int pLen;
	int bound;
	int speed;
	int dir;
	int score;
	int red;
	int green;
	int blue;

	public:
		//Paddle();
		Paddle(int x=0, int y=0, int l=50, int b=0, int s=4, int d=0, int scr=0);
		void move();
		void setSpeed(int spd);
		int getSpeed();
		void setDir(int d);
		int getDir();
		void reset();
		int getX();
		void setX(int x);
		int getY();
		void setY(int y);
		void setBound(int b);
		int getL();
		void setL(int l);
		void goal();
		int getScore();
		int getVtx(std::string crn, std::string axs);
		void setRed(int r);
		int getRed();
		void setGreen(int g);
		int getGreen();
		void setBlue(int b);
		int getBlue();
};
#endif
