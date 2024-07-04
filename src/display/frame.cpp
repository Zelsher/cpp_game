#include "../../inc/game.hpp"


void	Display::DRAW_Background(int id)
{
	//display.GET_Camera(id)->zoom
	int y_min = (player[id].GET_PosY() - ((HEIGHT / TILE_SIZE) / 2) / GET_Camera(id)->zoom) - 1;
	if (y_min < 0)
		y_min = 0;

	int y_max = (player[id].GET_PosY() + ((HEIGHT / TILE_SIZE) / 2) / GET_Camera(id)->zoom) + 1;
	if (y_max > (int)map->size())
		y_max = (int)map->size();

	int x_min = (player[id].GET_PosX() - ((WIDTH / TILE_SIZE) / 2) / GET_Camera(id)->zoom) - 1;
	if (x_min < 0)
		x_min = 0;

	int x_max = (player[id].GET_PosX() + ((WIDTH / TILE_SIZE) / 2) / GET_Camera(id)->zoom) + 2;
	if (x_max > (int)(*map)[0].size())
		x_max = (int)(*map)[0].size();

	
	for (int y = y_min; y < y_max; y++)
	{
	  for (int x = x_min; x < x_max; x++)
 		{
			//cout << "y" << y_min << " " << y_max << endl;
			//cout << "x" << x_min << " " << x_max << endl;
			if ((*map)[y][x] == '0')
				DrawTexture(texture->ground_1, x * TILE_SIZE, y * TILE_SIZE, WHITE);
			else if ((*map)[y][x] == '1')
				DrawTexture(texture->wall_1, x * TILE_SIZE, y * TILE_SIZE, WHITE);
			else if ((*map)[y][x] == '2')
			{
				DrawTexture(texture->ground_1, x * TILE_SIZE, y * TILE_SIZE, WHITE);
				DrawTexture(texture->tree_1, x * TILE_SIZE, y * TILE_SIZE, WHITE);
			}
		}
	}
  	
}
