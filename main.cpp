/********************************************************************/
/* CLASSE MAIN                                                      */
/*      - Initialisation du modèle                                  */
/*      - Démarrage de la gameloop                                  */
/********************************************************************/

#include "inputmanager.h"
#include "mainwindow.h"
#include "walkgame.h"
#include "walkgameview.h"
#include <QApplication>
#include <QGraphicsItem>
#include <iostream>
#include <QMouseEvent>
#include <sstream>
#include <string>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    // initialisation de la partie
    WalkGame * wg = new WalkGame();

    // initialisation de la vue
    WalkGameView * wgv = new WalkGameView(w.getVue());
    w.setListeItems(wgv->getComponentList());

    // initilisation de l'entrée
    //w.setMouseTracking(true);
    //w.setMouseTracking(true);

    //InputManager * inputManager = new InputManager(&w, wgv);

    // gameloop
/*    while(!wg->getGameover())
    {
        // on récupère la position de la souris
        int y = inputManager->getPosCoord().y();
        // on applique les mouvements aux objets de la vue
        wgv->getComponentList().first()->setY(y);
        // on vérifie les collisions

            // on atteint la fin de partie
            //wg->setGameover(true);
    }*/

    return a.exec();;
}

//void mouseMoveEvent( QMouseEvent *event ) {
//    qInfo(QString::number(event->pos().y()).toStdString().c_str());
//}
