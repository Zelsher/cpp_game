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

#define WIDTH 500
#define HEIGHT 500

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
		Display(Player* player_list);

		void	UPDATE_Image();
		void	UPDATE_Display();
		int		COUNT_Player(Player *player);
		void	SET_Map(vector<vector<char>> *n_map);
};

class Game
{
	private:
		Player					player[MAX_PLAYER];
		Display					display;
		vector<vector<char>>	map;
	public:
		Game();
		~Game() noexcept;

		void	CHOSE_Lvl();
		void	UPDATE_Img();
		int 	ADD_Player(string name);
	
		float 	PLAYER_PosX(int id);
		float 	PLAYER_PosY(int id);
		float 	PLAYER_Dir(int id);
		string	GET_Name_Player(int id);
};


#endif
