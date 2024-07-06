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

class Cell
{
	private:
		char	type;
		int		step;

		vector<Mob*>	mob;

		Player	*player;
	public:
		Cell(int n_type) : type(n_type), step(0), player(NULL) {}
		~Cell(){}

		void	SET_Type(int n_type) { type = n_type; }
		void	SET_Step(int n_step) { step = n_step; }

		char	GET_Type() { return type; }
		int		GET_Step() { return step; }


		void	MAP_Player(Player *n_player) { player = n_player; }
		void	MAP_Mob(Mob *n_mob) { mob.push_back(n_mob); }

		void	DELETE_Player() { player = NULL; }
		void	DELETE_Mob(int id) { mob.erase(mob.begin() + id); }
		Mob		*GET_Mob(int id);
		Player	*PLAYER_Near() { return(player); }
};
