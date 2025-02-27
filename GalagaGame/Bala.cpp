#include "Bala.h"
#include <iostream>

Bala::Bala() {
	position.x=0;
	position.y=0;
	active = false;
}
Bala::Bala(int x, int y) 
{  
	position.x = x;
	position.y = y;
	active = true;
}
void Bala::update ( ) 
{
	position.y--;
}
void Bala::draw() 
{
	if(active)
	{
		gotoxy(position.x,position.y);
		cout<<"|";
	}
}

void Bala::clear ( ) 
{
	gotoxy(position.x,position.y);
	cout<<" ";
}
bool Bala::isOffScreen() {
	return position.y < 6; 
}
int Bala::GetX()
{
	return position.x;
}
int Bala::GetY()
{
	return position.y;
}
