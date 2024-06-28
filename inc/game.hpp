#ifndef HEADER_HPP
# define HEADER_HPP

using namespace std;


# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# include "raylib.h"

#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include "raylib.h"
#include "player.hpp"
#include "functions.hpp"

#ifndef MAX_PLAYER
# define MAX_PLAYER 2
#endif

#define WIDTH 1920
#define HEIGHT 1080

class Display
{
	private:
		Player					*player;
		vector<vector<char>>	*map;
		int						max_mapY;
		int						n_cam;
		int						width;
		int						height;
	public:
		Display(Player* player_list) : player(player_list), n_cam(1), width(WIDTH), height(HEIGHT)
		{
		}
	
		void	UPDATE_Image()
		{
			int	temp_width = width;
			int	temp_height = height;
	
			if (n_cam == 2)
				temp_width /= 2;
			BeginDrawing();
			ClearBackground(BLACK);
			
			for (int i = 0 ; i < n_cam; i++)
				DISPLAY_Cam(&player[i], temp_width, temp_height, i, map, max_mapY);
			EndDrawing();
		}
	
		void	UPDATE_Display()
		{
			n_cam = COUNT_Player(player);
		}
		int	COUNT_Player(Player *player)
		{
			int	i = 0;

			while (player[i].EXIST())
				i++;
			return (i);
		}
		void	SET_Map(vector<vector<char>> *n_map)
		{
			map = n_map;
			max_mapY = map->size();
			PRINT_Map(*n_map);
		}
};

class Game
{
	private:
		Player					player[MAX_PLAYER];
		Display					display;
		vector<vector<char>>	map;
	public:
		Game() : display(player)
		{
			InitWindow(WIDTH, HEIGHT, "game");
			ClearBackground(BLACK);
			CHOSE_Lvl();
		}
		void	CHOSE_Lvl()
		{
			int	lvl = 1;//Offrir un choix

			if (lvl == 1)
				map = OPEN_Map("asset/map/map1");
			//PRINT_Map(map);
			display.SET_Map(&map);
			//Mettre / les joueur sur P
		}
		int ADD_Player(string name)
		{
			int	i = 0;

			if (i < MAX_PLAYER && player[i].EXIST() == 1)
				i++;
			if (i == MAX_PLAYER)
				return(1);
			player[0].SET_PosX(1);
			player[0].SET_PosY(1);
			return (player[i].Activate_Player(name, i));
		}
	
		void	UPDATE_Img()
		{
			display.UPDATE_Image();
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
