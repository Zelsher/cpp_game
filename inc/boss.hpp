#include "game.hpp"

#define BOSS1 1

class Game;
class Ressource;

class Boss
{
	private:
		int		type;
		int		hp;// temps de lhappening
        int 	sleeping;
		int     death;
		int		hitbox_n;
		int		width;
		int		height;

        Ressource   *mana;

        Vector2     pos;
        Vector2     hitbox[8];

        t_texture_pack	*texture;
		Texture2D		*actual_texture;

        Game           *game;
    public:
        Boss(Game *p_game, t_texture_pack *p_texture, int n_type, Vector2 n_pos);
        ~Boss();

		Vector2		*GET_Boss_Hitbox() { return hitbox; }
		int			GET_Width() { return width; }
		int			GET_Height() { return height; }
		int			GET_Hitbox_n() { return hitbox_n; }
		int			GET_Hp() { return (hp); }
		Vector2		GET_Pos() const { return pos; }
		Texture2D	GET_Texture(int id) const { (void)id; return (*actual_texture); }


		void		SET_Pos(Vector2 n_pos) { pos.x = n_pos.x;pos.y = n_pos.y; }
		void		SET_Hp(int n_hp) { hp = n_hp; }
		void		ADD_Hp(int n_hp) { hp += n_hp; }

		int			SLEEPING() { return (sleeping); }
		void		WAKE_Up() { sleeping = 0; }

		bool		HIT_Hitbox(Vector2 pos);
		int			UPDATE_Boss(vector<vector<Cell>> *map);
};
