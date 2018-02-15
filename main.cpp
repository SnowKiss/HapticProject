/********************************************************************/
/* CLASSE MAIN                                                      */
/*      - Initialisation du modèle                                  */
/*      - Démarrage de la gameloop                                  */
/********************************************************************/

#include "mainwindow.h"
#include "walkgame.h"
#include <QApplication>
#include <QGraphicsItem>
#include <iostream>
#include <QMouseEvent>
#include <sstream>
#include <string>
#include "drinkgame.h"
#include "keygame.h"
#include "panneau.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    // on crée les scenes et le scenario
    Scenario * s = new Scenario();

    Panneau * p1 = new Panneau("Bienvenue");
    s->addGame(p1);
    s->setCurrentGame(p1);

    DrinkGame * dg = new DrinkGame();
    s->addGame(dg);
    //s->setCurrentGame(dg);

    KeyGame * kg = new KeyGame();
    s->addGame(kg);
    //s->setCurrentGame(kg);

    WalkGame * wg = new WalkGame();
    s->addGame(wg);
    //s->setCurrentGame(wg);



    // on crée la vue
    MainWindow w(s);
    w.show();


    // on charge la vue du jeu courant
    s->getCurrentGame()->initView(w.getVue());




    return a.exec();;
}

