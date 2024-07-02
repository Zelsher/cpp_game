#include "../inc/game.hpp"

ressource::ressource()
{
	}

ressource::~ressource()
{
}

Weapon::Weapon()
{
	type = 0;
}
void	Weapon::SET_Weapon(int w_type)
{
	(void)w_type;
}
int	Weapon::GET_Type()
{
	return(type);
}
int	Weapon::GET_Color()
{
	return(type);
}