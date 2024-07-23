#include "game.hpp"

class Player;
class Event;
class Map;
class Boss;
class Mob;

class Display
{
	private:
		Camera2D				camera;
		Player					*player;
		t_texture				*texture;
		Event					*event;
		Map						*map;
		vector<Mob>				*mobs;
		vector<Boss>			*boss;

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
		void		DRAW_Boss();

		void		DISPLAY_Game(int id);
		void		UPDATE_Image();

		void		GET_Display_Width(int id);
		void		UPDATE_Display();
		int			COUNT_Player(Player *player);

		Camera2D	*GET_Camera(int id) { (void)id; return (&camera); }
		void		SET_Camera();
		void		SET_Map(Map *n_map, t_texture *map_texture, int width, int height);
		void		SET_Event(Event *n_event, vector<Boss> *n_boss, vector<Mob> *n_mobs) { event = n_event; boss = n_boss; mobs = n_mobs; }
};