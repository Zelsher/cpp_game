#include "../inc/game.hpp"

Player::Player()
{
	enable = 0;
	hp = 80;
	stamina = 100;
	speed = 0.1f;
	mana = 100;
	left_hand = NULL;
	right_hand = NULL;
}
int Player::ACTIVATE_Player(string new_name, int new_id)
{
	id = new_id;
	name = new_name;
	enable = 1;
	//fill pos
	return (0);
}
	
int	Player::EXIST()
{
	return (enable);
}



float	Player::GET_Hp()
{
	return (hp);
}

int	Player::GET_Stamina()
{
	return (stamina);
}

float	Player::GET_Speed()
{
	return (speed);
}

float	Player::GET_Mana()
{
	return (mana);
}

Weapon	*Player::GET_Hand(int hand)
{
	if (hand == RIGHT)
		return (right_hand);
	if (hand == LEFT)
		return (left_hand);
	return (NULL);
}



void	Player::ADD_Item(Weapon *item)
{
	if (!left_hand)
		left_hand = item;
	else if (!right_hand)
		right_hand = item;
}

void	Player::SET_Dir(float x, float y)
{
	dir.x = x;
	dir.y = y;
	rot = atan2(y, x) * (180 / PI) + 90;// * (100.0f / PI);
}

void	Player::SET_Stamina(float i)
{
	if (i < 0 && stamina > 0)
		stamina += i;
	if (i > 0 && stamina < 100)
		stamina += i;
}

void	Player::SET_Mana(float i)
{
	if (i < 0 && mana > 0)
		mana += i;
	if (i > 0 && mana < 100)
		mana += i;
}

void	Player::SET_Pos(Vector2 pos)
{
		posX = pos.x;
		posY = pos.y;
}

void	Player::SET_PosX(float new_posX)
{
		posX = new_posX;
}
void	Player::SET_PosY(float new_posY)
{
	posY = new_posY;
}



void	Player::ADD_PosX(float new_posX)
{
	posX += new_posX;
}
void	Player::ADD_PosY(float new_posY)
{
	posY += new_posY;
}

float	Player::GET_PosX()
{
	return (posX);
}
float	Player::GET_PosY()
{
	return (posY);
}

float	Player::GET_Rot()
{
	return (rot);
}
string	Player::GET_Name()
{
	return (name);
}
