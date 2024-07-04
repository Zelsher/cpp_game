#include "../../inc/game.hpp"

int	main()
{
	Game	game;

	game.ADD_Player("Suceur de naine");

	Item	ring;
	ring.SET_Item(TP_RING, game.GET_Player(0)->GET_Mana_p());
	game.GET_Player(0)->ADD_Item(ring);


	Item	uzi;
	uzi.SET_Item(UZI, NULL);
	game.GET_Player(0)->ADD_Item(uzi);

	Item	pistol;
	pistol.SET_Item(PISTOL, NULL);
	game.GET_Player(0)->ADD_Item(pistol);

	Item magic_stick;
	ring.SET_Item(MAGIC_STICK, game.GET_Player(0)->GET_Mana_p());
	game.GET_Player(0)->ADD_Item(ring);

	while (!WindowShouldClose())
	{
		game.UPDATE_Game();
	}
}
