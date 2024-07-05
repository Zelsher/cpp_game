#include "game.hpp"

#define TP 0
#define MAGIC_SPELL 1
#define SHOOT 2

class Game;

class Happening
{
	private:
		int	type;
		int	duration;// temps de lhappening
		int	happen;// temps ecoule pour lhappening

		Vector2	pos;

		float	incrX;
		float	incrY;
		Texture	*texture;
	public:
		Happening();
		Happening(int type, Vector2 origin_pos, Vector2 use_pos, Game *game);
		~Happening();

		int	UPDATE_Happening(vector<vector<Cell>> *map);

		Vector2	GET_Pos() { return pos; }
		Texture	GET_Texture() { return *texture; }
};

class Event
{
	private:
		vector<Happening>	happening;
		int					last_happening;
	public:
		Event();
		~Event();

		Event	*EVENT() { return this; }
		void	ADD_Event(int type, Vector2 origin_pos, Vector2 use_pos, Game *game);
		void	UPDATE_EVENTS(vector<vector<Cell>> *map);

		Happening	HAPPENING(int id) { return happening[id]; }
		int			HAPPENING_N() const { return last_happening; }
};

