#ifndef DRINKGAME_H
#define DRINKGAME_H

#include "game.h"

class DrinkGame: public Game
{
private:
public:
    DrinkGame(int profil);
    void initView(QGraphicsView *vue);
};

#endif // DRINKGAME_H
