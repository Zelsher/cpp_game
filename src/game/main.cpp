#include "../../inc/game.hpp"

int	main()
{
	Game	game;

	game.ADD_Player("Suceur de naine");
	game.CREATE_Mob(ENNEMY, Vector2{1, 8});

	Item	uzi;
	uzi.SET_Item(UZI, NULL);
	game.GET_Player(0)->ADD_Item(uzi);

	Item	ring;
	ring.SET_Item(TP_RING, game.GET_Player(0)->GET_Mana_p());
	game.GET_Player(0)->ADD_Item(ring);

	Item	pistol;
	pistol.SET_Item(PISTOL, NULL);
	game.GET_Player(0)->ADD_Item(pistol);

	Item magic_stick;
	magic_stick.SET_Item(MAGIC_STICK, game.GET_Player(0)->GET_Mana_p());
	game.GET_Player(0)->ADD_Item(magic_stick);

	game.CREATE_Boss(BOSS1, Vector2{10, 10});

	while (!WindowShouldClose())
		game.UPDATE_Game();
}
