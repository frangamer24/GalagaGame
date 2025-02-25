#include "meteorito.h"
#include <cstdlib>

Meteorito::Meteorito() {
	
	position.x=rand()%24+2;
	position.y=5;
	velocidad=1;
	contadorCaida = 0;
	
}
void Meteorito::clear()
{
	gotoxy(position.x, position.y);
	cout<<" ";
}
void Meteorito::draw()
{	
	gotoxy(position.x,position.y);
	cout<<"0";
}
void Meteorito::update()
{
	contadorCaida++;
	
	if (contadorCaida >= 3) { 
		position.y += velocidad;
		contadorCaida = 0;
	}
	
	if (position.y >= 15) { 
		resetPosition();
	}
}
void Meteorito::resetPosition()
{
	position.x=rand()%24+2;
	position.y=5;
	
}
int Meteorito::GetX()
{
	return position.x;
}
int Meteorito::GetY()
{
	return position.y;
}
