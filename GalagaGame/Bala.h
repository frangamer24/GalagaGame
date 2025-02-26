#ifndef BALA_H
#define BALA_H
#include "entity.h"

class Bala : public Entity {
public:
	Bala(int x, int y);
	void update ( ) override;
	void draw ( ) override;
	void clear ( ) override;
	bool isOffScreen();
	
	int GetX();
	int GetY();
private:
	
	bool active;
};

#endif

