#include "Player.h"
#include "Entity.h"
Player::Player() {
	
	position.x=12;
	position.y=14;
	vida=5;
	puntaje=0;
	invulnerable = false;
	tiempoInvulnerabilidad = 0;
}
void Player::clear()
{
	gotoxy(position.x,position.y);
	cout<<" ";

	for (auto& bala : balas) {
		bala.clear();
	}
}
void Player::draw()
{
	gotoxy(position.x,position.y);
	cout<<"A";
	
	
}
void Player::update()
{
	manejarBalas();
	
	if (invulnerable) {
		tiempoInvulnerabilidad--;
		if (tiempoInvulnerabilidad <= 0) {
			invulnerable = false;
		}
	}
}
void Player::disparar() {
	balas.push_back(Bala(position.x, position.y - 1)); 
}
void Player::manejarBalas() {
	for (size_t i = 0; i < balas.size(); i++) {
		balas[i].clear();
		balas[i].update();
		if (balas[i].isOffScreen()) {
			balas.erase(balas.begin() + i); 
			i--; 
		} else {
			balas[i].draw();
		}
	}
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
void Player::mostrarPuntaje() {
	
	gotoxy(30, 5);
	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
	
	std::cout << "Puntaje: " << puntaje << " ";
	
	SetConsoleTextAttribute(hConsole, 7);
}
void Player::perderVida()
{
	if (!invulnerable) { 
		vida--;
		mostrarvida();
		invulnerable = true; 
		tiempoInvulnerabilidad = 10; 
	}
	
	if(vida<=0)
	{
		gotoxy(10,10);
		cout<<"GAME OVER";
		

	}
	
}
bool Player ::colicionConEnemigo(Enemigo enemigo)
{
	return (position.x==enemigo.GetX()&&position.y==enemigo.GetY());
}
void Player::colicionBalaEnemigo(Enemigo &enemigo) {
	for (size_t i = 0; i < balas.size(); i++) {
		if (balas[i].GetX() == enemigo.GetX() && balas[i].GetY() == enemigo.GetY()) {
			balas.erase(balas.begin() + i); 
			enemigo.resetPosition(); 
			puntaje += 10; 
			mostrarPuntaje();
			break; 
		}
	}
}
bool Player::colicionConMeteorito(Meteorito meteorito)
{
	return (position.x==meteorito.GetX()&&position.y==meteorito.GetY());
}

void Player::inputProgress(int input)
{
	
	const int LimiteIzquierdo = 2;
	const int LimiteDerecho = 25;
	const int LimiteArriba = 5;
	const int LimiteAbajo = 14;
	
	switch (input) {
	case 87: 
		if (position.y > LimiteArriba)
		{
			position.y -= 1;
		}
	case 119: 
		if (position.y > LimiteArriba)
		{
			position.y -= 1;
		}
		break;
	case 83: 
		if (position.y < LimiteAbajo)
		{
			position.y += 1;
		} 
	case 115: 
		if (position.y < LimiteAbajo)
		{
			position.y += 1;
		} 
		break;
	case 65: 
		if (position.x > LimiteIzquierdo)
		{
			position.x -= 1;
		} 
	case 97: 
		if (position.x > LimiteIzquierdo)
		{
			position.x -= 1;
		} 
		break;
	case 68: 
		if (position.x < LimiteDerecho)
		{
			position.x += 1;
		}
	case 100: 
		if (position.x < LimiteDerecho)
		{
			position.x += 1;
		}
		break;
	case 32:
		disparar();
		break;
	default:
		break;
	}
}
