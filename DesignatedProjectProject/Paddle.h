#ifndef _PADDLE_H
#define _PADDLE_H


class Paddle
{
	int pX;
	int pY;
	int initY;
	int pLen;
	int bound;
	bool uMot;
	bool dMot;

	public:
		//Paddle();
		Paddle(int x=0, int y=0, int b=0, int l=50);
		void move(int in);
		void moveY(int val);
		void start(char dir);
		void stop(char dir);
		void reset();
		bool uMotion();
		bool dMotion();
		int getX();
		void setX(int x);
		int getY();
		void setY(int y);
		void setBound(int b);
		int getL();
		void setL(int l);
};
#endif
