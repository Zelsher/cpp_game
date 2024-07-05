#include "../../inc/game.hpp"

//Game

Game::Game() : display(player), frame(0)
{
	InitWindow(WIDTH, HEIGHT, "game");
	ClearBackground(BLACK);
	SetTargetFPS(200);
	InitAudioDevice();
	CHOSE_Lvl();
	display.SET_Event(&event);
	display.SET_Mobs(&mobs);
}

Game::~Game()
{
	CloseWindow();
}

void		Game::CREATE_Mob(int type, Vector2 pos)
{
	Mob	ennemy(this, &texture.texture_pack, type, pos);
	mobs.push_back(ennemy);
}
vector<vector<Cell>> Game::OPEN_Map(string file)
{
    vector<vector<Cell>> map;
	string ligne;
	ifstream fichier(file);
    if (!fichier.is_open()) 
	{
        cerr << "Erreur d'ouverture du fichier!" << endl;
        exit(1);
    }
    int y = 0;
    int x = 0;
    while (getline(fichier, ligne)) 
	{
        vector<Cell> ligneCarte;
        for (Cell c : ligne) 
		{
            ligneCarte.push_back(c);
            if (c.GET_Type() >= 48 && c.GET_Type() <= 57)
                LOAD_Spawner(Vector3{(float)x, (float)y, (float)(c.GET_Type() - '0')});
            x++;
        }
        map.push_back(ligneCarte);
        y++;
		x = 0;
    }
    fichier.close();
    return (map);
}
void	Game::CHOSE_Lvl()
{
	int	width;
	int	height;

	int	lvl = 1;//Offrir un choix
		if (lvl == 1)
	map = OPEN_Map("asset/map/map.txt");
	width = map[1].size();
	height = map.size();
	LOAD_Texture();
	display.SET_Map(&map, &texture, width, height);
	//Mettre / les joueur sur P
}

void		Game::LOAD_Texture()
{
	texture.wall_1 =  LoadTexture("asset/texture/Wall_1.png");
	texture.ground_1 = LoadTexture("asset/texture/Ground_1.png");
	texture.house_1 =  LoadTexture("asset/texture/House.png");
	texture.tree_1 = LoadTexture("asset/texture/Tree_1.png");
	texture.player_1 = LoadTexture("asset/texture/character_1/Player_1.png");
	texture.player_2 = LoadTexture("asset/texture/Player_2.png");
	texture.r_hand = LoadTexture("asset/texture/Right_Hand.png");
	texture.l_hand = LoadTexture("asset/texture/Left_Hand.png");
	texture.tile1 = LoadTexture("asset/texture/32.png");
	texture.tile2 = LoadTexture("asset/texture/64.png");
	texture.item[TP_RING] = LoadTexture("asset/texture/Tp_Ring.png");
	texture.item[MAGIC_STICK] = LoadTexture("asset/texture/32.png");
	texture.item[PISTOL] = LoadTexture("asset/texture/Pistol.png");
	texture.item[UZI] = LoadTexture("asset/texture/Uzi.png");
	texture.texture_pack.ennemy = LoadTexture("asset/texture/32.png");
	//texture.texture_pack.ennemy = LoadTexture("assest/texture/ennemy_texture_pack/1.png");
}

int Game::ADD_Player(string name)
{
	int	i = 0;

	if (i < 2 && player[i].EXIST() == 1)
		i++;
	if (i == 2)
		return(1);
	player[0].SET_PosX(2);
	player[0].SET_PosY(2);
	return (player[i].ACTIVATE_Player(name, i));
	display.UPDATE_Display();
}

void	Game::UPDATE_Spawner()
{
	for (size_t i = 0; i < spawner.size(); i++)
	{
		//cout << spawner[i].z << endl;
		if (spawner[i].z && rand()%9 + 1 < spawner[i].z)
		{
			//cout << spawner[i].x << " " << spawner[i].y << endl;
			CREATE_Mob(ENNEMY, Vector2{spawner[i].x, spawner[i].y});
		}
	}
}

void	Game::UPDATE_Game()
{
	HANDLE_Input(0);

	player[0].UPDATE_Items();

	event.UPDATE_EVENTS(&map);

	for (size_t i = 0; i < mobs.size(); i++)
		mobs[i].ACTION(&map);

	if (frame % 50 == 0)
		UPDATE_Spawner();

	if (frame == 100000)
		frame = 0;
	display.UPDATE_Image();
	frame++;

	if (player[0].IS_Inventory_Open())
		(void)player[0];
}



//Display


