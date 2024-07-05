#ifndef HEADER_HPP
# define HEADER_HPP
//vector<vector<Cell>>	*map;
using namespace std;

#define WIDTH 2200
#define HEIGHT 1200

#define	TILE_SIZE 64

#define	RIGHT 1
#define	LEFT 0

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# include "raylib.h"
# include <cmath>
# include <fstream>
# include <vector>
# include <iostream>
# include <string>

#include "struct_def.hpp"
#include "map.hpp"
#include "player.hpp"
#include "item.hpp"
#include "event.hpp"
#include "functions.hpp"
#include "mob.hpp"

class Display
{
	private:
		Camera2D				camera;
		Player					*player;
		t_texture				*texture;
		Event					*event;
		vector<Mob>				*mobs;
		vector<vector<Cell>>	*map;

		int						n_cam;
		int						width;
		int						height;
		Vector2					display_Max;
		Vector2					display_Min;

		Vector2					display_size;//taille du fond afficher
		int						map_width;
		int						map_height;
		
	public:
		Display(Player* player_list);
		void		DRAW_Background();
		void		DRAW_Player_Item(int id);
		void		DRAW_Player(int id);
		void		DRAW_Events();
		void		DRAW_Mobs();

		void		DISPLAY_Game(int id);
		void		UPDATE_Image();

		void		GET_Display_Width(int id);
		void		UPDATE_Display();
		int			COUNT_Player(Player *player);

		Camera2D	*GET_Camera(int id) { (void)id; return (&camera); }
		void		SET_Camera();
		void		SET_Map(vector<vector<Cell>> *n_map, t_texture *map_texure, int width, int height);
		void		SET_Event(Event *n_event) { event = n_event; }
		void		SET_Mobs(vector<Mob> *n_mobs) { mobs = n_mobs; }
};

class Game
{
	private:
		Player					player[2];
		Display					display;
		Event					event;
		t_texture				texture;
		vector<Mob>				mobs;
		vector<vector<Cell>>	map;

	public:
		Game();
		~Game() noexcept;

		void		CHOSE_Lvl();
		void		LOAD_Texture();

		void		HANDLE_Input(int id);
		void		HANDLE_Click(Vector2 position, int id, int hand);
		void		UPDATE_Game();
		
		int 		ADD_Player(string name);
		float 		PLAYER_PosX(int id) const {return (player[id].GET_PosX()); }
		float 		PLAYER_PosY(int id) const {return (player[id].GET_PosY()); }
		float 		PLAYER_Dir(int id) const {return (player[id].GET_Rot());}
		string		GET_Name_Player(int id) const { return player[id].GET_Name(); }

		void		CREATE_Mob(int type, Vector2 pos);

		Player		*GET_Player(int id) { return(&player[id]); }
		Event		*GET_Event() { return &event; }
		t_texture	*GET_Texture() { return &texture; }
};


#endif
