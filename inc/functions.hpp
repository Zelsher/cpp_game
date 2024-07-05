#ifndef FUNCTIONS_HPP
# define FUNCTIONS_HPP

#include <game.hpp>
#include <iostream>
#include <string>

void 					PRINT_Map(const vector<vector<Cell>>& carte);
int						IN_Map(vector<vector<Cell>> *map, float X, float Y);
int 					NOT_Wall(vector<vector<Cell>> *map, float X, float Y);
Vector2 				FIND_Direction(Vector2 start_pos, Vector2 end_pos);

#endif
