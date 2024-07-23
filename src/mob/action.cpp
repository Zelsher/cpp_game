#include "../../inc/game.hpp"

int		Mob::COOLDOWN()
{
	cooldown++;
	if (cooldown_time && cooldown == cooldown_time)
	{
		cooldown = 0;
		return (1);
	}
	return(0);
}

void	Mob::MOOVE_Ennemy(Map *map)
{
	Vector2	dir;
	int		dist_player;

	dist_player = game->PLAYER_PosX(0) - pos.x + game->PLAYER_PosY(0) - pos.x;
	if (this->SLEEPING() && (dist_player > 15 || dist_player < -15))
	{
		map->MAP_Mob(this, pos);
		return;
	}
	else
		WAKE_Up();
	dir	= FIND_Direction(pos, Vector2 {game->PLAYER_PosX(0), game->PLAYER_PosY(0)});
	if (NOT_Wall(map, pos.x + dir.x / 2, pos.y))
		pos.x += dir.x / 2;
	if (NOT_Wall(map, pos.x, pos.y + dir.y / 2))
		pos.y += dir.y / 2;
	map->MAP_Mob(this, pos);
	if (COOLDOWN())
		game->GET_Event()->ADD_Event(SHOOT, pos, game->GET_Player(0)->GET_Pos(), game, 4, 5);
}

void	Mob::MOOVE_Sleeper(Map *map)
{
	Vector2	dir;
	Mob		*p_mob;
	int		dist_player;
	
	int i = 0;// !!!!!!!!1 changer sa pour que tout se supprime a chaque update directement
	while ((p_mob = map->GET_Mob(i, pos)))
	{
		if (this == p_mob)
			map->DELETE_Mob(i, pos);
		i++;
	}
	dist_player = game->PLAYER_PosX(0) - pos.x + game->PLAYER_PosY(0) - pos.x;
	if (dist_player > 30 || dist_player < -35)
	{
		map->MAP_Mob(this, pos);
		return;
	}
	map->MAP_Mob(this, pos);
	dir	= FIND_Direction(pos, Vector2 {game->PLAYER_PosX(0), game->PLAYER_PosY(0)});
	if (NOT_Wall(map, pos.x + dir.x / 2, pos.y))
		pos.x += dir.x / 2;
	if (NOT_Wall(map, pos.x, pos.y + dir.y / 2))
		pos.y += dir.y / 2;
	if (COOLDOWN())
	{
		game->GET_Event()->ADD_Event(SHOOT, pos, game->GET_Player(0)->GET_Pos(), game, 4, 5);
	}
}

int	Mob::ACTION(Map *map)
{
	if (hp <= 0)
	{
		if (death == 750)
			return(0);
		death++;
		return (1);
	}
	if (type == ENNEMY)
		MOOVE_Ennemy(map);
	if (type == SLEEPER)
		MOOVE_Sleeper(map);
	return (1);
}
