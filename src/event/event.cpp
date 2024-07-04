#include "../../inc/game.hpp"

Event::Event() : last_happening(0)
{
}

Event::~Event()
{
}

void	Event::ADD_Event(int type, Vector2 origin_pos, Vector2 use_pos, Game *game)
{
	cout << "new_event" << endl;
	happening.push_back(Happening(type, origin_pos, use_pos, game));
	last_happening++;
}

void	Event::UPDATE_EVENTS()
{
	for (int i = 0 ; i < last_happening ; i++)
	{
		happening[i].UPDATE_Happening();//verifier si il est detruit ici et decr n
	}
}