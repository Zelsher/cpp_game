#include "../../inc/game.hpp"

Weapon::Weapon() : empty(1), type(0), reload_time(0), reload(0), cooldown_time(0), cooldown(0)
{
	audio.reload = LoadSound("asset/audio/Reload.mp3");
	audio.end_reload = LoadSound("asset/audio/End_Reload.mp3");
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
		cooldown_time = 20;
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
	else if (w_type == MAGIC_STICK)
	{
		reload_time = 0;
		cooldown_time = 170;
		ressource_type = MANA;
	}
	empty = 0;
}
