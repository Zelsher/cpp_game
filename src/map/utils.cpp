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

int RAY_Collision(Map *map, Vector2 pos, Vector2 end_pos, Vector2 incr)
{
    int pos_type;

    while (pos.x != end_pos.x)
    {
        pos_type = map->GET_Type(Vector2{pos.y, pos.x});
        if (pos_type != GROUND && pos_type != BRICK_GROUND)
            return (1);
        pos.x += incr.x;
        pos.y += incr.y;
    }  
    return (0); 
}

int	IN_Map(Map *map, float X, float Y)
{
	if (X < 0 || Y < 0)
		return (0);
	if (map->GET_Height_Map() < Y || map->GET_Width_Map() < X)
		return (0);
	return (1);
}

int NOT_Wall(Map *map, float X, float Y)
{
    if (!IN_Map(map, X, Y)
        || (map->GET_Type(Vector2{Y, X}) != GROUND && map->GET_Type(Vector2{Y, X}) != BRICK_GROUND))
        return (0);
    return (1);
}

vector<vector<Cell>> Map::OPEN_Map(string file)
{
    vector<vector<Cell>> map;
	string ligne;
	ifstream fichier(file);
    if (!fichier.is_open()) 
	{
        cerr << "Erreur d'ouverture du fichier!" << endl;
        exit(1);
    }
    int y = 0;
    int x = 0;
    while (getline(fichier, ligne)) 
	{
        vector<Cell> ligneCarte;
        for (Cell c : ligne) 
		{
            ligneCarte.push_back(c);
            if (c.GET_Type() >= 48 && c.GET_Type() <= 57)
                LOAD_Spawner(Vector3{(float)x, (float)y, (float)(c.GET_Type() - '0')});
            x++;
        }
        map.push_back(ligneCarte);
        y++;
		x = 0;
    }
    fichier.close();
    return (map);
}
