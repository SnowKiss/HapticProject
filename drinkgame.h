#ifndef DRINKGAME_H
#define DRINKGAME_H

#include "game.h"

/**
 * @brief La classe du premier mini-jeu
 * Hérite de la clase Game
 *
 */
class DrinkGame: public Game
{
private:
public:
    DrinkGame(int profil);
    void initView(QGraphicsView *vue);
};

#endif // DRINKGAME_H
