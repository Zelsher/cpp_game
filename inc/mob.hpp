#include "game.hpp"
#include "struct_def.hpp"

#define ENNEMY 1

class Game;

class	Mob
{
	private:
		int				type;
		Vector2			pos;
		Vector2			dir;

		t_texture_pack	*texture;
		Game			*game;
	public:
		Mob(Game *p_game, t_texture_pack *p_texture, int n_type, Vector2 n_pos);
		~Mob();

		void		SET_Pos(Vector2 n_pos) { pos.x = n_pos.x;pos.y = n_pos.y; }
		Vector2		GET_Pos() const { return pos; }
		Texture2D	GET_Texture(int id) const { (void)id; return texture->ennemy; }

		void		MOOVE_Ennemy(vector<vector<Cell>> *map);
		void		ACTION(vector<vector<Cell>> *map);

};