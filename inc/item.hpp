#ifndef ITEM_HPP
# define ITEM_HPP

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

		void		UPDATE_Item();
		void		RELOAD();
		int			RELOADING();
		void		COOLDOWN();
		int			IS_Cooldown();
		void		USE(Vector2 player_pos, Vector2 use_pos, Player *t_player, vector<vector<char>> *map, Game *game);
	
		bool		EMPTY() { return(empty); }
};



#endif
