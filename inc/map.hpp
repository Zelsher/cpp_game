#include "game.hpp"

#define SPAWN1 1
#define GROUND 'D'
#define WALL 'W'
#define HOUSE_BASE 'H'
#define HOUSE 'h'
#define TREE_BASE 'T'
#define TREE 't'
#define BRICK_GROUND 'G'
#define ROAD_1 "-"
#define ROAD_2 "|"
#define ROAD_3 "+"

class Game;
class Mob;
class Player;
class Boss;

class Cell
{
	private:
		char	type;
		int		step;

		vector<Mob*>	mob;
		vector<Boss*>	boss;

		Player	*player;
	public:
		Cell(int n_type) : type(n_type), step(0), player(NULL) {}
		~Cell(){}

		void	SET_Type(int n_type) { type = n_type; }
		void	SET_Step(int n_step) { step = n_step; }
		void	ADD_Player(Player *n_player) { player = n_player; }
		void	ADD_Mob(Mob *n_mob) { mob.push_back(n_mob); }
		void	ADD_Boss(Boss *n_boss) 
		{ 
			if (boss.empty() || (!boss.empty() && n_boss != boss[0]))
				boss.push_back(n_boss);
		}//condition if a changer
	
		char	GET_Type() { return type; }
		int		GET_Step() { return step; }
		Mob		*GET_Mob(int id);
		Boss	*GET_Boss(int id);

		void	DEL_Player() { player = NULL; }
		void	DEL_Mob(int id) { mob.erase(mob.begin() + id); }
		void	DEL_Boss(Boss *p_boss) { (void)p_boss; boss.clear(); }
		Player	*PLAYER_Near() { return(player); }
};

class	Map
{
	private:
		vector<vector<Cell>>	map;
		int						width;
		int						height;

		vector<Vector3>			spawner;//z=proba
		Game					*game;
	public:
		Map(Game* p_game);
		~Map();
		
		vector<vector<Cell>>	OPEN_Map(string file);
		void					SET_Map(string file_name);
		
	
		int		GET_Type(Vector2 pos) { return(map[pos.y][pos.x].GET_Type()); }
		int		GET_Width_Map() { return (width); }
		int		GET_Height_Map() { return (height); }
		char	GET_Cell_Type(Vector2 pos) { return map[pos.y][pos.x].GET_Type(); }
		Mob		*GET_Mob(int id, Vector2 pos) { return(map[pos.y][pos.x].GET_Mob(id)); };
		Boss	*GET_Boss(int id, Vector2 pos) { return(map[pos.y][pos.x].GET_Boss(id)); };

		void	MAP_Player(Player *n_player, Vector2 pos) { map[pos.y][pos.x].ADD_Player(n_player);  }
		void	MAP_Mob(Mob *n_mob, Vector2 pos) { map[pos.y][pos.x].ADD_Mob(n_mob);  }
		void	MAP_Boss(Boss *n_boss, Vector2 pos) { map[pos.y][pos.x].ADD_Boss(n_boss);  }
		void	LOAD_Spawner(Vector3 pos);
		void	UPDATE_Spawner();

		void	DELETE_Player(Vector2 pos) { map[pos.y][pos.x].DEL_Player(); }
		void	DELETE_Mob(int id, Vector2 pos) { map[pos.y][pos.x].DEL_Mob(id); }//changer id par pointeur?
		void	DELETE_Boss(Boss *p_boss, Vector2 pos) { map[pos.y][pos.x].DEL_Boss(p_boss); }
		Player	*PLAYER_Near(Vector2 pos) { return(map[pos.y][pos.x].PLAYER_Near()); }//chamger de nom
};
