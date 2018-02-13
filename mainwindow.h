#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsItem>
#include <QGraphicsView>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    void mouseMoveEvent(QMouseEvent *event);
    int step;
    QGraphicsView * vue;
    QList<QGraphicsItem*> wg_listeItems;
    QList<QGraphicsItem*> kg_listeItems;
    QList<QGraphicsItem*> dg_listeItems;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QGraphicsView *getVue() const;

    void setWGListeItems(const QList<QGraphicsItem *> &value);
    void setKGListeItems(const QList<QGraphicsItem *> &value);
    void setDGListeItems(const QList<QGraphicsItem *> &value);

    void changeStep();

private:
    Ui::MainWindow *ui;
    bool eventFilter(QObject *obj, QEvent *event);
};

#endif // MAINWINDOW_H
