#include "mainwindow.h"
#include "scenario.h"

QList<Game*> Scenario::getStoryboard() const
{
    return storyboard;
}

void Scenario::nextGame()
{
    this->storyboard.pop_front();
    this->currentGame=this->storyboard.first();
}

void Scenario::addGame(Game* g)
{

    this->storyboard.append(g);
}

void Scenario::setCurrentGame(Game *g)
{
    this->currentGame=g;
}

Game *Scenario::getCurrentGame() const
{
    return currentGame;
}

void Scenario::start(QGraphicsView *vue)
{
    //for (Game* g : this->getStoryboard()) {
    //Game* g = this->getStoryboard()->first();
        //while(!g->getWin())
        //{
            //g->initView(vue);
            //while(!g->getGameover());
        //}
    //}
}

Scenario::Scenario()
{

}
