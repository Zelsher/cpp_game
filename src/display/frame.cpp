#include "../../inc/game.hpp"


void	Display::DRAW_Background(int id)
{
	//display.GET_Camera(id)->zoom
	int y_min = (player[id].GET_PosY() - ((HEIGHT / TILE_SIZE) / 2) / GET_Camera(id)->zoom) - 4;
	if (y_min < 0)
		y_min = 0;

	int y_max = (player[id].GET_PosY() + ((HEIGHT / TILE_SIZE) / 2) / GET_Camera(id)->zoom) + 1;
	if (y_max > (int)map->size() - 1)
		y_max = (int)map->size() - 1;

	int x_min = (player[id].GET_PosX() - ((WIDTH / TILE_SIZE) / 2) / GET_Camera(id)->zoom) - 4;
	if (x_min < 0)
		x_min = 0;

	int x_max = (player[id].GET_PosX() + ((WIDTH / TILE_SIZE) / 2) / GET_Camera(id)->zoom) + 2;
	if (x_max > (int)(*map)[0].size() - 1)
		x_max = (int)(*map)[0].size() - 1;

	for (int y = y_max; y >= y_min; y--)
	{
	  for (int x = x_max; x >= x_min; x--)
 		{
			//cout << "y" << y_min << " " << y_max << endl;
			//cout << "x" << x_min << " " << x_max << endl;
			//cout << "[" << y << "] " << "[" << x << "]" << endl;
			if ((*map)[y][x].GET_Type() == GROUND || HOUSE || HOUSE_BASE || TREE)
				DrawTexture(texture->ground_1, x * TILE_SIZE, y * TILE_SIZE, WHITE);
			if ((*map)[y][x].GET_Type() == WALL)
				DrawTexture(texture->wall_1, x * TILE_SIZE, y * TILE_SIZE, WHITE);
			else if ((*map)[y][x].GET_Type() == BRICK_GROUND)
				DrawTexture(texture->wall_1, x * TILE_SIZE, y * TILE_SIZE, WHITE);
			
			if ((*map)[y][x].GET_Type() == TREE_BASE)
				DrawTexture(texture->tree_1, x * TILE_SIZE, y * TILE_SIZE, WHITE);
			if ((*map)[y][x].GET_Type() == HOUSE_BASE)
				DrawTexture(texture->house_1, x * TILE_SIZE, y * TILE_SIZE, WHITE);
		}
	}
  	
}
