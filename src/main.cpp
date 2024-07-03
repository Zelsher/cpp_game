#include "../inc/game.hpp"

int	main()
{
	Game	game;

	Weapon	ring;
	Weapon	pistol;

	ring.SET_Weapon(PISTOL, NULL);
	pistol.SET_Weapon(TP_RING, game.GET_Player(0)->GET_Mana_p());
	game.ADD_Player("Suceur de naine");
	game.GET_Player(0)->ADD_Item(ring);
	game.GET_Player(0)->ADD_Item(pistol);
	while (!WindowShouldClose())
	{
		game.UPDATE_Img();
	}
}