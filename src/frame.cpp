#include "../inc/game.hpp"


void	Display::DRAW_Background()
{
	for (int y = 0; y < map_height; y++)
	{
	  for (int x = 0; x < map_width; x++)
 		{

			if ((*map)[y][x] == '0')
				DrawTexture(texture->ground_1, x * TILE_SIZE, y * TILE_SIZE, WHITE);
			else if ((*map)[y][x] == '1')
				DrawTexture(texture->wall_1, x * TILE_SIZE, y * TILE_SIZE, WHITE);
			else if ((*map)[y][x] == '2')
			{
				DrawTexture(texture->ground_1, x * TILE_SIZE, y * TILE_SIZE, WHITE);
				DrawTexture(texture->tree_1, x * TILE_SIZE, y * TILE_SIZE, WHITE);
			}
			//cout << x << " " << map_width << y << endl;
			//cout << "oui\n";
		}
	}
  	
}
