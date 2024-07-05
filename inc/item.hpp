#ifndef ITEM_HPP
# define ITEM_HPP

//Item Type
#define	TP_RING 1
#define	MAGIC_STICK 2
#define PISTOL 3
#define UZI 4
#define N_ITEM

//Resspource Type
#define MANA 1
#define AMMO 2

#include <iostream>
#include <string>

typedef struct s_audio
{
	Sound	reload;
	Sound	end_reload;
	Sound	use;
}			t_audio;

class Ressource
{
	private:
		float	value;
		Color	color;

	public:
		Ressource(Color n_color);
		~Ressource();

	void	ADD_Value(float i);
	void	SET_Value(float i) { value = i; }
	float	GET_Value() const { return value; }
	Color	GET_Color() const { return color; }

};

class Player;
class Game;

class Item
{
	private:
		bool		empty;
		int			type;
		float		damage;

		int			ressource_type;
		Ressource	*ressource;
		Color		color_bar;

		int			reload_time;
		int			reload;
		int			cooldown_time;
		int			cooldown;

		t_audio		audio;
	public:
		Item();
		~Item();
		void		SET_Item(int w_type, Ressource *Ressource);
		
		int			GET_Type() { return(type); }
		Color		GET_Color() { return(ressource->GET_Color()); }
		
		Ressource	*GET_Ressource() { return(ressource); }
		int			GET_Ressource_Type() { return(ressource_type); }
	
		void		UPDATE_Item();
		void		RELOAD();
		int			RELOADING();
		void		COOLDOWN();
		int			IS_Cooldown();
		void		USE(Vector2 player_pos, Vector2 use_pos, Player *t_player, vector<vector<Cell>> *map, Game *game);
	
		bool		EMPTY() { return(empty); }
};



#endif
