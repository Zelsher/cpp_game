#include "../inc/game.hpp"

int	main()
{
	Game	game;

	game.ADD_Player("Bob");
	cout << game.GET_Name_Player(0) << endl;
	while (!WindowShouldClose())
	{
		game.UPDATE_Img();
	}
}