#ifndef ITEM_HPP
# define ITEM_HPP

#include "game.hpp"

class Ressource
{
	private:
		float	value;
		Color	color;

	public:
		Ressource(Color n_color);
		~Ressource();

	void	ADD_Value(float i) { value += i; }
	float	GET_Value() const { return value; }
	Color	GET_Color() const { return color; }

};



class Weapon
{
	private:
		bool		nothing;
		int			type;
		float		damage;
		Ressource	*ressource;
		Color		color_bar;
	public:
		Weapon();
		~Weapon();
		void	SET_Weapon(int w_type, Ressource *Ressource);
		
		int		GET_Type() { return(type); }
		Color	GET_Color() { return(ressource->GET_Color()); }
		
		Ressource	*GET_Ressource() { return(ressource); }

		bool	Nothing() { return(nothing); }
};



#endif
