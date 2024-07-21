#include "../../inc/game.hpp"

void    Game::LOAD_Spawner(Vector3 pos)
{
    cout << pos.x << " " << pos.y << " " << pos.z << endl;
    spawner.push_back(pos);
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
    if (!IN_Map(map, X, Y)
        || ((*map)[(int)Y][(int)X].GET_Type() != GROUND && (*map)[(int)Y][(int)X].GET_Type() != BRICK_GROUND))
        return (0);
    return (1);
}

Mob*		Cell::GET_Mob(int id) 
{
    if (id < (int)mob.size())
        return(mob[id]);
    return (NULL);
}

Boss*		Cell::GET_Boss(int id) 
{
    if (id < (int)boss.size())
        return(boss[id]);
    return (NULL);
}

vector<vector<Cell>> Game::OPEN_Map(string file)
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
void	Game::CHOSE_Lvl()
{
	int	width;
	int	height;

	int	lvl = 1;//Offrir un choix
		if (lvl == 1)
	map = OPEN_Map("asset/map/map2");
	width = map[1].size();
	height = map.size();
	LOAD_Texture();
	display.SET_Map(&map, &texture, width, height);
	//Mettre / les joueur sur P
}