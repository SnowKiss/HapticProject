#ifndef WALKGAME_H
#define WALKGAME_H

#include "game.h"


/**
 * @brief La classe du troisème mini-jeu
 * Hérite de Game
 */
class WalkGame : public Game
{
private:
public:
    WalkGame(int profil);
    virtual void initView(QGraphicsView *vue);
};

#endif // WALKGAME_H
