#include "../inc/game.hpp"

Player::Player()
{
	enable = 0;
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
float	Player::GET_Dir()
{
	return (dir);
}
string	Player::GET_Name()
{
	return (name);
}
