#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.h"

class Player : public Entity 
{
public:
	Player();
	
	void draw();
	void update();
	void clear();
	
	void inputProgress();
private:
};

#endif

