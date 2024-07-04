#include "../../inc/game.hpp"

int	main()
{
	Game	game;

	game.ADD_Player("Suceur de naine");

	Weapon	ring;
	ring.SET_Weapon(TP_RING, game.GET_Player(0)->GET_Mana_p());
	game.GET_Player(0)->ADD_Item(ring);

	//Weapon magic_stick;
	//ring.SET_Weapon(MAGIC_STICK, game.GET_Player(0)->GET_Mana_p());
	//game.GET_Player(0)->ADD_Item(ring);

	//Weapon	pistol;
	//pistol.SET_Weapon(PISTOL, NULL);
	//game.GET_Player(0)->ADD_Item(pistol);

	Weapon	uzi;
	uzi.SET_Weapon(UZI, NULL);
	game.GET_Player(0)->ADD_Item(uzi);

	while (!WindowShouldClose())
	{
		game.UPDATE_Game();
	}
}
