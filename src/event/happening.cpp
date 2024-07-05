#include "../../inc/game.hpp"

Happening::Happening()
{
	pos.x = 0;
	pos.y = 0;
	incrX = 0;
	incrY = 0;
	happen = 0;
	duration = 0;
}

Happening::Happening(int n_type, Vector2 origin_pos, Vector2 use_pos, Game *game)
{
	Vector2	n_pos;
	type = n_type;
	incrX = 0;
	incrY = 0;
	pos.x = origin_pos.x;
	pos.y = origin_pos.y;

	if (type == MAGIC_SPELL)
	{
		pos.x = use_pos.x;
		pos.y = use_pos.y;
		texture = &game->GET_Texture()->tile1;
		duration = 50;
		happen = 0;
	}
	else if (type == SHOOT)
	{
		n_pos = FIND_Direction(origin_pos, use_pos);
		(void)game;
		(void)use_pos;
		pos.x = origin_pos.x;
		pos.y = origin_pos.y;
		incrX = n_pos.x * 10;
		incrY = n_pos.y* 10;
		texture = &game->GET_Texture()->tile1;
		duration = 200;
		happen = 0;
	}
}

Happening::~Happening()
{
}

int	Happening::UPDATE_Happening(vector<vector<Cell>> *map)
{
	//cout << "update" << endl;
	if ((duration && duration < happen)
		|| !NOT_Wall(map, pos.x + incrX, pos.y + incrY))
		return(0);
	if (type == SHOOT)
	{
		//cout << pos.x << " " << pos.y << "  " << happen << endl;
		pos.x += incrX;
		pos.y += incrY;
	}
	happen++;
	return (1);
}


