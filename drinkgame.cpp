#include "drinkgame.h"

DrinkGame::DrinkGame(int profil):Game(profil)
{
    this->type=GameType::DG;
}

void DrinkGame::initView(QGraphicsView *vue)
{
    qInfo("1");
    // on démarre le suivi de la souris
    vue->setMouseTracking(true);
qInfo("2");
    // initialisation de la scène
    QGraphicsScene *scene = new QGraphicsScene();
    qInfo("21");
    scene->setSceneRect(0,0,850,550);
    qInfo("22");
    QString backGround = "C:/Users/M2IHM/Documents/Antoine/HapticProject/asset/bg_drinkgame.png";
    qInfo("23");
    scene->setBackgroundBrush(QBrush(QImage(backGround)));
qInfo("3");
    // creation de la bouteille
    //QGraphicsRectItem *player = new QGraphicsRectItem();
    //player->setRect(0,100,120,220);
    QGraphicsPixmapItem *player = new QGraphicsPixmapItem(QPixmap("C:/Users/M2IHM/Documents/Antoine/HapticProject/asset/bottle.png"));
    player->moveBy(0,100);
    scene->addItem(player);
qInfo("4");
    // creation du verre
    //QGraphicsRectItem *verre = new QGraphicsRectItem();
    //verre->setRect(700,400,80,110);
    QGraphicsPixmapItem *verre = new QGraphicsPixmapItem(QPixmap("C:/Users/M2IHM/Documents/Antoine/HapticProject/asset/empty_glass.png"));
    verre->moveBy(700,400);
    scene->addItem(verre);
qInfo("5");
    vue->setScene(scene);
qInfo("6");
    this->assetList.clear();
    this->assetList.append(player);
    this->assetList.append(verre);
qInfo("7");
}
