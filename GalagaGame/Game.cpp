#include "Game.h"

Game::Game() {
	
	using namespace std;
	
	const int ancho=27;
	const int alto=12;
	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
	cout<<"teclas de movimiento: WASD"<<endl;
	cout<<"disparar con la tecla:ESPACIO"<<endl;
	cout<<"debes disparar a las X, cuidado con los asteroides!"<<endl;
	SetConsoleTextAttribute(hConsole, 7);
	
	for(int i=0; i<alto;i++)
	{
		for(int j=0;j<ancho;j++)
		{
			if(i==0||i==alto-1||j==0||j==ancho-1){
				cout<<"#";
			}
			else{
				cout<<" ";
			}
		}
		cout<<endl;
	}
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
