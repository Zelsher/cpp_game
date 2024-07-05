#ifndef FUNCTIONS_HPP
# define FUNCTIONS_HPP

#include <game.hpp>
#include <iostream>
#include <string>

vector<vector<Cell>>	OPEN_Map(string file);
void 					PRINT_Map(const vector<vector<Cell>>& carte);
int						IN_Map(vector<vector<Cell>> *map, float X, float Y);
int 					NOT_Wall(vector<vector<Cell>> *map, float X, float Y);
#endif
