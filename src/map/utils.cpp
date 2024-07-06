#include "../../inc/game.hpp"

Vector2 FIND_Direction(Vector2 start_pos, Vector2 end_pos)
{
    Vector2 pos;

	float y1 = end_pos.y;
	float y0 = start_pos.y;
	float x1 = end_pos.x;
	float x0 = start_pos.x;

    // Paramètres de la simulation
    double v = 0.1; // vitesse constante (0.1 unité par seconde)
    double theta = atan2(y1 - y0, x1 - x0);
    pos.x = v * cos(theta);
    pos.y = v * sin(theta);

	//cout << pos.y  << " " <<  pos.x << endl;
    return (pos);
}

int RAY_Collision(vector<vector<Cell>> *map, Vector2 pos, Vector2 end_pos, Vector2 incr)
{
    int pos_type;

    while (pos.x != end_pos.x)
    {
        pos_type = (*map)[(int)pos.y][(int)pos.x].GET_Type();
        if (pos_type != GROUND && pos_type != BRICK_GROUND)
            return (1);
        pos.x += incr.x;
        pos.y += incr.y;
    }  
    return (0); 
}
