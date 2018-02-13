#include "walkgameview.h"

#include <QGraphicsRectItem>

QList<QGraphicsItem *> WalkGameView::getComponentList() const
{
    return componentList;
}

WalkGameView::WalkGameView(QGraphicsView *vue)
{
    // on démarre le suivi de la souris
    vue->setMouseTracking(true);

    // initialisation de la scène
    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(0,0,850,550);
    // creation du personnage
    QGraphicsRectItem *player = new QGraphicsRectItem();
    player->setRect(0,0,80,180);
    scene->addItem(player);

    // creation de la poubelle
    QGraphicsRectItem *poubelle = new QGraphicsRectItem();
    poubelle->setRect(250,100,80,80);
    scene->addItem(poubelle);

    // creation du passant
    QGraphicsRectItem *passant = new QGraphicsRectItem();
    passant->setRect(500,400,80,80);
    scene->addItem(passant);

    // creation du chien
    QGraphicsRectItem *chien = new QGraphicsRectItem();
    chien->setRect(1000,300,80,80);
    scene->addItem(chien);

    vue->setScene(scene);

    this->componentList.append(player);
    this->componentList.append(poubelle);
    this->componentList.append(passant);
    this->componentList.append(chien);
}
