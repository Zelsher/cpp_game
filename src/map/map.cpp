#include "../../inc/game.hpp"

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
