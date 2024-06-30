#ifndef PLAYER_HPP
# define PLAYER_HPP

#include <iostream>
#include <string>
#include "weapon.hpp"

class Player
{
	private:
		int		enable;
		int		id;
		string	name;
		float	posY;
		float	posX;
		float	dir;
		Weapon	weapon;
	public:
		Player();
	
		int ACTIVATE_Player(string new_name, int new_id);
		int	EXIST();
	
		void	SET_PosX(float new_posX);
		void	SET_PosY(float new_posY);

		void	ADD_PosX(float new_posX);
		void	ADD_PosY(float new_posY);

		float	GET_PosX();
		float	GET_PosY();
		float	GET_Dir();
		string	GET_Name();
};

#endif
