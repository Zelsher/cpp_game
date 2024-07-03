#include "../inc/game.hpp"

Ressource::Ressource(Color n_color)
{
	value = 100.0f;
	color = n_color;
}

Ressource::~Ressource()
{
}

Weapon::Weapon() : nothing(1), type(0)
{
}

Weapon::~Weapon()
{
}

void	Weapon::SET_Weapon(int w_type, Ressource *n_ressource)
{
	if (n_ressource)
		ressource = n_ressource;
	else
		ressource = NULL;
	type = w_type;
	nothing = 0;
}
