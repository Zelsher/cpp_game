#include "../../inc/game.hpp"

//Game

void	Game::UPDATE_Game()
{
	int	verif;
	while (!IsWindowFocused())
	{
		BeginDrawing();
		ClearBackground(BLACK);
		EndDrawing();
	}

	HANDLE_Input(0);

	player[0].UPDATE_Items();

	event.UPDATE_EVENTS(&map);

	for (size_t i = 0; i < mobs.size() || i < boss.size(); i++)
	{
		if (i < mobs.size())
		{
			verif = mobs[i].ACTION(&map);
			if (verif == 0)
			{
				mobs.erase(mobs.begin() + i);
			}
		}
		if (i < boss.size())
		{
			verif = boss[i].UPDATE_Boss(&map);
			if (verif == 0)
				boss.erase(boss.begin() + i);
		}
	}

	if (frame % 50 == 0)
		map.UPDATE_Spawner();

	if (frame == 100000)
		frame = 0;
	display.UPDATE_Image();
	frame++;

	if (player[0].IS_Inventory_Open())
		(void)player[0];
}

void	Game::CHOSE_Lvl()
{
	map.SET_Map("asset/map/map2");//@
}

Game::Game() : display(player), map(this) ,frame(0)
{
	InitWindow(WIDTH, HEIGHT, "game");
	ClearBackground(BLACK);
	SetTargetFPS(30);
	InitAudioDevice();
	CHOSE_Lvl();
	display.SET_Map(&map, &texture, map.GET_Width_Map(), map.GET_Height_Map());
	LOAD_Texture();
	display.SET_Event(&event, &boss, &mobs);
}

Game::~Game()
{
	CloseWindow();
}

void		Game::LOAD_Texture()
{
	texture.wall_1 =  LoadTexture("asset/texture/Wall_1.png");
	texture.ground_1 = LoadTexture("asset/texture/Ground_1.png");
	texture.ground_2 = LoadTexture("asset/texture/Ground_2.png");
	texture.house_1 =  LoadTexture("asset/texture/House.png");
	texture.tree_1 = LoadTexture("asset/texture/Tree_1.png");
	texture.player_1 = LoadTexture("asset/texture/character_1/Player_1.png");
	texture.player_2 = LoadTexture("asset/texture/Player_2.png");
	texture.r_hand = LoadTexture("asset/texture/Right_Hand.png");
	texture.l_hand = LoadTexture("asset/texture/Left_Hand.png");
	texture.bullet_1 = LoadTexture("asset/texture/bullet_1.png");
	texture.tile1 = LoadTexture("asset/texture/32.png");
	texture.tile2 = LoadTexture("asset/texture/64.png");
	texture.boss1 = LoadTexture("asset/texture/boss.png");
	texture.item[TP_RING] = LoadTexture("asset/texture/Tp_Ring.png");
	texture.item[MAGIC_STICK] = LoadTexture("asset/texture/32.png");
	texture.item[PISTOL] = LoadTexture("asset/texture/Pistol.png");
	texture.item[UZI] = LoadTexture("asset/texture/Uzi.png");

	texture.texture_pack.ennemy = LoadTexture("asset/texture/character_1/Player_1.png");
	texture.texture_pack.boss = LoadTexture("asset/texture/boss.png");
	//texture.texture_pack.ennemy = LoadTexture("assest/texture/ennemy_texture_pack/1.png");
}

int Game::ADD_Player(string name)
{
	int	i = 0;

	if (i < 2 && player[i].EXIST() == 1)
		i++;
	if (i == 2)
		return(1);
	player[0].SET_PosX(1.5);
	player[0].SET_PosY(1.5);
	return (player[i].ACTIVATE_Player(name, i));
	display.UPDATE_Display();
}

//Display


