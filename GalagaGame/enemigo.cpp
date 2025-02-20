#include "enemigo.h"
#include <iostream>

using namespace std; 
Enemigo::Enemigo(){
	
	pocition.x=2;
	pocition.y=5;
	direction=1;
}
void Enemigo::update() {
	
	if(pocition.x>=24)
	{
		direction = -1;
	}
	if(pocition.x<=3)
	{
		direction = 1;
	}
	
	pocition.x +=direction;
}
void Enemigo::clear() {
	
	gotoxy(pocition.x, pocition.y);
	cout<<" ";
}
void Enemigo::draw() {
	
	gotoxy(pocition.x, pocition.y);
	cout<<"X";
	
}
