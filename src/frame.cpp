#include "../inc/game.hpp"

int	is_wspace(char c)
{
	if (c == 32 || c == 9 || c == 13 || c == 10)
		return (1);
	return (0);
}

int	is_in_map(double x, double y, vector<vector<char>> *map, int max_mapY)
{
	//cout << "[" << y << "][" << x << "]" << (*map)[(int)y][(int)x] << endl;
	(void)max_mapY;
	if ((int)x < 0 || (int)y < 0)
		return (0);
	if ((int)y >= max_mapY
		|| x > map[(int)y].size())
		return (0);
	return (1);
}

void	draw_line(int *pixel, double X, double Y, int width, int s_width,
					float scale, vector<vector<char>> *map, int max_mapY)
{
	(void)max_mapY;
	int	color;
	int	last_pos;
	
	while (pixel[0] <= width - s_width)
	{
		last_pos = (int)X;
		if (!is_in_map(X, Y, map, max_mapY))
		{
			color = 0;
		}
		else if ((*map)[(int)Y][(int)X] == '1')
			color = 1;
		else
			color = 2;
		while (last_pos == (int)X && pixel[0] <= width)
		{
			//printf("posXY[%f][%f], scale :%f\n", pos[1], pos[0], scale);
			if (color == 0)
				DrawPixel((int)pixel[0], (int)pixel[1], BLACK);
			if (color == 1)
				DrawPixel((int)pixel[0], (int)pixel[1], BLUE);
			if (color == 2)
				DrawPixel((int)pixel[0], (int)pixel[1], WHITE);
			X += scale;
			pixel[0]++;
		}
	}
}

void	DRAW_Background(Player *player, int width, int s_width, int height, int s_height, 
						vector<vector<char>> *map, int max_mapY)
{
	int		pixel[2];
	double 	X;
	float	scale = 0.03;
	double Y = (int)player->GET_PosY() - 5;

	pixel[1] = 0;
	while (pixel[1] <= height - s_height)
	{
		X = (int)player->GET_PosX() - 5;
		pixel[0] = 0;
		draw_line(pixel, X, Y, width, s_width, scale, map, max_mapY);
		pixel[1]++;
		Y += scale;
	}

}

void	DISPLAY_Cam(Player *player, int width, int height,
					int id, vector<vector<char>> *map, int max_mapY)
{
	//(void)map;
	//(void)max_mapY;
	//(void)player;
	(void)map;
	(void)player;
	(void)max_mapY;
	(void)height;
	int	s_width = 0;
	//int	s_height = 0;
	if (id == 1)
		s_width += width;
	BeginDrawing();
	ClearBackground(BLACK);
	DRAW_Background(player, width, s_width, height, id, map, max_mapY);
	DrawCircle(width / 2, height / 2, 20, RED);
	EndDrawing();
}