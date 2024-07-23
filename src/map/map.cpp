#include "../../inc/game.hpp"

Map::Map(Game *p_game)
{
	game = p_game;
}

Map::~Map()
{

}

void	Map::SET_Map(string file_name)
{
	int	lvl = 1;//Offrir un choix
		if (lvl == 1)
	map = OPEN_Map(file_name);
	width = map[1].size();
	height = map.size();
//Mettre / les joueur sur P
}



void    Map::LOAD_Spawner(Vector3 pos)
{
    cout << pos.x << " " << pos.y << " " << pos.z << endl;
    spawner.push_back(pos);
}

void	Map::UPDATE_Spawner()
{
	for (size_t i = 0; i < spawner.size(); i++)
	{
		//cout << spawner[i].z << endl;
		if (spawner[i].z && rand() % 9 + 1 < spawner[i].z)
		{
			//cout << spawner[i].x << " " << spawner[i].y << endl;
			game->CREATE_Mob(ENNEMY, Vector2{spawner[i].x, spawner[i].y});
		}
	}
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
