#include "inputmanager.h"
#include <QGraphicsItem>
#include <iostream>

QPoint InputManager::getPosCoord() const
{
    return posCoord;
}

void InputManager::mouseMoveEvent(QMouseEvent *event){
    this->posCoord=event->pos();
    this->scene->getComponentList().first()->setY(this->posCoord.y());
    std::cout << this->posCoord.y();
}

InputManager::InputManager(QMainWindow *vue, WalkGameView *scene)
{
    vue->setMouseTracking(true);
    this->scene = scene;
}
