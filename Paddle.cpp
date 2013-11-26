#include "Paddle.h"
#include <iostream>

Paddle::Paddle(int x, int y, int b, int l)
{
	// Need to make this center instead of top corner.
	pX = x;
	pY = y;
	bound = b;
	pLen = l;
	initY = y;
	speed = 4;
	dir = 0;
}

void Paddle::reset()
{
	pY=initY;
}

void Paddle::move()
{
	if(pY >= -bound && dir < 0)
	{
		pY += speed * dir;
	}
	else if(pY <= bound && dir > 0)
	{
		pY += speed * dir;
	}
}

int Paddle::getDir()
{
    return dir;
}

void Paddle::setDir(int d)
{
    if (d < 0)
    {
	dir = -1;
    }
    else if(d > 0)
    {
	dir = 1;
    }
    else 
	dir = 0;
}

int Paddle::getSpeed()
{
    return speed;
}

void Paddle::setSpeed(int spd)
{
    speed = spd;
}

int Paddle::getX()
{
	return pX;
}

void Paddle::setX(int x)
{
	pX = x;
}

int Paddle::getY()
{
	return pY;
}

void Paddle::setY(int y)
{
	pY = y;
	initY = y;
}

void Paddle::setBound(int b)
{
	bound = b/2;
}

int Paddle::getL()
{
	return pLen;
}

void Paddle::setL(int l)
{
	pLen = l;
}
