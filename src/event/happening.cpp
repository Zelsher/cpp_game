#include "../../inc/game.hpp"

Happening::Happening()
{
	pos.x = 0;
	pos.y = 0;
	incrX = 0;
	incrY = 0;
	happen = 0;
}

Happening::Happening(int type, Vector2 origin_pos, Vector2 use_pos, Game *game)
{
	if (type == SHOOT)
	{
		(void)game;
		(void)use_pos;
		pos.x = origin_pos.x;
		pos.y = origin_pos.y;
		incrX = 1;
		incrY = 1;
		*texture = game->GET_Texture()->tile1;
		duration = 200;
		happen = 0;
	}
}

Happening::~Happening()
{
}

void	Happening::UPDATE_Happening()
{
	cout << "update" << endl;
	if (type == SHOOT)
	{
		pos.x += incrX;
		pos.y += incrY;
	}
	happen++;
}


