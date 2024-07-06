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

Happening::Happening(int n_type, Vector2 origin_pos, Vector2 use_pos, Game *game, int speed)
{
	Vector2	n_pos;
	type = n_type;
	incrX = 0;
	incrY = 0;
	pos.x = origin_pos.x;
	pos.y = origin_pos.y;
	dir = 0;
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
		pos.x = origin_pos.x + n_pos.x * speed;
		pos.y = origin_pos.y + n_pos.y * 3;
		incrX = n_pos.x * speed;
		incrY = n_pos.y * speed;
		texture = &game->GET_Texture()->bullet_1;
		duration = 200;
		happen = 0;
		dir = atan2(use_pos.y - origin_pos.y, use_pos.x - origin_pos.x) * (180 / PI) + 90;
	}
}

Happening::~Happening()
{
}

int	Happening::UPDATE_Happening(vector<vector<Cell>> *map)
{
	//cout << "[" << pos.y << "][" << pos.x << "]" << endl;
	Player	*p_player;
	Mob		*p_mob;

	if ((duration && duration < happen)
		|| !NOT_Wall(map, pos.x + incrX, pos.y + incrY))
		return(0);
	if (type == SHOOT)
	{
		int	dist_y;
		int	dist_x;
	
		pos.x += incrX;
		pos.y += incrY;
		p_player = (*map)[pos.y][pos.x].PLAYER_Near();
		if (p_player)
		{
			dist_x = p_player->GET_PosX() - pos.x;
			dist_y = p_player->GET_PosY() - pos.y;
			if ((dist_x > -0.2 && dist_x < 0.2) && (dist_y > -0.2 && dist_y < 0.2))
				p_player->ADD_Hp(-5);
			return (0);
		}
		int i = 0;
		while ((p_mob = (*map)[pos.y][pos.x].GET_Mob(i)))
		{
			dist_x = p_mob->GET_Pos().x - pos.x;
			dist_y = p_mob->GET_Pos().y - pos.y;
			if ((dist_x > -0.2 && dist_x < 0.2) && (dist_y > -0.2 && dist_y < 0.2))
				p_mob->ADD_Hp(-10);
			i++;
		}
	}
	happen++;
	return (1);
}


