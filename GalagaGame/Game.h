#ifndef GAME_H
#define GAME_H
#include <conio2.h>
#include <iostream>
#include <windows.h>
#include "entity.h"
#include "Enemigo.h"
#include "player.h"

class Game {
public:
	Game();
	
	void run();
private:
	//atributos
	bool isOpen=true;
	Player* player;
	Enemigo* enemigo;
	
	//metodos	
	void clear();
	void progressInput();
	void update();
	void draw();

};

#endif

