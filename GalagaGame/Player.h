#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.h"
#include "Enemigo.h"
#include "Meteorito.h"

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
	void perderVida();
	void inputProgress();
	int getvida();
private:
	
	int vida;
	bool invulnerable;
	int tiempoInvulnerabilidad;
	
};

#endif

