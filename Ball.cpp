#include "Ball.h"

Ball::Ball()
{
	bX=0;
	bY=0;
	speed=0;
	xBound=0;
	yBound=0;
	xDir=0;
	yDir=0;
}

Ball::Ball(int x, int y, int xb, int yb)
{
	bX = x;
	bY = y;
	speed = 0;
	xBound = xb/2;
	yBound = yb/2;
	xDir = 0;
	yDir = 0;
	setDir();
}

void Ball::setDir()
{
	xDir = 1;
	int loop = rand() % 10 + 1;
	for( int i=0; i<loop; i++)
	{
		xDir*=-1;
	}

	yDir = 1;
	loop = rand() % 10 + 1;
	for(int i=0; i<loop; i++)
	{
		yDir*=-1;
	}
	std::cout << xDir << "::" << yDir << std::endl;
}

void Ball::setSpeed(int s)
{
	speed = s;
}

int Ball::getSpeed()
{
	return speed;
}

void Ball::reset()
{
	bX=0;
	bY=0;
	speed=0;
	setDir();
}

void Ball::moveY()
{
	if(bY <= -yBound)
	{
		yDir *= -1;
		bY += speed * yDir;
	}
	else if(bY >= yBound)
	{
		yDir *= -1;
		bY += speed * yDir;
	}
	else 
	{
		bY += speed * yDir;
	}
}

void Ball::moveX()
{
	if(bX <= -xBound || bX >= xBound)
	{
		reset();
	}
	else
	{
		bX += speed * xDir;
	}
}

void Ball::move()
{
    moveX();
    moveY();
}

int Ball::getDir(char ax)
{
	if(ax == 'x')
		return xDir;
	
	else if(ax == 'y')
		return yDir;

	else
		return -100;
}

void Ball::changeDir(char ax)
{
	if(ax == 'x')
		xDir *= -1;

	else if(ax == 'y')
		yDir *= -1;
}

int Ball::getX()
{
	return bX;
}

void Ball::setX(int x)
{
	bX = x;
}

int Ball::getY()
{
	return bY;
}

void Ball::setY(int y)
{
	bY = y;
}

void Ball::setBound(int x, int y)
{
	xBound = x/2;
	yBound = y/2;
}
