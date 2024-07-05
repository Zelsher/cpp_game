#include "game.hpp"

#define SPAWN1 1
#define GROUND 'G'
#define WALL 'W'
#define HOUSE_BASE 'H'
#define HOUSE 'h'
#define TREE_BASE 'T'
#define TREE 't'
#define BRICK_GROUND 'b'
#define ROAD_1 "-"
#define ROAD_2 "|"
#define ROAD_3 "+"

class Game;

class Cell
{
	private:
		char	type;
		int		step;
	public:
		Cell(int n_type) : type(n_type), step(0) {}
		~Cell(){}

		void	SET_Type(int n_type) { type = n_type; }
		void	SET_Step(int n_step) { step = n_step; }

		char	GET_Type() { return type; }
		int	GET_Step() { return step; }
};
