#include "enemigo.h"
#include <iostream>

using namespace std; 
Enemigo::Enemigo(){
	
	position.x=2;
	position.y=5;
	direction=1;
}
void Enemigo::update() {
	
	if(position.x>=26)
	{
		direction = -1;
	}
	if(position.x<=3)
	{
		direction = 1;
	}
	
	position.x +=direction;
}
void Enemigo::clear() {
	
	gotoxy(position.x, position.y);
	cout<<" ";
}
void Enemigo::draw() {
	
	gotoxy(position.x, position.y);
	cout<<"X";
	
}
int Enemigo::GetX()
{
	return position.x;
}
int Enemigo::GetY()
{
	return position.y;
}
