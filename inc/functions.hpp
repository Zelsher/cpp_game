#ifndef FUNCTIONS_HPP
# define FUNCTIONS_HPP

#include <game.hpp>
#include <iostream>
#include <string>

vector<vector<char>>	OPEN_Map(string file);
void 					PRINT_Map(const vector<vector<char>>& carte);
int						IN_Map(vector<vector<char>> *map, float X, float Y);
#endif
