#include "../../inc/game.hpp"

//si un item a commencer un reload ou un cd, il lincremente, si il la finit, il le remet a 0
void	Item::UPDATE_Item()
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

void	Item::RELOAD()
{
	if (ressource_type == MANA || ressource->GET_Value() == 100)
		return;
	if (reload_time && !RELOADING())
	{
		reload++;
		PlaySound(audio.reload);
	}
}

int	Item::RELOADING()
{
	return(reload);
}

void	Item::COOLDOWN()
{
	//cout << cooldown_time << endl;
	if (cooldown_time && !cooldown)
		cooldown++;
}

int	Item::IS_Cooldown()
{
	return(cooldown);
}


void	Item::USE(Vector2 player_pos, Vector2 use_pos, Player *player, vector<vector<Cell>> *map, Game *game)
{
	(void)game;
	use_pos.x /= TILE_SIZE;
	use_pos.y /= TILE_SIZE;
	if (empty || !type || reload || cooldown)
		return;
	//cout << cooldown << endl;
	if (type == TP_RING)
	{
		int	cost = ((sqrt(pow(player_pos.x * TILE_SIZE - use_pos.x * TILE_SIZE, 2)
			+ pow(player_pos.y * TILE_SIZE - use_pos.y * TILE_SIZE, 2)) / TILE_SIZE)) * 5;
		//cout << "cost" << cost << endl;
		if (!NOT_Wall(map, use_pos.x, use_pos.y))
			return;
		if (player->GET_Mana_V() > cost)
		{
			player->ADD_Mana(-cost);
			PlaySound(audio.use);
			player->SET_Pos(use_pos);
			COOLDOWN();
		}
	}
	else if (type == MAGIC_STICK && ressource->GET_Value() >= 20)
	{
		game->GET_Event()->ADD_Event(MAGIC_SPELL, player_pos, use_pos, game, 0);
		ressource->ADD_Value(-20);
		PlaySound(audio.use);
		COOLDOWN();
	}
	else if ((type == PISTOL || type == UZI))
	{
		if (type == PISTOL && ressource->GET_Value() >= 10)
		{
			ressource->ADD_Value(-10);
			PlaySound(audio.use);
			game->GET_Event()->ADD_Event(SHOOT, player_pos, use_pos, game, 8);
		}
		if (type == UZI && ressource->GET_Value() >= 2)
		{
			ressource->ADD_Value(0);
			PlaySound(audio.use);
			game->GET_Event()->ADD_Event(SHOOT, player_pos, use_pos, game, 8);
		}
		COOLDOWN();
	}
}