#include "../inc/game.hpp"

Player::Player() : run(0), stamina(GREEN), mana(BLUE)
{
	enable = 0;
	hp = 100;
	speed = 0.1f;
}
int Player::ACTIVATE_Player(string new_name, int new_id)
{
	id = new_id;
	name = new_name;
	enable = 1;
	//fill pos
	return (0);
}

void	Player::UPDATE_Items()
{
	//cout << "mana" << mana.GET_Value() << endl;
	hands[0].UPDATE_Item();
	hands[1].UPDATE_Item();
	pocket[0].UPDATE_Item();
	pocket[1].UPDATE_Item();
	if (mana.GET_Value() < 100)
		mana.ADD_Value(0.4f);

	if (stamina.GET_Value() < 100 && !run)
		stamina.ADD_Value(1);
	else if (run)
		stamina.ADD_Value(-1);
}
	
int	Player::EXIST()
{
	return (enable);
}

Weapon	*Player::GET_Hand(int hand)
{
	return (&hands[hand]);
}

int			Player::GET_Hand_Type(int hand)
{
	return (hands[hand].GET_Type());
}

void		Player::SWITCH_Weapon(int hand)
{
	Weapon temp;

	temp = hands[hand];
	hands[hand] = pocket[hand];
	pocket[hand] = temp;
}

void		Player::RELOAD_Weapons()
{
	hands[0].RELOAD();
	hands[1].RELOAD();
}

void	Player::ADD_Item(Weapon item)
{
	if (hands[LEFT].EMPTY())
		hands[LEFT] = item;
	else if (hands[RIGHT].EMPTY())
		hands[RIGHT] = item;
	else if (pocket[LEFT].EMPTY())
		pocket[LEFT] = item;
	else if (pocket[RIGHT].EMPTY())
		pocket[RIGHT] = item;
}



void	Player::SET_Dir(float x, float y)
{
	dir.x = x;
	dir.y = y;
	rot = atan2(y, x) * (180 / PI) + 90;// * (100.0f / PI);
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

void	Player::ADD_PosX(float new_posX)
{
	posX += new_posX;
}
void	Player::ADD_PosY(float new_posY)
{
	posY += new_posY;
}


