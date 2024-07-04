#include "../inc/game.hpp"


int	moove_player_valid(vector<vector<char>> *map, float X, float Y)
{
	if (X < 0 || Y < 0)
		return (0);
	if ((*map).size() < Y || (*map)[(int)Y].size() < X)
		return (0);
	if ((*map)[(int)Y][(int)X] == '1')
		return (0);
	//cout << (*map)[(int)Y][(int)X] << endl;
	return (1);
}

int	MOOVING()
{
	if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_RIGHT)
		|| IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_UP)
		|| IsKeyDown(KEY_A) || IsKeyDown(KEY_D)
		|| IsKeyDown(KEY_S) || IsKeyDown(KEY_W))
		return (1);
	return (0);
}

void	Game::HANDLE_Input(int id)
{
	float m_speed = player[id].GET_Speed();
	if (IsKeyDown(KEY_LEFT_SHIFT) && (player[id].GET_Stamina_V() > 20 || player[id].RUNNING()))
	{
		m_speed *= 1.5f;
		player[id].RUN();
	}
	if (player[id].GET_Stamina_V() <= 0)
		player[id].STOP_Run();

	if (IsKeyReleased(KEY_SPACE))
		(void)player;//pause
	if ((IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) && moove_player_valid(&map, player[id].GET_PosX() - m_speed * 2, player[id].GET_PosY()))
		player[id].ADD_PosX(-m_speed);
	if ((IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) && moove_player_valid(&map, player[id].GET_PosX() + m_speed * 2, player[id].GET_PosY()))
		player[id].ADD_PosX(m_speed);
	if ((IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) && moove_player_valid(&map, player[id].GET_PosX(), player[id].GET_PosY() - m_speed * 2))
		player[id].ADD_PosY(-m_speed);
	if ((IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) && moove_player_valid(&map, player[id].GET_PosX(), player[id].GET_PosY() + m_speed * 2))
		player[id].ADD_PosY(m_speed);

//Handle Mouse Click
	Vector2 mouse_pos = GetScreenToWorld2D(GetMousePosition(), *display.GET_Camera(id));
	if (IsMouseButtonDown(0))
		player[id].GET_Hand(LEFT)->USE(player[id].GET_Pos(), mouse_pos, &player[id], &map);
	if (IsMouseButtonDown(1))
		player[id].GET_Hand(RIGHT)->USE(player[id].GET_Pos(), mouse_pos, &player[id], &map);

//Handle Mouse Wheel
	if (GetMouseWheelMove() < 0)
		player[id].SWITCH_Weapon(RIGHT);
	if (GetMouseWheelMove() > 0)
		player[id].SWITCH_Weapon(LEFT);

	if (IsKeyDown(KEY_R))
	{
		player[id].RELOAD_Weapons();
	}
	display.GET_Camera(id)->target = (Vector2){(player[id].GET_PosX() * TILE_SIZE - WIDTH / 3), (player[id].GET_PosY() * TILE_SIZE - HEIGHT / 3)};
	player[id].SET_Dir(mouse_pos.x / TILE_SIZE - player[id].GET_PosX(), mouse_pos.y / TILE_SIZE - player[id].GET_PosY());
}
