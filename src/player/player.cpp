#include "../../inc/game.hpp"

Player::Player() : run(0), stamina(GREEN), mana(BLUE)
{
	enable = 0;
	hp = 100;
	speed = 0.1f;
}
int	Player::ACTIVATE_Player(string new_name, int new_id)
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

void	Player::SWITCH_Weapon(int hand)
{
	Weapon temp;

	temp = hands[hand];
	hands[hand] = pocket[hand];
	pocket[hand] = temp;
}

void	Player::RELOAD_Weapons()
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
