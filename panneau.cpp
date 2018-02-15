#include "panneau.h"

Panneau::Panneau(std::string msg)
{
    this->message=msg;
    this->type=GameType::PAN;
}

void Panneau::initView(QGraphicsView *vue)
{

    // initialisation de la scène
    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(0,0,850,550);

    // creation du message
    //scene->addText(QString::fromStdString(this->message));

    vue->setScene(scene);
    scene->addText("bogotobogo.com", QFont("Arial", 20) );
    this->assetList.clear();
}
