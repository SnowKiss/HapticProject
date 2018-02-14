#ifndef KEYGAMEVIEW_H
#define KEYGAMEVIEW_H

#include <QGraphicsView>

class KeyGameView
{
private:
    QList<QGraphicsItem *> componentList;
public:
    KeyGameView(QGraphicsView * vue);
    QList<QGraphicsItem *> getComponentList() const;
};

#endif // KEYGAMEVIEW_H
