#ifndef SCENARIO_H
#define SCENARIO_H

#include "game.h"
#include "mainwindow.h"

#include <QList>

class Scenario
{
private:
    QList<Game*> * storyboard;
    Game * currentGame;
public:
    Scenario();
    QList<Game *> *getStoryboard() const;
    void addGame(Game* g);
    void setCurrentGame(Game * g);
    Game *getCurrentGame() const;
    void start(QGraphicsView *vue);
};

#endif // SCENARIO_H
