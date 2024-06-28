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
		Player()
		{
			enable = 0;
		}
		int Activate_Player(string new_name, int new_id)
		{
			id = new_id;
			name = new_name;
			enable = 1;
			//fill pos
			return (0);
		}
		int	EXIST()
		{
			return (enable);
		}
		float	GET_PosX()
		{
			return (posX);
		}
		float	GET_PosY()
		{
			return (posY);
		}
		float	GET_Dir()
		{
			return (dir);
		}
		string	GET_Name()
		{
			return (name);
		}
};

#endif
