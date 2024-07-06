#include "../../inc/game.hpp"

//Game

Game::Game() : display(player), frame(0)
{
	InitWindow(WIDTH, HEIGHT, "game");
	ClearBackground(BLACK);
	SetTargetFPS(200);
	InitAudioDevice();
	CHOSE_Lvl();
	display.SET_Event(&event);
	display.SET_Mobs(&mobs);
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
	texture.item[TP_RING] = LoadTexture("asset/texture/Tp_Ring.png");
	texture.item[MAGIC_STICK] = LoadTexture("asset/texture/32.png");
	texture.item[PISTOL] = LoadTexture("asset/texture/Pistol.png");
	texture.item[UZI] = LoadTexture("asset/texture/Uzi.png");
	texture.texture_pack.ennemy = LoadTexture("asset/texture/character_1/Player_1.png");
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

void	Game::UPDATE_Spawner()
{
	for (size_t i = 0; i < spawner.size(); i++)
	{
		//cout << spawner[i].z << endl;
		if (spawner[i].z && rand()%9 + 1 < spawner[i].z)
		{
			//cout << spawner[i].x << " " << spawner[i].y << endl;
			CREATE_Mob(ENNEMY, Vector2{spawner[i].x, spawner[i].y});
		}
	}
}

void	Game::UPDATE_Game()
{
	int	j;

	if (!player[0].GET_Hp())
	{
		cout << "DEAD\n";
		exit(0);
	}
	HANDLE_Input(0);

	player[0].UPDATE_Items();

	event.UPDATE_EVENTS(&map);

	for (size_t i = 0; i < mobs.size(); i++)
	{
		j = mobs[i].ACTION(&map);
		if (j == 0)
			mobs.erase(mobs.begin() + i);
	}
	if (frame % 50 == 0)
		UPDATE_Spawner();

	if (frame == 100000)
		frame = 0;
	display.UPDATE_Image();
	frame++;

	if (player[0].IS_Inventory_Open())
		(void)player[0];
}

//Display


