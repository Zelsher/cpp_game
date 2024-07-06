#include "../../inc/game.hpp"

Mob::Mob(Game *p_game, t_texture_pack *p_texture, int n_type, Vector2 n_pos)
{
	death = 0;
	game = p_game;
	texture = p_texture;
	type = n_type;
	pos = n_pos;
	cooldown = 0;
	hp = 100;
	if (type == ENNEMY)
		cooldown_time = 100;
}

Mob::~Mob()
{

}

void	Game::CREATE_Mob(int type, Vector2 pos)
{
	Mob	ennemy(this, &texture.texture_pack, type, pos);
	mobs.push_back(ennemy);
}