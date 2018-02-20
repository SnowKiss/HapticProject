#ifndef SCENARIO_H
#define SCENARIO_H

#include "game.h"
#include "mainwindow.h"

#include <QList>
/**
 * @brief La liste des jeux
 * Permet de gérer facilement l'enchainement des mini-jeux
 */
class Scenario
{
private:
    QList<Game*> storyboard;
    Game * currentGame;
public:
    Scenario();
    void addGame(Game* g);
    void setCurrentGame(Game * g);
    Game *getCurrentGame() const;
    void start(QGraphicsView *vue);
    QList<Game *> getStoryboard() const;
    void nextGame();
};

#endif // SCENARIO_H
