#ifndef GAME_H
#define GAME_H
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QList>
#include <gametype.h>

class Game
{
protected:
    QList<QGraphicsItem*> componentList;
    GameType type;
    QList<QGraphicsItem*> assetList;
    bool gameover;
    bool win;
public:
    Game();
    QList<QGraphicsItem *> getAssetList() const;
    void addItem(QGraphicsItem* item);
    GameType getType() const;
    bool getGameover() const;
    void setGameover(bool value);
    bool getWin() const;
    void setWin(bool value);
    virtual void initView(QGraphicsView *vue);
};

#endif // GAME_H
