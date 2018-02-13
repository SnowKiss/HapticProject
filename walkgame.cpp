#include "walkgame.h"

bool WalkGame::getGameover() const
{
    return gameover;
}

void WalkGame::setGameover(bool value)
{
    gameover = value;
}

WalkGame::WalkGame()
{
    this->setGameover(false);
}
