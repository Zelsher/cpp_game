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

		bool	run;
		float	hp;
		float	speed;
		Ressource	stamina;
		Ressource	mana;

		Weapon		hands[2];
		Weapon		pocket[2];
	public:
		Player();
	
		int 	ACTIVATE_Player(string new_name, int new_id);
		void	UPDATE_Items();
		int		EXIST();
	
		void	SET_Pos(Vector2 pos) {	posX = pos.x;posY = pos.y; }
		void	SET_PosX(float new_posX) { posX = new_posX; }
		void	SET_PosY(float new_posY) { posY = new_posY; }
		void	SET_Dir(float x, float y);
		void	ADD_PosX(float new_posX);
		void	ADD_PosY(float new_posY);
		void	ADD_Stamina(float i);
		void	ADD_Mana(float i);
		void	ADD_Item(Weapon item);


		Weapon		*GET_Hand(int hand);
		int			GET_Hand_Type(int hand);
		void		SWITCH_Weapon(int hand);
		void		RELOAD_Weapons();

		bool		RUNNING() { return run; }
		void		RUN() { run = 1; }
		void		STOP_Run() { run = 0; }

		Ressource	GET_Stamina() const { return stamina; }
		Ressource	GET_Mana() const { return mana; }
		Ressource	*GET_Mana_p() { return &mana; }
		float		GET_Stamina_V() const { return stamina.GET_Value(); }
		float		GET_Mana_V() const { return mana.GET_Value(); }

		float		GET_Speed() const { return speed; }
		float		GET_Hp() const { return hp; }
		Vector2		GET_Pos() const { return {posX, posY}; }
		float		GET_PosX() const { return posX; }
		float		GET_PosY() const { return posY; }
		float		GET_Rot() const { return rot; }
		string		GET_Name() const { return name; }
};

#endif
