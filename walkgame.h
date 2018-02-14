#ifndef WALKGAME_H
#define WALKGAME_H

#include "game.h"



class WalkGame : public Game
{
private:
public:
    WalkGame();
    void initView(QGraphicsView *vue);
};

#endif // WALKGAME_H
