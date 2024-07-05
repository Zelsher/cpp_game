#include "../../inc/game.hpp"

//DrawPixel(x,y,color)
Display::Display(Player* player_list) : player(player_list), n_cam(1), width(WIDTH), height(HEIGHT), display_size({WIDTH / TILE_SIZE, HEIGHT / TILE_SIZE})
{
	SET_Camera();
}

void	Display::UPDATE_Display()
{
	n_cam = COUNT_Player(player);
}

void	Display::SET_Camera()
{
	camera.target = (Vector2){0, 0};
	camera.offset = (Vector2){0, 0};
	camera.rotation = 0.0f;
	camera.zoom = 1.4f;
}

int	Display::COUNT_Player(Player *player)
{
	int	i = 0;
	while (player[i].EXIST())
		i++;
	return (i);
}

void	Display::SET_Map(vector<vector<Cell>> *n_map, t_texture *map_texture, int width, int height)
{
	texture = map_texture;
	map = n_map;
	map_width = width;
	map_height = height;
	//PRINT_Map(*n_map);
}

void	Display::UPDATE_Image()
{
	DISPLAY_Game(0);
	if (player[1].EXIST())
		DISPLAY_Game(1);
}

//Draw left and right hand icons, and there ressources
void	Display::DRAW_Player_Item(int id)
{
	int ressource_bar;

	if (!player[id].GET_Hand(LEFT)->EMPTY())//Left
	{
		DrawTexture(texture->item[player[id].GET_Hand(LEFT)->GET_Type()], player[id].GET_PosX() * TILE_SIZE - TILE_SIZE,
			player[id].GET_PosY() * TILE_SIZE - TILE_SIZE, WHITE);
	
		if (player[id].GET_Hand(LEFT)->GET_Ressource_Type() != MANA)
		{
			ressource_bar = (player[id].GET_Hand(LEFT)->GET_Ressource()->GET_Value() * TILE_SIZE / 115) / 2;
			DrawRectangle(player[id].GET_PosX() * TILE_SIZE - TILE_SIZE + TILE_SIZE * 0.05,
				player[id].GET_PosY() * TILE_SIZE - TILE_SIZE *0.60, ressource_bar, TILE_SIZE / 10, player[id].GET_Hand(LEFT)->GET_Color());
		}
	}
	else
		DrawTexture(texture->l_hand, player[id].GET_PosX() * TILE_SIZE - TILE_SIZE * 1,
			player[id].GET_PosY() * TILE_SIZE - TILE_SIZE, WHITE);

	if (!player[id].GET_Hand(RIGHT)->EMPTY())//right
	{
		DrawTexture(texture->item[player[id].GET_Hand(RIGHT)->GET_Type()], player[id].GET_PosX() * TILE_SIZE + TILE_SIZE / 2,
			player[id].GET_PosY() * TILE_SIZE - TILE_SIZE, WHITE);
		
		if (player[id].GET_Hand(RIGHT)->GET_Ressource_Type() != MANA)
		{
			ressource_bar = (player[id].GET_Hand(RIGHT)->GET_Ressource()->GET_Value() * TILE_SIZE / 115) / 2;
			DrawRectangle(player[id].GET_PosX() * TILE_SIZE + TILE_SIZE / 2,
				player[id].GET_PosY() * TILE_SIZE - TILE_SIZE *0.60, ressource_bar, TILE_SIZE / 10, player[id].GET_Hand(RIGHT)->GET_Color());
		}
	}
	else
		DrawTexture(texture->r_hand, player[id].GET_PosX() * TILE_SIZE + TILE_SIZE / 2,
			player[id].GET_PosY() * TILE_SIZE - TILE_SIZE, WHITE);
}

void	Display::DRAW_Player(int id)
{
	int	textWidth;
	int	lifebar;
	int	staminabar;
	int	manabar;

	
	DrawTexturePro(texture->player_1, Rectangle{0, 0, TILE_SIZE, TILE_SIZE},
                       { player[id].GET_PosX() * TILE_SIZE, player[id].GET_PosY() * TILE_SIZE, TILE_SIZE, TILE_SIZE},
                       { TILE_SIZE/2, TILE_SIZE/2 },
					   player[id].GET_Rot(), RAYWHITE);

	textWidth = MeasureText(player[id].GET_Name().c_str(), TILE_SIZE / 2);
	DrawText(player[id].GET_Name().c_str(), player[id].GET_PosX() * TILE_SIZE - textWidth / 2, player[id].GET_PosY() * TILE_SIZE - TILE_SIZE * 1.5, TILE_SIZE / 2, WHITE);
	
	//HUD Relativ
	lifebar = player[id].GET_Hp() * TILE_SIZE / 110;
	staminabar = (player[id].GET_Stamina_V() * TILE_SIZE / 110);
	manabar = (player[id].GET_Mana_V() * TILE_SIZE / 110);
	DrawRectangle(player[id].GET_PosX() * TILE_SIZE - TILE_SIZE / 2, player[id].GET_PosY() * TILE_SIZE - TILE_SIZE, TILE_SIZE, TILE_SIZE / 2, DARKGRAY);
	DrawRectangle(player[id].GET_PosX() * TILE_SIZE - TILE_SIZE / 2 + TILE_SIZE * 0.05, player[id].GET_PosY() * TILE_SIZE - TILE_SIZE *0.95, lifebar, TILE_SIZE / 7, RED);
	DrawRectangle(player[id].GET_PosX() * TILE_SIZE - TILE_SIZE / 2 + TILE_SIZE * 0.05, player[id].GET_PosY() * TILE_SIZE - TILE_SIZE *0.75, staminabar, TILE_SIZE / 10, GREEN);
	DrawRectangle(player[id].GET_PosX() * TILE_SIZE - TILE_SIZE / 2 + TILE_SIZE * 0.05, player[id].GET_PosY() * TILE_SIZE - TILE_SIZE *0.60, manabar, TILE_SIZE / 10, DARKBLUE);
	
	DRAW_Player_Item(id);
}

void	Display::DRAW_Events()
{
	int	n_happening = event->HAPPENING_N();
	Vector2	pos;
	for (int i = 0; i < n_happening ; i++)
	{
		pos = event->HAPPENING(i).GET_Pos();
		if (IN_Map(map, pos.x, pos.y))
			DrawTexture(event->HAPPENING(i).GET_Texture(), event->HAPPENING(i).GET_Pos().x * TILE_SIZE - TILE_SIZE / 4, event->HAPPENING(i).GET_Pos().y * TILE_SIZE - TILE_SIZE / 4, WHITE);
	}
}

void	Display::DRAW_Mobs()
{
	Vector2 pos;
	for (size_t i = 0; i < mobs->size(); i++)
	{
		pos = (*mobs)[i].GET_Pos();
		DrawTexture((*mobs)[i].GET_Texture(0), pos.x * TILE_SIZE, pos.y * TILE_SIZE, WHITE);
	}
}

void	Display::DISPLAY_Game(int id)
{
	//cout << "posYX[" << player[id].GET_PosY() << "][" << player[id].GET_PosX() << "] " << (*map)[(int)player[id].GET_PosY()][(int)player[id].GET_PosX()] << endl;
	GET_Display_Width(id);
	BeginDrawing();
	ClearBackground(DARKGRAY);
	BeginMode2D(camera);

	DRAW_Background();
	DRAW_Player(id);
	DRAW_Events();
	DRAW_Mobs();
	DrawFPS(0, 0);
	EndMode2D();
	EndDrawing();
}

