#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "scenario.h"
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QMainWindow>
#include "haptichandler.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    void mouseMoveEvent(QMouseEvent *event);
    QGraphicsView * vue;
    Scenario * scenario;
    bool buttonPressed = false;
    bool next = false;
public:
    explicit MainWindow(Scenario * scenario, QWidget *parent = 0);
    ~MainWindow();
    QGraphicsView *getVue() const;
    void setScenario(Scenario * s);
private:
    Ui::MainWindow *ui;
    bool eventFilter(QObject *obj, QEvent *event);
    HapticHandler *hHandler;
    void changeProfile();
    int currentProfile;
};

#endif // MAINWINDOW_H
