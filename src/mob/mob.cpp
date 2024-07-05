#include "../../inc/game.hpp"

Mob::Mob(Game *p_game, t_texture_pack *p_texture, int n_type, Vector2 n_pos)
{
	game = p_game;
	texture = p_texture;
	type = n_type;
	pos = n_pos;
}

Mob::~Mob()
{

}