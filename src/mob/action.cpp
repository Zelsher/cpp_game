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

void	Mob::MOOVE_Ennemy(vector<vector<Cell>> *map)
{
	Vector2	dir;
	int		dist_player;

	dist_player = game->PLAYER_PosX(0) - pos.x + game->PLAYER_PosY(0) - pos.x;
	if (this->SLEEPING() && (dist_player > 15 || dist_player < -15))
	{
		(*map)[pos.y][pos.x].MAP_Mob(this);
		return;
	}
	else
		WAKE_Up();
	dir	= FIND_Direction(pos, Vector2 {game->PLAYER_PosX(0), game->PLAYER_PosY(0)});
	if (NOT_Wall(map, pos.x + dir.x / 2, pos.y))
		pos.x += dir.x / 2;
	if (NOT_Wall(map, pos.x, pos.y + dir.y / 2))
		pos.y += dir.y / 2;
	(*map)[pos.y][pos.x].MAP_Mob(this);
	if (COOLDOWN())
		game->GET_Event()->ADD_Event(SHOOT, pos, game->GET_Player(0)->GET_Pos(), game, 4, 5);
}

void	Mob::MOOVE_Sleeper(vector<vector<Cell>> *map)
{
	Vector2	dir;
	Mob		*p_mob;
	int		dist_player;
	
	int i = 0;// !!!!!!!!1 changer sa pour que tout se supprime a chaque update directement
	while ((p_mob = (*map)[pos.y][pos.x].GET_Mob(i)))
	{
		if (this == p_mob)
			(*map)[pos.y][pos.x].DELETE_Mob(i);
		i++;
	}
	dist_player = game->PLAYER_PosX(0) - pos.x + game->PLAYER_PosY(0) - pos.x;
	if (dist_player > 30 || dist_player < -35)
	{
		(*map)[pos.y][pos.x].MAP_Mob(this);
		return;
	}
	(*map)[pos.y][pos.x].MAP_Mob(this);
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

int	Mob::ACTION(vector<vector<Cell>> *map)
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
