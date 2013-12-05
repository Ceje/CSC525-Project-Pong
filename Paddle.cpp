#include "Paddle.h"
#include <iostream>

// Need to do vertex math interally and include accessors

Paddle::Paddle(int x, int y, int l, int b, int s, int d, int scr)
{
	pX = x;
	pY = y;
	bound = b;
	pLen = l;
	initY = y;
	speed = s;
	dir = d;
	score = scr;
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

void Paddle::goal()
{
    score++;
}

int Paddle::getScore()
{
    return score;
}

int Paddle::getVtx(std::string crn, std::string axs)
{
    if(crn == "ft")
    {
	if(axs == "x")
	    return pX;
	else if(axs == "y")
	    return pY+pLen/2;
    }
    else if(crn == "fb")
    {
        if(axs == "x")
	    return pX;
	else if(axs == "y")
	    return pY-pLen/2;
    }
    else if(crn == "bt")
    {
	if(axs == "x" && pX < 0)
	    return pX-20;
	else if(axs == "x" && pX > 0)
	    return pX+20;
	else if(axs == "y")
	    return pY+pLen/2;
    }
    else if(crn == "bb")
    {
	if(axs == "x" && pX < 0)
	    return pX-20;
	else if(axs == "x" && pX > 0)
	    return pX + 20;
	else if(axs == "y")
	    return pY-pLen/2;
    }
    
    return -1;
}
