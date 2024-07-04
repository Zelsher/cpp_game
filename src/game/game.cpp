#include "../../inc/game.hpp"

//Game

Game::Game() : display(player)
{
	InitWindow(WIDTH, HEIGHT, "game");
	ClearBackground(BLACK);
	SetTargetFPS(60);
	InitAudioDevice();
	CHOSE_Lvl();
}

Game::~Game()
{
	CloseWindow();
}

void	Game::CHOSE_Lvl()
{
	int	width;
	int	height;

	int	lvl = 1;//Offrir un choix
		if (lvl == 1)
	map = OPEN_Map("asset/map/map1");
	width = map[1].size();
	height = map.size();
	LOAD_Texture();
	display.SET_Map(&map, &texture, width, height);
	//Mettre / les joueur sur P
}

void		Game::LOAD_Texture()
{
	texture.wall_1 =  LoadTexture("asset/texture/Wall_1.png");
	texture.ground_1 = LoadTexture("asset/texture/Ground_1.png");
	texture.tree_1 = LoadTexture("asset/texture/Tree_1.png");
	texture.player_1 = LoadTexture("asset/texture/character_1/Player_1.png");
	texture.player_2 = LoadTexture("asset/texture/Player_2.png");
	texture.r_hand = LoadTexture("asset/texture/Right_Hand.png");
	texture.l_hand = LoadTexture("asset/texture/Left_Hand.png");
	texture.tile1 = LoadTexture("asset/texture/32.png");
	texture.tile2 = LoadTexture("asset/texture/64.png");
	texture.item[TP_RING] = LoadTexture("asset/texture/Tp_Ring.png");
	texture.item[MAGIC_STICK] = LoadTexture("asset/texture/Magic_Stick.png");
	texture.item[PISTOL] = LoadTexture("asset/texture/Pistol.png");
	texture.item[UZI] = LoadTexture("asset/texture/Uzi.png");
}

int Game::ADD_Player(string name)
{
	int	i = 0;

	if (i < 2 && player[i].EXIST() == 1)
		i++;
	if (i == 2)
		return(1);
	player[0].SET_PosX(15);
	player[0].SET_PosY(15);
	return (player[i].ACTIVATE_Player(name, i));
	display.UPDATE_Display();
}

void	Game::UPDATE_Game()
{
	HANDLE_Input(0);
	player[0].UPDATE_Items();
	display.UPDATE_Image();
	//if (backpack_mod)
	//	display.DISPLAY_Backpack();
}



//Display


