#include "Pong.h"

//Work out ball paddle interaction bugs
//Work on clock time
//Stop being lazy!
//Make accessors and mutators for objects (make paddles and ball private again) not very feasable
//add functionality for 4 player version
//Basic AI for single player and demo purposes

Pong::Pong()
{
    p1 = Paddle();
    p2 = Paddle();
    b1 = Ball();
    xBound = 640;
    yBound = 480;
}

Pong::Pong(int xB, int yB)
{
	xBound = xB;
	yBound = yB;
	clock = 40;
	ticks = 0;
	p1 = Paddle((-xBound/2)+30, 0, yBound/6, yBound, 4, 0, 0);
	p2 = Paddle((xBound/2)-30, 0, yBound/6, yBound, 4, 0, 0);
	b1 = Ball(0, 0, xBound, yBound, yBound/100);
}

Pong::Pong(Paddle in1, Paddle in2, Ball bin1, int xB, int yB)
{
    p1 = in1;
    p2 = in2;
    b1 = bin1;
    clock = 0;
    xBound = xB;
    yBound = yB;
}

Paddle Pong::getPaddle(std::string st)
{
    if(st == "p1")
	return p1;
    else if(st == "p2")
	return p2;
    else
	return NULL;
}

int Pong::getTime()
{
	return clock;
}

void Pong::clockTick()
{
	ticks++;

	if(ticks % 100 == 0)
	{
		clock --;
	}
}


void Pong::play()
{
    p1.move();
    p2.move();

    if(b1.getSpeed() == 0)
    {
	p1.reset();
	p2.reset();
    }

    if(b1.getX()-b1.getRad() <= p1.getX() && b1.getY()-b1.getRad() < p1.getY()+p1.getL()/2 && b1.getY()+b1.getRad() > p1.getY()-p1.getL()/2)
    {
	b1.changeDir('x');
    }

	//if(b1.getX()-b1.getRad()/2 <= p1.getX() && b1.getY()-b1.getRad() 

    if(b1.getX()+b1.getRad() >= p2.getX() && b1.getY()-b1.getRad() < p2.getY()+p2.getL()/2 && b1.getY()+b1.getRad() > p2.getY()-p2.getL()/2)
    {
	b1.changeDir('x');
    }

	if(b1.getX() <= -xBound/2)
	{
		p2.goal();
		b1.reset();
		std::cout << "Player 2: " << p2.getScore() << std::endl;
	}

	if(b1.getX() >= xBound/2)
	{
		p1.goal();
		b1.reset();
		std::cout << "Player 1: " << p1.getScore() << std::endl;
	}

    b1.move();
}
