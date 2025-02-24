#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.h"
#include "Enemigo.h"

class Player : public Entity 
{
public:
	Player();
	
	bool colicionConEnemigo(Enemigo enemigo);
	void draw();
	void update();
	void clear();
	void mostrarvida();
	void perderVida();
	void inputProgress();
	int getvida();
private:
	
	int vida;
	
};

#endif

