#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include "walkgameview.h"

#include <QGraphicsView>
#include <QMainWindow>
#include <QMouseEvent>
#include <QPoint>

class InputManager
{
private:
    QPoint posCoord;
    WalkGameView *scene;
    void mouseMoveEvent(QMouseEvent *event);
public:
    InputManager(QMainWindow * vue, WalkGameView * scene);
    QPoint getPosCoord() const;
};

#endif // INPUTMANAGER_H
