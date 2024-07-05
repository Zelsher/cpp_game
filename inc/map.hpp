#include "game.hpp"

class Cell
{
	private:
		int	type;
		int	step;
	public:
		Cell(int n_type) : type(n_type), step(0) {}
		~Cell(){}

		void	SET_Type(int n_type) { type = n_type; }
		void	SET_Step(int n_step) { step = n_step; }

		int	GET_Type() { return type; }
		int	GET_Step() { return step; }
};
