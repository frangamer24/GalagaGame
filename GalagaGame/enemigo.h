#ifndef ENEMIGO_H
#define ENEMIGO_H
#include "Entity.h"
#include <conio2.h>

class Enemigo : public Entity {
public:
	Enemigo();
	void update();
	void draw();
	void clear();
	void resetPosition();
	
	int GetX();
	int GetY();
private:
	
	int direction;
};

#endif

