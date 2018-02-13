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
    QGraphicsView * vue;
    QList<QGraphicsItem*> listeItems;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QGraphicsView *getVue() const;

    void setListeItems(const QList<QGraphicsItem *> &value);

private:
    Ui::MainWindow *ui;
    bool eventFilter(QObject *obj, QEvent *event);
};

#endif // MAINWINDOW_H
