#include "Player.h"
#include <iostream>

Player::Player() {
	position.x = 12;
	position.y = 14;
	vida = 5;
	puntaje = 0;
	invulnerable = false;
	tiempoInvulnerabilidad = 0;
	
	for (int i = 0; i < MAX_BALAS; i++) {
		balasActivas[i] = false;
	}
}

void Player::clear() {
	gotoxy(position.x, position.y);
	std::cout << " ";
	
	for (int i = 0; i < MAX_BALAS; i++) {
		if (balasActivas[i]) {
			balas[i].clear();
		}
	}
}

void Player::draw() {
	gotoxy(position.x, position.y);
	std::cout << "A";
}

void Player::update() {
	manejarBalas();
	if (invulnerable) {
		tiempoInvulnerabilidad--;
		if (tiempoInvulnerabilidad <= 0) {
			invulnerable = false;
		}
	}
}

void Player::disparar() {
	for (int i = 0; i < MAX_BALAS; i++) {
		if (!balasActivas[i]) {
			balas[i] = Bala(position.x, position.y - 1);
			balasActivas[i] = true;
			break;
		}
	}
}

void Player::manejarBalas() {
	for (int i = 0; i < MAX_BALAS; i++) {
		if (balasActivas[i]) {
			balas[i].clear();
			balas[i].update();
			if (balas[i].isOffScreen()) {
				balasActivas[i] = false;
			} else {
				balas[i].draw();
			}
		}
	}
}

int Player::getvida() {
	return vida;
}

void Player::mostrarvida() {
	gotoxy(30, 6);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
	std::cout << "vida: (" << vida << ")";
	SetConsoleTextAttribute(hConsole, 7);
}

void Player::mostrarPuntaje() {
	gotoxy(30, 5);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
	std::cout << "Puntaje: " << puntaje << " ";
	SetConsoleTextAttribute(hConsole, 7);
}

void Player::perderVida() {
	if (!invulnerable) {
		vida--;
		mostrarvida();
		invulnerable = true;
		tiempoInvulnerabilidad = 10;
	}
	if (vida <= 0) {
		gotoxy(10, 10);
		std::cout << "GAME OVER";
	}
}

bool Player::colicionConEnemigo(Enemigo enemigo) {
	return (position.x == enemigo.GetX() && position.y == enemigo.GetY());
}

void Player::colicionBalaEnemigo(Enemigo &enemigo) {
	for (int i = 0; i < MAX_BALAS; i++) {
		if (balasActivas[i] && balas[i].GetX() == enemigo.GetX() && balas[i].GetY() == enemigo.GetY()) {
			balasActivas[i] = false;
			enemigo.resetPosition();
			puntaje += 10;
			mostrarPuntaje();
			break;
		}
	}
}

bool Player::colicionConMeteorito(Meteorito meteorito) {
	return (position.x == meteorito.GetX() && position.y == meteorito.GetY());
}

void Player::inputProgress(int input) {
	const int LimiteIzquierdo = 2;
	const int LimiteDerecho = 25;
	const int LimiteArriba = 6;
	const int LimiteAbajo = 15;
	
	switch (input) {
	case 87:
	case 119:
		if (position.y > LimiteArriba) position.y -= 1;
		break;
	case 83:
	case 115:
		if (position.y < LimiteAbajo) position.y += 1;
		break;
	case 65:
	case 97:
		if (position.x > LimiteIzquierdo) position.x -= 1;
		break;
	case 68:
	case 100:
		if (position.x < LimiteDerecho) position.x += 1;
		break;
	case 32:
		disparar();
		break;
	default:
		break;
	}
}
