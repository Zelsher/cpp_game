#include "../inc/game.hpp"

Ressource::Ressource(Color n_color)
{
	value = 100.0f;
	color = n_color;
}

Ressource::~Ressource()
{
}

void	Ressource::ADD_Value(float i)
{
	if (value + i < 0)
		return ;
	else if (value + i > 100)
		value = 100;
	else
		value += i;
}

Weapon::Weapon() : empty(1), type(0), reload_time(0), reload(0), cooldown_time(0), cooldown(0)
{
}

Weapon::~Weapon()
{
}

void	Weapon::SET_Weapon(int w_type, Ressource *n_ressource)
{
	if (n_ressource)
		ressource = n_ressource;
	else
		ressource = NULL;
	type = w_type;
	if (w_type == PISTOL)
	{
		reload_time = 100;
		cooldown_time = 200;
		ressource = new Ressource(ORANGE);
		ressource_type = AMMO;
	}
	else if (w_type == UZI)
	{
		reload_time = 120;
		cooldown_time = 2;
		ressource = new Ressource(ORANGE);
		ressource_type = AMMO;
	}
	else if (w_type == TP_RING)
	{
		reload_time = 0;
		cooldown_time = 0;
		ressource_type = MANA;
	}
	empty = 0;
}
