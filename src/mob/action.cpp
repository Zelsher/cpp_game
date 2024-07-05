#include "../../inc/game.hpp"

void	Mob::MOOVE_Ennemy(vector<vector<Cell>> *map)
{
	Vector2	dir;

	(void)map;
	dir	= FIND_Direction(pos, Vector2 {game->PLAYER_PosX(0), game->PLAYER_PosY(0)});
	if (NOT_Wall(map, pos.x + dir.x, pos.y))
		pos.x += dir.x;
	if (NOT_Wall(map, pos.x, pos.y + dir.y))
		pos.y += dir.y;
}


void	Mob::ACTION(vector<vector<Cell>> *map)
{
	if (type == ENNEMY)
		MOOVE_Ennemy(map);
}