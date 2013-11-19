#include "Paddle.h"
#include <iostream>

Paddle::Paddle()
{
    pX=0;
    pY=0;
    pLen=0;
	initY = 0;
	uMot=false;
	dMot=false;
}

Paddle::Paddle(int x, int y, int l)
{
	pX = x;
	pY = y;
	pLen = l;
	initY = y;
	uMot=false;
	dMot=false;
}

void Paddle::start(char dir)
{
	if(dir == 'u')
	{
		uMot=true;
	}
	else if(dir == 'd')
	{
		dMot=true;
	}
}

void Paddle::stop(char dir)
{
	if(dir == 'u')
	{
		uMot=false;
	}
	else if(dir == 'd')
	{
		dMot=false;
	}
}

void Paddle::reset()
{
	pY=initY;
}

bool Paddle::uMotion()
{
	return uMot;
}

bool Paddle::dMotion()
{
	return dMot;
}

void Paddle::moveY(int val)
{
	pY = pY + val;
	//std::cout << val <<  std::endl;
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
}

int Paddle::getL()
{
	return pLen;
}

void Paddle::setL(int l)
{
	pLen = l;
}
