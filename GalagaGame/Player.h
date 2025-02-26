#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include "Entity.h"
#include "Enemigo.h"
#include "Meteorito.h"
#include "Bala.h"

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
	std::vector<Bala> balas;  
	
};

#endif

