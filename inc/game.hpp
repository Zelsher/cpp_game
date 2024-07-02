#ifndef HEADER_HPP
# define HEADER_HPP

using namespace std;

#define WIDTH 1920
#define HEIGHT 1080

#define	TILE_SIZE 64

#define	TP_RING 1

#define	RIGHT 1
#define	LEFT 0

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# include "raylib.h"

#include <cmath>
#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include "raylib.h"
#include "player.hpp"
#include "weapon.hpp"
#include "functions.hpp"



typedef struct s_texture
{
	Texture2D	ground_1;
	Texture2D	wall_1;
	Texture2D	tree_1;
	Texture2D	player_1;
	Texture2D	player_2;
	Texture2D	r_hand;
	Texture2D	l_hand;
	Texture2D	item[10];
}			t_texture;

class Display
{
	private:
		Camera2D				camera;
		Camera2D				camera2;
		Player					*player;
		t_texture				*texture;
		vector<vector<char>>	*map;
		int						n_cam;
		int						width;
		int						height;
		int						map_width;
		int						map_height;
		
	public:
		Display(Player* player_list);
		void		DRAW_Background();
		void		DRAW_Player(int id);
		void		DISPLAY_Cam(int id);
		void		UPDATE_Image();
		void		UPDATE_Display();
		int			COUNT_Player(Player *player);
		void		SET_Camera();
		void		SET_Map(vector<vector<char>> *n_map, t_texture *map_texure, int width, int height);
		Camera2D	*GET_Camera(int id);
};

class Game
{
	private:
		Player					player[2];
		Display					display;
		t_texture				texture;
		vector<vector<char>>	map;

	public:
		Game();
		~Game() noexcept;

		void	CHOSE_Lvl();
		void	LOAD_Texture();

		void	HANDLE_Input(int id);
		void	HANDLE_Click(Vector2 position, int id, int hand);
		void	UPDATE_Img();
		
		int 	ADD_Player(string name);
		float 	PLAYER_PosX(int id);
		float 	PLAYER_PosY(int id);
		float 	PLAYER_Dir(int id);
		string	GET_Name_Player(int id);

		Player	*GET_Player(int id);
};


#endif
