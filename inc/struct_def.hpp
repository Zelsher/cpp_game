#ifndef STRUCT_DEF_HPP
#define STRUCT_DEF_HPP


typedef struct s_texture_pack
{
	Texture2D		ennemy;
}			t_texture_pack;

typedef struct s_texture
{
	Texture2D		ground_1;
	Texture2D		wall_1;
	Texture2D		house_1;
	Texture2D		tree_1;
	Texture2D		player_1;
	Texture2D		player_2;
	Texture2D		r_hand;
	Texture2D		l_hand;
	Texture2D		tile1;
	Texture2D		tile2;
	Texture2D		item[10];
	t_texture_pack	texture_pack;
}			t_texture;


#endif
