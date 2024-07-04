#include "../../inc/game.hpp"

Item::Item() : empty(1), type(0), reload_time(0), reload(0), cooldown_time(0), cooldown(0)
{
	audio.reload = LoadSound("asset/audio/Reload.mp3");
	audio.end_reload = LoadSound("asset/audio/End_Reload.mp3");
}

Item::~Item()
{
	//if (ressource_type == AMMO)
		//delete ressource;
}

void	Item::SET_Item(int w_type, Ressource *n_ressource)
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
		audio.use = LoadSound("asset/audio/Shoot.mp3");
	}
	else if (w_type == UZI)
	{
		reload_time = 120;
		cooldown_time = 2;
		ressource = new Ressource(ORANGE);
		ressource_type = AMMO;
		audio.use = LoadSound("asset/audio/Shoot.mp3");
	}
	else if (w_type == TP_RING)
	{
		reload_time = 0;
		cooldown_time = 30;
		ressource_type = MANA;
		audio.use = LoadSound("asset/audio/Tp.mp3");
	}
	else if (w_type == MAGIC_STICK)
	{
		reload_time = 0;
		cooldown_time = 110;
		ressource_type = MANA;
		audio.use = LoadSound("asset/audio/Tp.mp3");
	}
	empty = 0;
}
