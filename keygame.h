#ifndef KEYGAME_H
#define KEYGAME_H

#include "game.h"
/**
 * @brief La classe du second mini-jeu
 */
class KeyGame: public Game
{
private:
public:
    KeyGame(int profil);
    void initView(QGraphicsView *vue);
};

#endif // KEYGAME_H
