#include "walkgame.h"


WalkGame::WalkGame(int profil) : Game(profil)
{
    this->type=GameType::WG;
}

void WalkGame::initView(QGraphicsView *vue)
{
    // on démarre le suivi de la souris
    vue->setMouseTracking(true);

    // initialisation de la scène
    QGraphicsScene *scene = vue->scene();
    scene->clear();
    scene->setSceneRect(0,0,850,550);
    QString backGround = "C:/Users/M2IHM/Documents/Antoine/HapticProject/asset/bg_walkgame.png";
    scene->setBackgroundBrush(QBrush(QImage(backGround)));

    // creation du personnage
    //QGraphicsRectItem *player = new QGraphicsRectItem();
    //player->setRect(0,0,80,180);
    QGraphicsPixmapItem *player = new QGraphicsPixmapItem(QPixmap("C:/Users/M2IHM/Documents/Antoine/HapticProject/asset/man.png"));
    player->moveBy(0,200);
    scene->addItem(player);

    // creation de la poubelle
    //QGraphicsRectItem *poubelle = new QGraphicsRectItem();
    //poubelle->setRect(250,100,80,80);
    QGraphicsPixmapItem *poubelle = new QGraphicsPixmapItem(QPixmap("C:/Users/M2IHM/Documents/Antoine/HapticProject/asset/trash.png"));
    poubelle->moveBy(230,200);
    scene->addItem(poubelle);

    // creation du passant
    //QGraphicsRectItem *passant = new QGraphicsRectItem();
    //passant->setRect(500,400,80,80);
    QGraphicsPixmapItem *passant = new QGraphicsPixmapItem(QPixmap("C:/Users/M2IHM/Documents/Antoine/HapticProject/asset/oldman.png"));
    passant->moveBy(700,50);
    scene->addItem(passant);

    // creation du chien
    //QGraphicsRectItem *chien = new QGraphicsRectItem();
    //chien->setRect(1000,300,80,80);
    QGraphicsPixmapItem *chien = new QGraphicsPixmapItem(QPixmap("C:/Users/M2IHM/Documents/Antoine/HapticProject/asset/dog.png"));
    chien->moveBy(1000,400);
    scene->addItem(chien);

    vue->setScene(scene);

    this->assetList.clear();
    this->assetList.append(player);
    this->assetList.append(poubelle);
    this->assetList.append(passant);
    this->assetList.append(chien);
}
