#include "../inc/game.hpp"

//si un item a commencer un reload ou un cd, il lincremente, si il la finit, il le remet a 0
void	Weapon::UPDATE_Item()
{
	if (empty || !type)
		return;
	//cout << "ressource" << type << " " << ressource->GET_Value() << endl;
	if (reload_time && reload == reload_time)
	{
		reload = 0;
		GET_Ressource()->SET_Value(100);
	}
	else if (reload_time && reload)
		reload++;

	if (cooldown_time && cooldown == cooldown_time)
		cooldown = 0;
	else if (cooldown_time && cooldown)
		cooldown++;
}

void	Weapon::RELOAD()
{
	cout << "PRERELOAD" << endl;
	if (ressource_type == MANA)
		return;
	if (reload_time && reload < reload_time)
	{
		reload++;
		cout << "RELOAD" << endl;
	}
}

int	Weapon::RELOADING()
{
	return(reload);
}

void	Weapon::COOLDOWN()
{
	cout << "CD" << endl;
	if (cooldown_time && cooldown < cooldown_time)
		cooldown++;
}

int	Weapon::IS_Cooldown()
{
	return(cooldown);
}


void	Weapon::USE(Vector2 player_pos, Vector2 use_pos, Player *player, vector<vector<char>> *map)
{

	if (empty || !type || reload)
	{
		cout << "UNVALID" << endl;
		return;
	}
	if (type == TP_RING)
	{
		cout << "USE" << endl;
		(void)player_pos;
		int	cost = 66;//calculer le cout en fonction de la distance

		if (player->GET_Mana_V() > cost && 
			moove_player_valid(map, use_pos.x / TILE_SIZE, use_pos.y / TILE_SIZE))
		{
			use_pos.x /= TILE_SIZE;
			use_pos.y /= TILE_SIZE;
			player->ADD_Mana(-66);
			player->SET_Pos(use_pos);
		}
	}
	if ((type == PISTOL || type == UZI))
	{
		cout << "USE" << endl;
		if (type == PISTOL)
			GET_Ressource()->ADD_Value(-10);
		if (type == UZI)
			GET_Ressource()->ADD_Value(-2);
		COOLDOWN();
	}
}