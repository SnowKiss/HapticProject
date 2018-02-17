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
    QGraphicsSimpleTextItem *text = new QGraphicsSimpleTextItem(QString::fromStdString(this->message));
    text->setFont( QFont( "Calibri", 20 ) );
    text->setPos(QPoint(425-text->boundingRect().width()/2,275-text->boundingRect().height()/2));
    scene->addItem(text);
    vue->setScene(scene);

    //this->assetList.clear();
}
