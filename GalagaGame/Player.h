#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.h"
#include "Enemigo.h"
#include "Meteorito.h"
#include "Bala.h"

#define MAX_BALAS 10

class Player : public Entity 
{
public:
	Player();
	
	bool colicionConEnemigo(Enemigo enemigo);
	bool colicionConMeteorito(Meteorito meteorito);
	void draw();
	void update();
	void clear();
	void mostrarvida();
	void mostrarPuntaje();
	void perderVida();
	void inputProgress();
	void inputProgress(int input);
	int getvida();
	void disparar();
	void manejarBalas();
	void colicionBalaEnemigo(Enemigo &enemigo);
private:
	
	int vida;
	int puntaje;
	bool invulnerable;
	int tiempoInvulnerabilidad;
	Bala balas[MAX_BALAS];  
	bool balasActivas[MAX_BALAS] = {false}; // Inicializamos en falso
	
};

#endif
