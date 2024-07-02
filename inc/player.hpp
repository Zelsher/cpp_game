#ifndef PLAYER_HPP
# define PLAYER_HPP

#include <iostream>
#include <string>
#include "item.hpp"

class Player
{
	private:
		int		enable;
		int		id;
		string	name;
		float	posY;
		float	posX;
		Vector2	dir;
		float	rot;
		float	hp;
		float	speed;
		float	stamina;
		float	mana;
		Weapon	*left_hand;
		Weapon	*right_hand;
	public:
		Player();
	
		int ACTIVATE_Player(string new_name, int new_id);
		int	EXIST();
	
		void	SET_Pos(Vector2 pos);
		void	SET_PosX(float new_posX);
		void	SET_PosY(float new_posY);
		void	SET_Dir(float x, float y);
		void	SET_Stamina(float i);
		void	SET_Mana(float i);
		void	ADD_Item(Weapon *item);
		void	ADD_PosX(float new_posX);
		void	ADD_PosY(float new_posY);

		Weapon	*GET_Hand(int hand);
		int		GET_Stamina();
		float	GET_Speed();
		float	GET_Hp();
		float	GET_Mana();
		float	GET_PosX();
		float	GET_PosY();
		float	GET_Rot();
		string	GET_Name();
};

#endif
