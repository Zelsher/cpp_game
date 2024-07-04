#include "../inc/game.hpp"

int	main()
{
	Game	game;

	Weapon	ring;
	Weapon	pistol;
	Weapon	uzi;

	pistol.SET_Weapon(PISTOL, NULL);
	uzi.SET_Weapon(UZI, NULL);
	ring.SET_Weapon(TP_RING, game.GET_Player(0)->GET_Mana_p());
	game.ADD_Player("Suceur de naine");
	game.GET_Player(0)->ADD_Item(ring);
	game.GET_Player(0)->ADD_Item(pistol);
	while (!WindowShouldClose())
	{
		game.UPDATE_Game();
	}
}