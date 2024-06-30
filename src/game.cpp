#include "../inc/game.hpp"

//Game

Game::Game() : display(player)
{
	InitWindow(WIDTH, HEIGHT, "game");
	ClearBackground(BLACK);
	CHOSE_Lvl();
}

Game::~Game()
{
	CloseWindow();
}

void	Game::CHOSE_Lvl()
{
	int	lvl = 1;//Offrir un choix
		if (lvl == 1)
	map = OPEN_Map("asset/map/map1");
	//PRINT_Map(map);
	display.SET_Map(&map);
	//Mettre / les joueur sur P
}

int Game::ADD_Player(string name)
{
	int	i = 0;

	if (i < MAX_PLAYER && player[i].EXIST() == 1)
		i++;
	if (i == MAX_PLAYER)
		return(1);
	player[0].SET_PosX(15);
	player[0].SET_PosY(15);
	return (player[i].ACTIVATE_Player(name, i));
}

void	Game::UPDATE_Img()
{
	display.UPDATE_Image();
}

float Game::PLAYER_PosX(int id)
{
	return (player[id].GET_PosX());
}
float Game::PLAYER_PosY(int id)
{
	return (player[id].GET_PosY());
}

float Game::PLAYER_Dir(int id)
{
	return (player[id].GET_Dir());
}

string	Game::GET_Name_Player(int id)
{
	return (player[id].GET_Name());
}

//Display


