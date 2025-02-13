#include "Game.h"

Game::Game() {
	
}

void Game::clear()
{
	
}

void Game::draw()
{
	
}

void Game::progressImput()
{
	
	if(kbhit())
	{
		int imput=getch();
		
		switch(imput)
		{
		case 27:
			isOpen=false;
			break;
		}
	}
	
}

void Game::update()
{
	
}

void Game::run()
{
	while(isOpen)
	{
		clear();
		progressImput();
		update();
		draw();
	}
}
