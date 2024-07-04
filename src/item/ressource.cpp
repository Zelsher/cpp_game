#include "../../inc/game.hpp"

Ressource::Ressource(Color n_color)
{
	value = 100.0f;
	color = n_color;
}

Ressource::~Ressource()
{
}

void	Ressource::ADD_Value(float i)
{
	if (value + i < 0)
		return ;
	else if (value + i > 100)
		value = 100;
	else
		value += i;
}
