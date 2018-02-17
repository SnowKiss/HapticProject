#include "keygame.h"

KeyGame::KeyGame(int profil) : Game(profil)
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
    QString backGround = "C:/Users/M2IHM/Documents/Antoine/HapticProject/asset/bg_keygame.png";
    scene->setBackgroundBrush(QBrush(QImage(backGround)));

    // creation de la serrure
    //QGraphicsEllipseItem *serrure = new QGraphicsEllipseItem(560,300,70,70);
    QGraphicsPixmapItem *serrure = new QGraphicsPixmapItem(QPixmap("C:/Users/M2IHM/Documents/Antoine/HapticProject/asset/keyhole.png"));
    serrure->moveBy(560,300);
    scene->addItem(serrure);

    // creation de la clef
    //QGraphicsEllipseItem *player = new QGraphicsEllipseItem(200,200,20,20);
    QGraphicsPixmapItem *player = new QGraphicsPixmapItem(QPixmap("C:/Users/M2IHM/Documents/Antoine/HapticProject/asset/key.png"));
    player->moveBy(200,200);
    scene->addItem(player);

    vue->setScene(scene);

    this->assetList.clear();
    this->assetList.append(player);
    this->assetList.append(serrure);
}

