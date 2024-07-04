#include "game.hpp"


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

		void	UPDATE_Happening();

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
		void	UPDATE_EVENTS();

		Happening	HAPPENING(int id) { return happening[id]; }
		int			HAPPENING_N() const { return last_happening; }
};

