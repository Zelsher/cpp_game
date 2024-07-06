#include "../../inc/game.hpp"

void	Player::SET_Dir(float x, float y)
{
	dir.x = x;
	dir.y = y;
	rot = 1;
	rot = atan2(y, x) * (180 / PI) + 90;// * (100.0f / PI);f
}

void	Player::ADD_Stamina(float i)
{
	if (i < 0 && stamina.GET_Value() > 0)
		stamina.ADD_Value(i);
	if (i > 0 && stamina.GET_Value() < 100)
		stamina.ADD_Value(i);
}

void	Player::ADD_Mana(float i)
{
	if (i < 0 && mana.GET_Value() > 0)
		mana.ADD_Value(i);
	if (i > 0 && mana.GET_Value() < 100)
		mana.ADD_Value(i);
}

void	Player::ADD_Hp(float i)
{
	hp += i;
}

void	Player::ADD_PosX(float new_posX)
{
	posX += new_posX;
}
void	Player::ADD_PosY(float new_posY)
{
	posY += new_posY;
}

Item	*Player::GET_Hand(int hand)
{
	return (&hands[hand]);
}

int			Player::GET_Hand_Type(int hand)
{
	return (hands[hand].GET_Type());
}