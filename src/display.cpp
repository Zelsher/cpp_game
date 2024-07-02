#include "../inc/game.hpp"

//DrawPixel(x,y,color)
Display::Display(Player* player_list) : player(player_list), n_cam(1), width(WIDTH), height(HEIGHT) 
{
	SET_Camera();
}

void	Display::UPDATE_Display()
{
	n_cam = COUNT_Player(player);
}

void	Display::SET_Camera()
{
	camera.target = (Vector2){player[0].GET_PosX(), player[0].GET_PosY()};
	camera.offset = (Vector2){100.0f, 200.0f};
	camera.rotation = 0.0f;
	camera.zoom = 1.0f;
}

int	Display::COUNT_Player(Player *player)
{
	int	i = 0;
	while (player[i].EXIST())
		i++;
	return (i);
}

void	Display::SET_Map(vector<vector<char>> *n_map, t_texture *map_texture, int width, int height)
{
	texture = map_texture;
	map = n_map;
	map_width = width;
	map_height = height;
	PRINT_Map(*n_map);
}

void	Display::UPDATE_Image()
{
	DISPLAY_Cam(0);
	if (player[1].EXIST())
		DISPLAY_Cam(1);
}

void	Display::DRAW_Player(int id)
{
	int	lifebar;
	int	staminabar;
	int	manabar;
	int	textWidth;
	
	DrawTexturePro(texture->player_1, Rectangle{0, 0, TILE_SIZE, TILE_SIZE},
                       { player[id].GET_PosX() * TILE_SIZE, player[id].GET_PosY() * TILE_SIZE,
						TILE_SIZE, TILE_SIZE },
                       { TILE_SIZE/2, TILE_SIZE/2 }, player[id].GET_Rot(), RAYWHITE);

	textWidth = MeasureText(player[id].GET_Name().c_str(), TILE_SIZE / 2);
	DrawText(player[id].GET_Name().c_str(), player[id].GET_PosX() * TILE_SIZE - textWidth / 2, player[id].GET_PosY() * TILE_SIZE - TILE_SIZE * 1.5, TILE_SIZE / 2, WHITE);
	
	lifebar = player[id].GET_Hp() * TILE_SIZE / 110;
	staminabar = (player[id].GET_Stamina() * TILE_SIZE / 110) / 2;
	manabar = (player[id].GET_Mana() * TILE_SIZE / 110) / 2;
	DrawRectangle(player[id].GET_PosX() * TILE_SIZE - TILE_SIZE / 2, player[id].GET_PosY() * TILE_SIZE - TILE_SIZE, TILE_SIZE, TILE_SIZE / 2, DARKGRAY);
	DrawRectangle(player[id].GET_PosX() * TILE_SIZE - TILE_SIZE / 2 + TILE_SIZE * 0.05, player[id].GET_PosY() * TILE_SIZE - TILE_SIZE *0.95, lifebar, TILE_SIZE / 7, RED);
	DrawRectangle(player[id].GET_PosX() * TILE_SIZE - TILE_SIZE / 2 + TILE_SIZE * 0.05, player[id].GET_PosY() * TILE_SIZE - TILE_SIZE *0.75, staminabar, TILE_SIZE / 10, GREEN);
	
	//#define BLUE       CLITERAL(Color){ 0, 121, 241, 255 }     // Blue
	if (player[id].GET_Hand(LEFT))//Left
	{
		//DrawTexture(texture->tile1, player[id].GET_PosX() * TILE_SIZE - TILE_SIZE * 1, player[id].GET_PosY() * TILE_SIZE - TILE_SIZE, WHITE);
		DrawRectangle(player[id].GET_PosX() * TILE_SIZE - TILE_SIZE / 2 + TILE_SIZE * 0.05, player[id].GET_PosY() * TILE_SIZE - TILE_SIZE *0.60, manabar, TILE_SIZE / 10, BLUE);
	}
	else
		DrawTexture(texture->tile1, player[id].GET_PosX() * TILE_SIZE - TILE_SIZE * 1, player[id].GET_PosY() * TILE_SIZE - TILE_SIZE, WHITE);
	if (player[id].GET_Hand(RIGHT))//Left
	{
		 //DrawTexture(texture->tree_1, player[id].GET_PosX() * TILE_SIZE - TILE_SIZE * 1.5, player[id].GET_PosY() * TILE_SIZE - TILE_SIZE * 1.5);
		DrawRectangle(player[id].GET_PosX() * TILE_SIZE, player[id].GET_PosY() * TILE_SIZE - TILE_SIZE *0.60, manabar, TILE_SIZE / 10, ORANGE);
	}
	else
		DrawTexture(texture->tile1, player[id].GET_PosX() * TILE_SIZE + TILE_SIZE / 2, player[id].GET_PosY() * TILE_SIZE - TILE_SIZE, WHITE);
	//if (1)
	//	Dra
}

void	Display::DISPLAY_Cam(int id)
{
	//cout << "posYX[" << player[id].GET_PosY() << "][" << player[id].GET_PosX() << "] " << (*map)[(int)player[id].GET_PosY()][(int)player[id].GET_PosX()] << endl;
	BeginDrawing();
	ClearBackground(DARKGRAY);
	BeginMode2D(camera);

	DRAW_Background();
	DRAW_Player(id);

	EndMode2D();
	EndDrawing();
}

Camera2D	*Display::GET_Camera(int id)
{
	(void)id;
	return (&camera);
}
