#ifndef PLAYER_HPP
# define PLAYER_HPP

#include <iostream>
#include <string>

#include "game.hpp"
#include "item.hpp"

class Inventory
{
	private:
		Item	cell[4];
	public:
		Inventory();
		~Inventory();

		int	OPENED() { return 1; }
};

class Player
{
	private:
		int		id;
		string	name;
		bool	enable;

		float	posY;
		float	posX;
		Vector2	dir;
		float	rot;

		bool		run;
		float		hp;
		float		speed;
		Ressource	stamina;
		Ressource	mana;

		Item		hands[2];
		Item		pocket[2];
		Inventory	inventory;

		Sound		switch_sound;
	public:
		Player();
	
		int 	ACTIVATE_Player(string new_name, int new_id);
		void	UPDATE_Items();
		bool	EXIST() const { return (enable); }
	
		void	SET_Pos(Vector2 pos) {	posX = pos.x;posY = pos.y; }
		void	SET_PosX(float new_posX) { posX = new_posX; }
		void	SET_PosY(float new_posY) { posY = new_posY; }
		void	SET_Dir(float x, float y);
		void	ADD_PosX(float new_posX);
		void	ADD_PosY(float new_posY);
		void	ADD_Stamina(float i);
		void	ADD_Mana(float i);
		void	ADD_Hp(float i);
		void	ADD_Item(Item item);


		Item		*GET_Hand(int hand);
		int			GET_Hand_Type(int hand);
		void		SWITCH_Item(int hand);
		void		RELOAD_Weapons();
		int			IS_Inventory_Open() { return inventory.OPENED(); }

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
