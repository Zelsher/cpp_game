#ifndef FUNCTIONS_HPP
# define FUNCTIONS_HPP

#include <game.hpp>
#include <iostream>
#include <string>

vector<vector<char>>	OPEN_Map(string file);
void 					PRINT_Map(const vector<vector<char>>& carte);
int						moove_player_valid(vector<vector<char>> *map, float X, float Y);
#endif
