#ifndef METEORITO_H
#define METEORITO_H
#include "Entity.h"

class Meteorito : public Entity {
public:
	Meteorito();
	
	void update();
	void draw();
	void clear();
	void resetPosition();
	
	int GetX();
	int GetY();
private:
	
	int velocidad;
	int contadorCaida;
};

#endif

