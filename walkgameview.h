#ifndef WALKGAMEVIEW_H
#define WALKGAMEVIEW_H

#include <QGraphicsView>

class WalkGameView
{
private:
    QList<QGraphicsItem*> componentList;
public:
    WalkGameView(QGraphicsView * vue);
    QList<QGraphicsItem *> getComponentList() const;
};

#endif // WALKGAMEVIEW_H
