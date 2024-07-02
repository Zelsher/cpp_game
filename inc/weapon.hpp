#ifndef WEAPON_HPP
# define WEAPON_HPP

#include "game.hpp"

class Weapon
{
	private:
		int	type;
		float	damage;

	public:
		Weapon()
		{
			type = 0;
		}
		void	SET_Weapon(int w_type)
		{
			type = w_type;
			if (type == TP_RING)
			{
				damage = 0;
			}
		}
		int	GET_Type()
		{
			return(type);
		}
};

#endif
