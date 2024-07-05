#include "../../inc/game.hpp"

Happening::Happening()
{
	pos.x = 0;
	pos.y = 0;
	incrX = 0;
	incrY = 0;
	happen = 0;
	duration = 0;
}

Happening::Happening(int n_type, Vector2 origin_pos, Vector2 use_pos, Game *game)
{
	type = n_type;
	pos.x = origin_pos.x;
	pos.y = origin_pos.y;

	float y1 = use_pos.y;
	float y0 = origin_pos.y;
	float x1 = use_pos.x;
	float x0 = origin_pos.x;

    // Paramètres de la simulation
    double v = 0.1; // vitesse constante (0.1 unité par seconde)

    // Exécuter la simulation
    double x = x0, y = y0;
    double xstep, ystep;
    
    // Calculer l'angle directionnel
    double theta = atan2(y1 - y0, x1 - x0);
    // Calculer les pas selon la vitesse
    xstep = v * cos(theta);
    ystep = v * sin(theta);

    std::cout << "Position initiale: (" << x << ", " << y << ")\n";
	cout << ystep << " " << xstep << endl;

	if (type == SHOOT)
	{
		(void)game;
		(void)use_pos;
		pos.x = origin_pos.x;
		pos.y = origin_pos.y;
		incrX = xstep * 10;
		incrY = ystep * 10;
		texture = &game->GET_Texture()->tile1;
		duration = 200;
		happen = 0;
	}
}

Happening::~Happening()
{
}

int	Happening::UPDATE_Happening(vector<vector<char>> *map)
{
	//cout << "update" << endl;
	if ((duration && duration < happen)
		|| !IN_Map(map, pos.x, pos.y))
		return(0);
	if (type == SHOOT)
	{
		//cout << pos.x << " " << pos.y << "  " << happen << endl;
		pos.x += incrX;
		pos.y += incrY;
	}
	happen++;
	return (1);
}


