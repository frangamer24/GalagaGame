#ifndef ENTITY_H
#define ENTITY_H
#include <windows.h>
#include <conio2.h>
#include <iostream>

using namespace std;

struct Position
{
	int x{};
	int y{};
};

class Entity {
public:
	entity();
	virtual void update()=0;
	virtual void draw()=0;
	virtual void clear()=0;
	
	
protected:
	//atributos
	Position position;
	//metodos
	
};

#endif

