#include "drinkgame.h"

DrinkGame::DrinkGame()
{
    this->type=GameType::DG;
}

void DrinkGame::initView(QGraphicsView *vue)
{
    // on démarre le suivi de la souris
    vue->setMouseTracking(true);

    // initialisation de la scène
    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(0,0,850,550);

    // creation de la bouteille
    QGraphicsRectItem *player = new QGraphicsRectItem();
    player->setRect(0,100,120,220);
    scene->addItem(player);

    // creation du verre
    QGraphicsRectItem *verre = new QGraphicsRectItem();
    verre->setRect(700,400,80,110);
    scene->addItem(verre);

    vue->setScene(scene);

    this->assetList.clear();
    this->assetList.append(player);
    this->assetList.append(verre);
}
