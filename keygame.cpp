#include "keygame.h"

KeyGame::KeyGame() : Game()
{
    this->type=GameType::KG;
}

void KeyGame::initView(QGraphicsView *vue)
{
    // on démarre le suivi de la souris
    vue->setMouseTracking(true);

    // initialisation de la scène
    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(0,0,850,550);

    // creation de la clef
    QGraphicsEllipseItem *player = new QGraphicsEllipseItem(200,200,20,20);
    scene->addItem(player);

    // creation de la serrure
    QGraphicsEllipseItem *serrure = new QGraphicsEllipseItem(500,300,100,100);
    scene->addItem(serrure);

    vue->setScene(scene);

    this->assetList.clear();
    this->assetList.append(player);
    this->assetList.append(serrure);
}

