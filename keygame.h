#ifndef KEYGAME_H
#define KEYGAME_H

#include "game.h"

class KeyGame: public Game
{
private:
public:
    KeyGame();
    void initView(QGraphicsView *vue);
};

#endif // KEYGAME_H
