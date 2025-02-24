#include "Player.h"
#include "Entity.h"
Player::Player() {
	
	position.x=12;
	position.y=14;
	vida=5;
}
void Player::clear()
{
	gotoxy(position.x,position.y);
	cout<<"  ";
}
void Player::draw()
{
	gotoxy(position.x,position.y);
	cout<<"[]";
	
}
void Player::update()
{
	
}
int Player::getvida()
{
	return vida;
}
void Player::mostrarvida()
{
	gotoxy(30,6);
	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
	
	cout<<"vida: ";
	cout<<"("<< vida<<")";
	
	SetConsoleTextAttribute(hConsole, 7);
}
void Player::perderVida()
{
	if(vida>0)
	{
		vida--;
		mostrarvida();
	}
	
	
	if(vida<=0)
	{
		gotoxy(10,10);
		cout<<"game over";
		

	}
	
}
bool Player ::colicionConEnemigo(Enemigo enemigo)
{
	return (position.x==enemigo.GetX()&&position.y==enemigo.GetY());
}
void Player::inputProgress()
{
	if (kbhit()) {
		int tecla = getch();
		
		gotoxy(100, 20);
		std::cout << "     ";
		
		gotoxy(100, 20);
		std::cout << position.y;
		
		
		const int LimiteIzquierdo = 2;
		const int LimiteDerecho = 25;
		const int LimiteArriba = 5;
		const int LimiteAbajo = 14;
		
		switch (tecla) {
		case 72: 
			if (position.y > LimiteArriba) 
				position.y -= 1;
			break;
		case 80: 
			if (position.y < LimiteAbajo) 
				position.y += 1;
			break;
		case 75: 
			if (position.x > LimiteIzquierdo) 
				position.x -= 1;
			break;
		case 77: 
			if (position.x < LimiteDerecho) 
				position.x += 1;
			break;
		default:
			break;
		}
	}
}
