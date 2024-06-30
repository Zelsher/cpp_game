#include "../inc/game.hpp"

using namespace std;

vector<vector<char>> OPEN_Map(string file)
{
    vector<vector<char>> map;
	string ligne;
	ifstream fichier(file);
    if (!fichier.is_open()) 
	{
        cerr << "Erreur d'ouverture du fichier!" << endl;
        exit(1);
    }
    while (getline(fichier, ligne)) 
	{
        vector<char> ligneCarte;
        for (char c : ligne) 
		{
            ligneCarte.push_back(c);
        }
        map.push_back(ligneCarte);
    }
    fichier.close();
    return (map);
}

void PRINT_Map(const vector<vector<char>>& map)
{
    for (const auto& ligne : map)
	{
        for (char cell : ligne) 
		{
            cout << cell;
        }
        cout << endl;
    }
}
