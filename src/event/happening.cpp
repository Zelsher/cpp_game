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

Happening::Happening(int n_type, Vector2 origin_pos, Vector2 use_pos, Game *game, int speed, float dmg)
{
	Vector2	n_pos;
	type = n_type;
	incrX = 0;
	incrY = 0;
	pos.x = origin_pos.x;
	pos.y = origin_pos.y;
	dir = 0;
	damage = dmg;
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

int	Happening::UPDATE_Happening(Map *map)
{
	//cout << "[" << pos.y << "][" << pos.x << "]" << endl;
	Player	*p_player;
	Mob		*p_mob;
	Boss	*p_boss;

	if ((duration && duration < happen)
		|| !NOT_Wall(map, pos.x + incrX, pos.y + incrY))
	{
		cout << "Wall hitted" << endl;
		return(0);
	}
	if (type == SHOOT)
	{
		int	dist_y;
		int	dist_x;
	
		pos.x += incrX;
		pos.y += incrY;
		p_player = map->PLAYER_Near(pos);
		if (p_player)
		{
			dist_x = p_player->GET_Pos().x - pos.x;
			dist_y = p_player->GET_Pos().y - pos.y;
			if ((dist_x > -0.2 && dist_x < 0.2) && (dist_y > -0.2 && dist_y < 0.2))
				p_player->ADD_Hp(-5);
			cout << "Player hitted" << endl;
			return (0);
		}
		int i = 0;
		while ((p_mob = map->GET_Mob(i, pos)))
		{
			dist_x = p_mob->GET_Pos().x - pos.x;
			dist_y = p_mob->GET_Pos().y - pos.y;
			if ((dist_x > -0.2 && dist_x < 0.2) && (dist_y > -0.2 && dist_y < 0.2))
				p_mob->ADD_Hp(-10);
			cout << "Mob hitted" << endl;
			i++;
			return (0);
		}
		i = 0;
		if ((p_boss = map->GET_Boss(i, pos)))
		{
			if (p_boss->HIT_Hitbox(pos))
			{
				p_boss->ADD_Hp(-5);
				cout << "Boss hitted" << endl;
				i++;
				return (0);
			}
		}
	}
	happen++;
	return (1);
}


