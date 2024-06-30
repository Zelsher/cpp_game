#include "../inc/game.hpp"


int	moove_player_valid(vector<vector<char>> *map, float X, float Y)
{
	cout << "posXY[" << Y << "][" << X << "] " << (*map)[(int)Y][(int)X] << endl;
	if (X < 0 || Y < 0)
		return (0);
	if ((*map).size() < Y || (*map)[(int)Y].size() < X)
		return (0);
	if ((*map)[Y][X] == '1')
		return (0);
	return (1);
	/*int	i;

	i = 0;
	if ((keycode == 100 || keycode == 65363))
		if (game->map[game->y_player][game->x_player + 1] != '1')
			i = 1;
	if ((keycode == 97 || keycode == 65361))
		if (game->map[game->y_player][game->x_player - 1] != '1')
			i = 1;
	if (keycode == 115 || keycode == 65364)
		if (game->map[game->y_player + 1][game->x_player] != '1')
			i = 1;
	if (keycode == 119 || keycode == 65362)
		if (game->map[game->y_player - 1][game->x_player] != '1')
			i = 1;
	if (i == 1)
	{
		game->moove++;
		return (1);
	}
	return (0);*/
}

void	HANDLE_Input(Player *player, vector<vector<char>> *map)
{
	if (IsKeyReleased(KEY_SPACE))
		(void)player;//pause
	if (IsKeyDown(KEY_LEFT) && moove_player_valid(map, player->GET_PosX() - 1, player->GET_PosY()))
		player->ADD_PosX(-1);
	if (IsKeyDown(KEY_RIGHT) && moove_player_valid(map, player->GET_PosX() + 1, player->GET_PosY()))
		player->ADD_PosX(1);
	if (IsKeyDown(KEY_UP) && moove_player_valid(map, player->GET_PosX(), player->GET_PosY() - 1))
		player->ADD_PosY(-1);
	if (IsKeyDown(KEY_DOWN) && moove_player_valid(map, player->GET_PosX(), player->GET_PosY() + 1))
		player->ADD_PosY(1);
}
