#include "walkgame.h"


WalkGame::WalkGame() : Game()
{
    this->type=GameType::WG;
}

void WalkGame::initView(QGraphicsView *vue)
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

    this->assetList.clear();
    this->assetList.append(player);
    this->assetList.append(poubelle);
    this->assetList.append(passant);
    this->assetList.append(chien);
}
