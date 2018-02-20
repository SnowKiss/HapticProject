#ifndef GAME_H
#define GAME_H
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QList>
#include <gametype.h>

/**
 * @brief La classe jeu
 * La classe abstraite réunnissant les mini-jeux
 */
class Game
{
protected:
    //Le type d'un jeu. Défini son type
    GameType type;
    //La liste des assets d'un jeu
    QList<QGraphicsItem*> assetList;
    //Deux booleens pour indiquer le statut de la partie
    bool gameover;
    bool win;
    //Le profil haptique associé au jeu
    int profil;
public:
    Game(int profil);
    QList<QGraphicsItem *> getAssetList() const;
    void addItem(QGraphicsItem* item);
    GameType getType() const;
    bool getGameover() const;
    void setGameover(bool value);
    bool getWin() const;
    void setWin(bool value);
    //La fonction qui initialise les item dans la vue donnée.
    virtual void initView(QGraphicsView *vue);
    int getProfil();
};

#endif // GAME_H
