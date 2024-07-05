#include "../../inc/game.hpp"

void	Display::GET_Display_Width(int id)
{
	display_Min.y = (player[id].GET_PosY() - ((HEIGHT / TILE_SIZE) / 2) / GET_Camera(id)->zoom) - 4;
	if (display_Min.y < 0)
		display_Min.y = 0;

	display_Max.y = (player[id].GET_PosY() + ((HEIGHT / TILE_SIZE) / 2) / GET_Camera(id)->zoom) + 1;
	if (display_Max.y > (int)map->size() - 1)
		display_Max.y = (int)map->size() - 1;

	display_Min.x = (player[id].GET_PosX() - ((WIDTH / TILE_SIZE) / 2) / GET_Camera(id)->zoom) - 4;
	if (display_Min.x < 0)
		display_Min.x = 0;

	display_Max.x = (player[id].GET_PosX() + ((WIDTH / TILE_SIZE) / 2) / GET_Camera(id)->zoom) + 2;
	if (display_Max.x > (int)(*map)[0].size() - 1)
		display_Max.x = (int)(*map)[0].size() - 1;
}

void	Display::DRAW_Background()
{

	for (int y = display_Max.y; y >= display_Min.y; y--)
	{
	  for (int x = display_Max.x; x >= display_Min.x; x--)
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
