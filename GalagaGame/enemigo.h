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
	
private:
	
	int direction;
};

#endif

