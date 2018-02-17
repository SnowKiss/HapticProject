#ifndef GAME_H
#define GAME_H
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QList>
#include <gametype.h>

class Game
{
protected:
    GameType type;
    QList<QGraphicsItem*> assetList;
    bool gameover;
    bool win;
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
    virtual void initView(QGraphicsView *vue);
    int getProfil();
};

#endif // GAME_H
