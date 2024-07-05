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

vector<vector<Cell>> OPEN_Map(string file)
{
    vector<vector<Cell>> map;
	string ligne;
	ifstream fichier(file);
    if (!fichier.is_open()) 
	{
        cerr << "Erreur d'ouverture du fichier!" << endl;
        exit(1);
    }
    while (getline(fichier, ligne)) 
	{
        vector<Cell> ligneCarte;
        for (Cell c : ligne) 
		{
            ligneCarte.push_back(c);
        }
        map.push_back(ligneCarte);
    }
    fichier.close();
    return (map);
}

void PRINT_Map(const vector<vector<Cell>>& map)
{
    for (const auto& ligne : map)
	{
        for (Cell cell : ligne) 
		{
            cout << cell.GET_Type();
        }
        cout << endl;
    }
}

int	IN_Map(vector<vector<Cell>> *map, float X, float Y)
{
	if (X < 0 || Y < 0)
		return (0);
	if ((*map).size() < Y || (*map)[(int)Y].size() < X)
		return (0);
	//cout << (*map)[(int)Y][(int)X] << endl;
	return (1);
}

int NOT_Wall(vector<vector<Cell>> *map, float X, float Y)
{
    if (!IN_Map(map, X, Y) || (*map)[(int)Y][(int)X].GET_Type() != GROUND)
        return (0);
    return (1);
}
