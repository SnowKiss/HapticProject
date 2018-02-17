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

Scenario * initScenario();

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    // on crée les scenes et le scenario
    Scenario* s = initScenario();

    // on crée la vue
    MainWindow w(s);
    w.show();

    // on lance la musicloop
    // TODO musicloop

    // on charge la vue du jeu courant
    s->getCurrentGame()->initView(w.getVue());




    return a.exec();;
}

Scenario * initScenario()
{
    Scenario * s = new Scenario();

    Panneau * p1 = new Panneau("Bienvenue (cliquez pour continuer)");
    s->addGame(p1);
    s->setCurrentGame(p1);

    Panneau * p2 = new Panneau("Nous allons vous raconter l'histoire de Bob");
    s->addGame(p2);

    Panneau * p3 = new Panneau("Bob est une personne comme les autres");
    s->addGame(p3);

    Panneau * p4 = new Panneau("Et comme tout le monde, il sait se servir un verre");
    s->addGame(p4);

    DrinkGame * dg = new DrinkGame();
    s->addGame(dg);
    //s->setCurrentGame(dg);

    Panneau * p5 = new Panneau("Un très bon cru !");
    s->addGame(p5);

    Panneau * p6 = new Panneau("Il est désormais tant de sortir...");
    s->addGame(p6);

    Panneau * p7 = new Panneau("... n'oublions pas de fermer la porte !");
    s->addGame(p7);

    KeyGame * kg = new KeyGame();
    s->addGame(kg);
    //s->setCurrentGame(kg);

    Panneau * p8 = new Panneau("La porte est clôse !");
    s->addGame(p8);

    Panneau * p9 = new Panneau("Mais l'heure tourne, les amis de Bob l'attendent !");
    s->addGame(p9);

    WalkGame * wg = new WalkGame();
    s->addGame(wg);
    //s->setCurrentGame(wg);

    Panneau * p10 = new Panneau("C'est parti ! Laissons Bob avec ses amis !");
    s->addGame(p10);

    Panneau * p11 = new Panneau("Premier verre");
    s->addGame(p11);

    Panneau * p12 = new Panneau("La fête de fait que commencer !");
    s->addGame(p12);

    Panneau * p13 = new Panneau("Un deuxième...");
    s->addGame(p13);

    Panneau * p14 = new Panneau("Un troisième...");
    s->addGame(p14);

    Panneau * p15 = new Panneau("[...]");
    s->addGame(p15);

    Panneau * p16 = new Panneau("Quelques heures sont passées");
    s->addGame(p16);

    Panneau * p17 = new Panneau("Bob veut un dernier verre");
    s->addGame(p17);

    DrinkGame * dg2 = new DrinkGame();
    s->addGame(dg2);

    Panneau * p18 = new Panneau("Ouh là...");
    s->addGame(p18);

    Panneau * p19 = new Panneau("Il est vraiment temps de rentrer...");
    s->addGame(p19);

    Panneau * p20 = new Panneau("A nous deux, la porte !");
    s->addGame(p20);

    KeyGame * kg2 = new KeyGame();
    s->addGame(kg2);

    Panneau * p21 = new Panneau("Plus que quelques pas...");
    s->addGame(p21);

    WalkGame * wg2 = new WalkGame();
    s->addGame(wg2);

    Panneau * p22 = new Panneau("Bob tombe de sommeil en passant le pas de sa porte");
    s->addGame(p22);

    Panneau * p23 = new Panneau("Un repos bien mérité !");
    s->addGame(p23);

    Panneau * p24 = new Panneau("[...]");
    s->addGame(p24);

    Panneau * p25 = new Panneau("Dimanche matin");
    s->addGame(p25);

    Panneau * p26 = new Panneau("Difficile comme réveil...");
    s->addGame(p26);

    Panneau * p27 = new Panneau("Mais Bob a promis à sa grand-mère de lui rendre visite...");
    s->addGame(p27);

    Panneau * p28 = new Panneau("Quand faut y aller, faut y aller...");
    s->addGame(p28);

    DrinkGame * dg3 = new DrinkGame();
    s->addGame(dg3);

    Panneau * p29 = new Panneau("La...");
    s->addGame(p29);

    Panneau * p30 = new Panneau("La... porte");
    s->addGame(p30);

    KeyGame * kg3 = new KeyGame();
    s->addGame(kg3);

    Panneau * p31 = new Panneau("Trop de... soleil...");
    s->addGame(p31);

    WalkGame * wg3 = new WalkGame();
    s->addGame(wg3);

    Panneau * p32 = new Panneau("Bob a finalement vu sa grand-mère");
    s->addGame(p32);

    Panneau * p33 = new Panneau("Mais a t-il vraiment profité ?");
    s->addGame(p33);

    Panneau * p34 = new Panneau("L'abus d'alcool est dangereux pour la santé");
    s->addGame(p34);

    Panneau * p36 = new Panneau("Et ses effets ne s'arrêtent avec la soirée");
    s->addGame(p36);

    Panneau * p37 = new Panneau("Pensez aux autres");
    s->addGame(p37);

    Panneau * p38 = new Panneau("Pensez A VOUS !");
    s->addGame(p38);

    Panneau * p39 = new Panneau("Buvez avec modération !");
    s->addGame(p39);

    return s;
}
