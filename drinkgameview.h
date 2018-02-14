#ifndef DRINKGAMEVIEW_H
#define DRINKGAMEVIEW_H

#include <QGraphicsView>

class DrinkGameView
{
private:
    QList<QGraphicsItem*> componentList;
public:
    DrinkGameView(QGraphicsView * vue);
    QList<QGraphicsItem *> getComponentList() const;
};

#endif // DRINKGAMEVIEW_H
