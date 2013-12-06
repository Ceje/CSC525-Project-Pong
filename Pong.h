#ifndef _PONG_H
#define _PONG_H

#include <string>
#include "Paddle.h"
#include "Ball.h"

class Pong
{
    //Paddle p1;
    //Paddle p2;
    Paddle p3;
    Paddle p4;
    //Ball b1;
    Ball b2;
    int clock;
    int yBound;
    int xBound;

    public:
	Paddle p1;
	Paddle p2;
	Ball b1;
	Pong();
	Pong(Paddle p1, Paddle p2, Ball b1, int xB, int yB);

	Paddle getPaddle(std::string st);
	void play();
};
#endif
