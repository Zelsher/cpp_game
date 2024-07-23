#ifndef HEADER_HPP
# define HEADER_HPP
//vector<vector<Cell>>	*map;

#define WIDTH 800//1366 1980
#define HEIGHT 600//768 1080

#define	TILE_SIZE 64

#define	RIGHT 1
#define	LEFT 0


# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# include <raylib.h>
//# include "raylib/src/raylib.h"
# include <cmath>
# include <fstream>
# include <vector>
# include <iostream>
# include <string>

using namespace std;

#include "struct_def.hpp"
#include "display.hpp"
#include "map.hpp"
#include "player.hpp"
#include "item.hpp"
#include "event.hpp"
#include "functions.hpp"
#include "mob.hpp"
#include "boss.hpp"

class Game
{
	private:
		Player					player[2];
		Display					display;
		Map						map;
		t_texture				texture;
	
		Event					event;
		vector<Mob>				mobs;
		vector<Boss>			boss;

		size_t					frame;

	public:
		Game();
		~Game();

		void					CHOSE_Lvl();
		void					LOAD_Spawner(Vector3 pos);
		void					LOAD_Texture();
		vector<vector<Cell>>	OPEN_Map(string file);

		void		HANDLE_Input(int id);
		void		HANDLE_Click(Vector2 position, int id, int hand);
		void		UPDATE_Game();
		
		int 		ADD_Player(string name);
		float 		PLAYER_PosX(int id) const {return (player[id].GET_Pos().x); }
		float 		PLAYER_PosY(int id) const {return (player[id].GET_Pos().y); }
		float 		PLAYER_Dir(int id) const {return (player[id].GET_Rot());}
		string		GET_Name_Player(int id) const { return player[id].GET_Name(); }

		void		CREATE_Mob(int type, Vector2 pos);
		void		CREATE_Boss(int type, Vector2 pos);

		Player		*GET_Player(int id) { return(&player[id]); }
		Event		*GET_Event() { return &event; }
		t_texture	*GET_Texture() { return &texture; }
};


#endif
