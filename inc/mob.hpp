#include "game.hpp"
#include "struct_def.hpp"

#define ENNEMY 1
#define SLEEPER 2

class Game;

class	Mob
{
	private:
		int				hp;
		int				type;
		Vector2			pos;
		Vector2			dir;
		int				cooldown;
		int				cooldown_time;

		int				sleeping;
		int				death;

		t_texture_pack	*texture;
		Game			*game;
	public:
		Mob(Game *p_game, t_texture_pack *p_texture, int n_type, Vector2 n_pos);
		~Mob();

		void		SET_Pos(Vector2 n_pos) { pos.x = n_pos.x;pos.y = n_pos.y; }
		void		SET_Hp(int n_hp) { hp = n_hp; }
		void		ADD_Hp(int n_hp) { hp += n_hp; }

		int			SLEEPING() { return (sleeping); }
		void		WAKE_Up() { sleeping = 0; }
		int			GET_Hp() { return (hp); }
		Vector2		GET_Pos() const { return pos; }
		Texture2D	GET_Texture(int id) const { (void)id; return texture->ennemy; }

		int			COOLDOWN();
		void		MOOVE_Ennemy(Map *map);
		void		MOOVE_Sleeper(Map *map);
		int			ACTION(Map *map);

};