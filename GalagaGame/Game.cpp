#include "Game.h"
#include <conio2.h>
Game::Game() {
		using namespace std;
	const int ancho=27;
	const int alto=12;
	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
	cout<<"teclas de movimiento: flechas"<<endl;
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
	player->clear();
	enemigo->clear();
	meteorito->clear();
	
}

void Game::draw()
{	
	player->draw();
	enemigo->draw();
	meteorito->draw();
}

void Game::progressInput()
{
  
	if(kbhit())
	{
		int input=getch();
		
		switch(input)
		{
		case 12:
			isOpen=false;
			break;
			
		}
		
	}
	player->inputProgress();
	
}

void Game::update()
{
	player->update();
	enemigo->update();
	meteorito->update();
	
	if(player->colicionConEnemigo(*enemigo))
	{
		player->perderVida();
	}
	if(player->getvida()<=0)
	{
		isOpen=false;
	}
	
	if(player->colicionConMeteorito(*meteorito))
	{
		player->perderVida();
	}
	if(player->getvida()<=0)
	{
		isOpen=false;
	}
}

void Game::run()
{
	
	player=new Player();
	enemigo=new Enemigo();
	meteorito=new Meteorito();
	
	while(isOpen)
	{
		clear();
		progressInput();
		update();
		draw();
		player->mostrarvida();
		Sleep(20);
	}
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
}
