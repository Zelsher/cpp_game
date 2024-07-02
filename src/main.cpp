#include "../inc/game.hpp"

int	main()
{
	Game	game;

	Weapon	ring;
	ring.SET_Weapon(TP_RING);
	game.ADD_Player("Suceur de naine");
	game.GET_Player(0)->ADD_Item(&ring);
	while (!WindowShouldClose())
	{
		game.UPDATE_Img();
	}
}