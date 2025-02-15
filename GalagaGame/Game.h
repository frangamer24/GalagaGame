#ifndef GAME_H
#define GAME_H
#include <conio2.h>
#include <iostream>
#include <windows.h>
class Game {
public:
	Game();
	
	void run();
private:
	//atributos
	bool isOpen=true;
	
	//metodos
	void progressImput();
	void update();
	void draw();
	void clear();
};

#endif

