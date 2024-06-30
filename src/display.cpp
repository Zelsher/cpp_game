#include "../inc/game.hpp"

//DrawPixel(x,y,color)
Display::Display(Player* player_list) : player(player_list), n_cam(1), width(WIDTH), height(HEIGHT)
{
}

void	Display::UPDATE_Display()
{
	n_cam = COUNT_Player(player);
}
int	Display::COUNT_Player(Player *player)
{
	int	i = 0;
	while (player[i].EXIST())
		i++;
	return (i);
}
void	Display::SET_Map(vector<vector<char>> *n_map)
{
	map = n_map;
	max_mapY = map->size();
	PRINT_Map(*n_map);
}

void	Display::UPDATE_Image()
{
	int	temp_width = width;
	int	temp_height = height;
	if (n_cam == 2)
		temp_width /= 2;
	for (int i = 0 ; i < n_cam; i++)
		DISPLAY_Cam(&player[i], temp_width, temp_height, i, map, max_mapY);
	HANDLE_Input(&player[0], map);
	if (player[1].EXIST())
		HANDLE_Input(&player[1], map);
}
