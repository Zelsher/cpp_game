#include "../inc/game.hpp"
#include "raylib.h"
int	main()
{
	Game	game;

	cout << game.GET_Name_Player(0) << endl;
	while (!WindowShouldClose())
	{
		ClearBackground(BLACK);
	}
}