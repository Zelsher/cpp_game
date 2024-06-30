#ifndef FUNCTIONS_HPP
# define FUNCTIONS_HPP

#include <game.hpp>
#include <iostream>
#include <string>

void					HANDLE_Input(Player *player, vector<vector<char>> *map);
void					DISPLAY_Cam(Player *player, int width, int height, int id, vector<vector<char>> *map, int max_mapY);
vector<vector<char>>	OPEN_Map(string file);
void 					PRINT_Map(const vector<vector<char>>& carte);

#endif
