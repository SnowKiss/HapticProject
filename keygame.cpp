#include "keygame.h"

KeyGame::KeyGame(int id): Game(id)
{
    this->setGameover(false);
}

bool KeyGame::getGameover() const
{
    return gameover;
}

void KeyGame::setGameover(bool value)
{
    gameover = value;
}
