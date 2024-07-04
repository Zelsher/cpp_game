#include "../../inc/game.hpp"

//si un item a commencer un reload ou un cd, il lincremente, si il la finit, il le remet a 0
void	Weapon::UPDATE_Item()
{
	if (empty || !type)
		return;
	//cout << "ressource" << type << " " << ressource->GET_Value() << endl;
	if (reload_time && reload == reload_time)
	{
		reload = 0;
		PlaySound(audio.end_reload);
		GET_Ressource()->SET_Value(100);
	}
	else if (reload)
		reload++;

	if (cooldown_time && cooldown == cooldown_time)
		cooldown = 0;
	else if (cooldown)
		cooldown++;
}

void	Weapon::RELOAD()
{
	if (ressource_type == MANA)
		return;
	if (reload_time && !RELOADING())
	{
		reload++;
		PlaySound(audio.reload);
	}
}

int	Weapon::RELOADING()
{
	return(reload);
}

void	Weapon::COOLDOWN()
{
	//cout << cooldown_time << endl;
	if (cooldown_time && !cooldown)
		cooldown++;
}

int	Weapon::IS_Cooldown()
{
	return(cooldown);
}


void	Weapon::USE(Vector2 player_pos, Vector2 use_pos, Player *player, vector<vector<char>> *map)
{

	if (empty || !type || reload || cooldown)
		return;
	//cout << cooldown << endl;
	if (type == TP_RING)
	{
		int	cost = sqrt(pow(player_pos.x - use_pos.x, 2) + pow(player_pos.y - use_pos.y, 2)) / TILE_SIZE;
		//cout << "cost" << cost << endl;

		if (player->GET_Mana_V() > cost && 
			moove_player_valid(map, use_pos.x / TILE_SIZE, use_pos.y / TILE_SIZE))
		{
			use_pos.x /= TILE_SIZE;
			use_pos.y /= TILE_SIZE;
			player->ADD_Mana(-cost);
			player->SET_Pos(use_pos);
		}
	}
	else if (type == MAGIC_STICK)
	{
		GET_Ressource()->ADD_Value(-20);
		COOLDOWN();
	}
	else if ((type == PISTOL || type == UZI))
	{
		if (type == PISTOL)
			GET_Ressource()->ADD_Value(-10);
		if (type == UZI)
			GET_Ressource()->ADD_Value(-2);
		COOLDOWN();
	}
}