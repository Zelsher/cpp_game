#include "../../inc/game.hpp"

void	Display::GET_Display_Width(int id)
{
	display_Min.y = (player[id].GET_Pos().y - ((HEIGHT / TILE_SIZE) / 2) / GET_Camera(id)->zoom) - 4;
	if (display_Min.y < 0)
		display_Min.y = 0;

	display_Max.y = (player[id].GET_Pos().y + ((HEIGHT / TILE_SIZE) / 2) / GET_Camera(id)->zoom) + 1;
	if (display_Max.y > map->GET_Height_Map() - 1)
		display_Max.y = map->GET_Height_Map() - 1 - 1;

	display_Min.x = (player[id].GET_Pos().x - ((WIDTH / TILE_SIZE) / 2) / GET_Camera(id)->zoom) - 4;
	if (display_Min.x < 0)
		display_Min.x = 0;

	display_Max.x = (player[id].GET_Pos().x + ((WIDTH / TILE_SIZE) / 2) / GET_Camera(id)->zoom) + 2;
	if (display_Max.x > map->GET_Width_Map() - 1)
		display_Max.x = map->GET_Width_Map() - 1;
}

void	Display::DRAW_Background()
{
	int	type;
	for (int y = display_Max.y; y >= display_Min.y; y--)
	{
	  for (int x = display_Max.x; x >= display_Min.x; x--)
 		{
			type = map->GET_Type(Vector2{(float)y, (float)x});
			if (type == GROUND || type == HOUSE || type == HOUSE_BASE
				|| type == TREE || type == TREE_BASE)
				DrawTexture(texture->ground_1, x * TILE_SIZE, y * TILE_SIZE, WHITE);
			else if (type == WALL)
				DrawTexture(texture->wall_1, x * TILE_SIZE, y * TILE_SIZE, WHITE);
			else if (type == BRICK_GROUND)
				DrawTexture(texture->ground_2, x * TILE_SIZE, y * TILE_SIZE, WHITE);
			
			if (type == TREE_BASE)
				DrawTexture(texture->tree_1, x * TILE_SIZE, y * TILE_SIZE, WHITE);
			if (type == HOUSE_BASE)
				DrawTexture(texture->house_1, x * TILE_SIZE, y * TILE_SIZE, WHITE);
		}
	}
  	
}
