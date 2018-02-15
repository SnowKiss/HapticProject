#ifndef WALKGAME_H
#define WALKGAME_H

#include "game.h"



class WalkGame : public Game
{
private:
public:
    WalkGame();
    virtual void initView(QGraphicsView *vue);
};

#endif // WALKGAME_H
