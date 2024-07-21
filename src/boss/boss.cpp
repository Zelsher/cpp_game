#include "../inc/game.hpp"

int    Boss::UPDATE_Boss(vector<vector<Cell>> *map)
{
    Vector2 new_pos = pos;//changer par lalgo de deplacement

    for (int Y = height * -1; Y != height; Y++)
    {
        for (int X = width * -1; X != width; X++)
        {
            (*map)[pos.y + Y][pos.x + X].DELETE_Boss(this);
            if (IN_Map(map, new_pos.x + X, new_pos.y + Y))
                (*map)[new_pos.y + Y][new_pos.x + X].MAP_Boss(this);
        }
    }
    actual_texture = &texture->boss;
    pos = new_pos;
    if (hp > 0)
        return (1);
    return (0);     
}

bool Boss::HIT_Hitbox(Vector2 hit_pos)
{
    bool inside = false;
    float   xi, xj, yi, yj;
    int     j = 0;
    for (int i = 0 ; i < hitbox_n; i++)
	{
        if (i + 1 == hitbox_n)
        {
            xi = hitbox[i].x + pos.x;
            yi = hitbox[i].y + pos.y;
            xj = hitbox[0].x + pos.x;
            yj = hitbox[0].y + pos.y;
        }
        else
        {
            xi = hitbox[i].x + pos.x; 
            yi = hitbox[i].y + pos.y;
            xj = hitbox[i + 1].x + pos.x; 
            yj = hitbox[i + 1].y + pos.y;
        }
        bool intersect = ((yi > hit_pos.y) != (yj > hit_pos.y)) &&
                         (hit_pos.x < (xj - xi) * (hit_pos.y - yi) / (yj - yi) + xi);
        if (intersect) {
            inside = !inside;
            j++;
        }
    }
    return inside;
}

Boss::Boss(Game *p_game, t_texture_pack *p_texture, int n_type, Vector2 n_pos)
{
    type = n_type;
    hp = 1000;
    mana = new Ressource(ORANGE);
    width = 2;
    height = 2;
    if (n_type == BOSS1)
    {
        hitbox_n = 7;
        hitbox[0].x = -1.5;
        hitbox[0].y = 1;

        hitbox[1].x = -1.5;
        hitbox[1].y = -1;

        hitbox[2].x = -1;
        hitbox[2].y = -2;

        hitbox[3].x = 1;
        hitbox[3].y = -2;

        hitbox[4].x = 1.5;
        hitbox[4].y = -1;

        hitbox[5].x = 1.5;
        hitbox[5].y = 1;

        hitbox[6].x = 1;
        hitbox[6].y = 2;

        hitbox[7].x = -1;
        hitbox[7].y = 2;
    }
    pos = n_pos;
	death = 0;
	sleeping = 1;
	game = p_game;
	texture = p_texture;
	type = n_type;
	pos = n_pos;
	hp = 100;
}

Boss::~Boss()
{

}
