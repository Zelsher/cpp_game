#ifndef HEADER_HPP
# define HEADER_HPP

using namespace std;


# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# include "raylib.h"

#include <iostream>
#include <string>
#include "raylib.h"
#include "functions.hpp"
#include "player.hpp"

#ifndef MAX_PLAYER
# define MAX_PLAYER 5
#endif

#define WIDTH 1920
#define HEIGHT 1080

class Game
{
	private:
		Player	player[10];
		char	**map;
	public:
		Game()
		{
			InitWindow(WIDTH, HEIGHT, "Game Of Life");
			ClearBackground(BLACK);
			CHOSE_Lvl();
		}
		void	CHOSE_Lvl()
		{
			int	lvl = 1;//Offrir un choix

			if (lvl == 1)
				map = NULL;//OPEN_Map("asset/map/map1");
			if (map)
				exit(0);
		}
		int ADD_Player(string name)
		{
			int	i = 0;

			if (i < MAX_PLAYER && player[i].EXIST() == 1)
				i++;
			if (i == MAX_PLAYER)
				return(1);
			return (player[i].Activate_Player(name, i));
		}
		float PLAYER_PosX(int id)
		{
			return (player[id].GET_PosX());
		}
		float PLAYER_PosY(int id)
		{
			return (player[id].GET_PosY());
		}
		float PLAYER_Dir(int id)
		{
			return (player[id].GET_Dir());
		}
		string	GET_Name_Player(int id)
		{
			return (player[id].GET_Name());
		}
};

#endif
