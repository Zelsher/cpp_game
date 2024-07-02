#ifndef ITEM_HPP
# define ITEM_HPP

#include "game.hpp"

class ressource
{
	private:
		int	value;
		int	color;

	public:
		ressource();
		~ressource();
};



class Weapon
{
	private:
		int		type;
		float	damage;
		float	*ressource;
		Color	color_bar;
	public:
		Weapon();
		void	SET_Weapon(int w_type);
		int		GET_Type();
		int		GET_Color();
};



#endif
