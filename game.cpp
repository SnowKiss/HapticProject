#include "game.h"

GameType Game::getType() const
{
    return type;
}

QList<QGraphicsItem *> Game::getAssetList() const
{
    return assetList;
}

void Game::addItem(QGraphicsItem *item)
{
    this->assetList.append(item);
}

bool Game::getGameover() const
{
    return gameover;
}

void Game::setGameover(bool value)
{
    gameover = value;
}

bool Game::getWin() const
{
    return win;
}

void Game::setWin(bool value)
{
    win = value;
}

Game::Game()
{
    this->setGameover(false);
    this->setWin(false);
}
