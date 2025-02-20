#include "Player.h"
#include "Entity.h"
Player::Player() {
	
	pocition.x=12;
	pocition.y=14;
}
void Player::clear()
{
	gotoxy(pocition.x,pocition.y);
	cout<<"  ";
}
void Player::draw()
{
	gotoxy(pocition.x,pocition.y);
	cout<<"[]";
}
void Player::update()
{
	
}
void Player::inputProgress()
{
	if(kbhit())
	{
		int tecla= getch();
		
		switch(tecla)
		{
		case 72:
			pocition.y-=1;
			break;
		case 80:
			pocition.y+=1;
			break;
		case 75:
			pocition.x-=1;
			break;
		case 77:
			pocition.x+=1;
			break;
		default:
			break;
		}
	}
}
