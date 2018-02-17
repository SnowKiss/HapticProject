#include "game.h"

GameType Game::getType() const
{
    return type;
}

Game::Game(int profil)
{
    this->profil = profil;
    this->gameover=false;
    this->win=false;
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

void Game::initView(QGraphicsView *vue)
{

}

int Game::getProfil(){
    return profil;
}
