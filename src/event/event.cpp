#include "../../inc/game.hpp"

Event::Event() : last_happening(0)
{
}

Event::~Event()
{
}

void	Event::ADD_Event(int type, Vector2 origin_pos, Vector2 use_pos, Game *game, int speed, float dmg)
{
	Happening temp(type, origin_pos, use_pos, game, speed, dmg);
	happening.push_back(temp);
	last_happening++;
}

void	Event::UPDATE_EVENTS(Map *map)
{
	for (int i = 0 ; i < last_happening ; i++)
	{
		if (!happening[i].UPDATE_Happening(map))
		{
			happening.erase(happening.begin() + i);
			i--;
			last_happening--;
		}
	}
}