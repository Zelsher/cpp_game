#include "../../inc/game.hpp"

Mob*		Cell::GET_Mob(int id) 
{
    if (id < (int)mob.size())
        return(mob[id]);
    return (NULL);
}

Boss*		Cell::GET_Boss(int id) 
{
    if (id < (int)boss.size())
        return(boss[id]);
    return (NULL);
}

