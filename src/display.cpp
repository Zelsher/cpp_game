#include "../inc/game.hpp"

//DrawPixel(x,y,color)

int	is_wspace(char c)
{
	if (c == 32 || c == 9 || c == 13 || c == 10)
		return (1);
	return (0);
}

int	is_in_map(double x, double y, vector<vector<char>> *map, int max_mapY)
{
	if (x < 0 || y < 0)
		return (0);
	if ((int)y >= max_mapY
		|| x >= map[(int)y].size())
		return (0);
	return (1);
}

void	draw_line(int *pixel, double *pos, int width, int s_width,
					float scale, vector<vector<char>> *map, int max_mapY)
{
	int	color;
	int	last_pos;
	
	while (pixel[0] <= width - s_width)
	{
		last_pos = (int)pos[0];
		if (!is_in_map(pos[0], pos[1], map, max_mapY)
			|| is_wspace((*map)[(int)pos[1]][(int)pos[0]]))
			color = 0;
		else if ((*map)[(int)pos[1]][(int)pos[0]] == '1')
			color = 1;
		else
			color = 2;
		while (last_pos == (int)pos[0] && pixel[0] <= width)
		{
			//printf("posXY[%f][%f], scale :%f\n", pos[1], pos[0], scale);
			if (color == 0)
				DrawPixel((int)pixel[0], (int)pixel[1], BLACK);
			if (color == 1)
				DrawPixel((int)pixel[0], (int)pixel[1], BLUE);
			if (color == 2)
				DrawPixel((int)pixel[0], (int)pixel[1], WHITE);
			pos[0] += scale;
			pixel[0]++;
		}
	}
}

void	DRAW_Background(Player *player, int width, int s_width, int height, int s_height, 
						vector<vector<char>> *map, int max_mapY)
{
	int		pixel[2];
	double 	pos[2];
	float	scale = 0.5;
	pos[1] = (int)player->GET_PosX() - 5;
	pixel[1] = 0;
	while (pixel[1] <= height - s_height)
	{
		pos[0] = (int)player->GET_PosY() - 5;
		pixel[0] = 0;
		draw_line(pixel, pos, width, s_width, scale, map, max_mapY);
		pixel[1]++;
		pos[1] += scale;
		//printf("OUI\n");
	}

}

void	DISPLAY_Cam(Player *player, int width, int height,
					int id, vector<vector<char>> *map, int max_mapY)
{
	//(void)map;
	//(void)max_mapY;
	//(void)player;
	int	s_width = 0;
	int	s_height = 0;
	if (id == 1)
		s_width += width;
	if (id == 3)
		s_width += height;
	DRAW_Background(player, width, s_width, height, id, map, max_mapY);
	DrawCircle(s_width / 2, s_height / 2, 5, RED);
}
