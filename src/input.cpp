#include "../inc/game.hpp"


int	moove_player_valid(vector<vector<char>> *map, float X, float Y)
{
	//cout << "posYX[" << Y << "][" << X << "] " << (*map)[(int)Y][(int)X] << endl;
	if (X < 0 || Y < 0)
		return (0);
	if ((*map).size() < Y || (*map)[(int)Y].size() < X)
		return (0);
	if ((*map)[(int)Y][(int)X] == '1')
		return (0);
	cout << (*map)[(int)Y][(int)X] << endl;
	return (1);
}

void	Game::HANDLE_Click(Vector2 position, int id, int hand)
{
	Weapon *weapon;

	weapon = player[id].GET_Hand(hand);

	if (hand == RIGHT)
		cout << "here" << player[id].GET_Hand(hand) << endl;
	//cout << "Clicked at" << position.y / TILE_SIZE << " " << position.x / TILE_SIZE << endl;
	if (weapon->GET_Type() && weapon->GET_Type() == TP_RING && player[id].GET_Mana() > 66)
	{
		position.x /= TILE_SIZE;
		position.y /= TILE_SIZE;
		player[id].SET_Pos(position);
		player[id].SET_Mana(-66);
	}
}

int	MOOVING()
{
	if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_RIGHT)
		|| IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_UP))
		return (1);
	return (0);
}

void	Game::HANDLE_Input(int id)
{
	float m_speed = player[id].GET_Speed();
	if (IsKeyDown(KEY_LEFT_SHIFT) && player[id].GET_Stamina() > 0 && MOOVING())
	{
		m_speed *= 2;
		player[id].SET_Stamina(-1);
	}
	else
		player[id].SET_Stamina(1);
	player[id].SET_Mana(0.2);

	if (IsKeyReleased(KEY_SPACE))
		(void)player;//pause
	if (IsKeyDown(KEY_LEFT) && moove_player_valid(&map, player[id].GET_PosX() - m_speed * 2, player[id].GET_PosY()))
		player[id].ADD_PosX(-m_speed);
	if (IsKeyDown(KEY_RIGHT) && moove_player_valid(&map, player[id].GET_PosX() + m_speed * 2, player[id].GET_PosY()))
		player[id].ADD_PosX(m_speed);
	if (IsKeyDown(KEY_UP) && moove_player_valid(&map, player[id].GET_PosX(), player[id].GET_PosY() - m_speed * 2))
		player[id].ADD_PosY(-m_speed);
	if (IsKeyDown(KEY_DOWN) && moove_player_valid(&map, player[id].GET_PosX(), player[id].GET_PosY() + m_speed * 2))
		player[id].ADD_PosY(m_speed);
	
	Vector2 mouse_pos = GetScreenToWorld2D(GetMousePosition(), *display.GET_Camera(id));
	if (IsMouseButtonDown(0))
		HANDLE_Click(mouse_pos, id, LEFT);
	if (IsMouseButtonDown(1))
		HANDLE_Click(mouse_pos, id, RIGHT);
	
	display.GET_Camera(id)->target = (Vector2){(player[id].GET_PosX() - 10) * TILE_SIZE, (player[id].GET_PosY() - 5) * TILE_SIZE};
	player[id].SET_Dir(mouse_pos.x / TILE_SIZE - player[id].GET_PosX(), mouse_pos.y / TILE_SIZE - player[id].GET_PosY());
}
