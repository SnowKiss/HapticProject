#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cstddef>

#include <QMouseEvent>

QGraphicsView *MainWindow::getVue() const
{
    return vue;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->step = 1; // En dur, comme ça c'est bien dégueu
    this->setMouseTracking(true);
    ui->setupUi(this);
    this->setMaximumWidth(900);
    this->setMaximumHeight(600);
    this->setFixedSize(this->maximumSize());
    this->vue=ui->graphicsView;
    this->vue->setFixedSize(850,550);
    qApp->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{

}

void MainWindow::setWGListeItems(const QList<QGraphicsItem *> &value)
{
    wg_listeItems = value;
}

void MainWindow::setDGListeItems(const QList<QGraphicsItem *> &value)
{
    dg_listeItems = value;
}

void MainWindow::setKGListeItems(const QList<QGraphicsItem *> &value)
{
    kg_listeItems = value;
}


// COORDONNEES DU CURSEUR + Gameloop
bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    switch (this->step) {
    case 1:
        if(event->type() == QEvent::KeyPress){
            this->changeStep();
        }
        break;
    case 2:
        if(event->type() == QEvent::KeyPress){
            this->changeStep();
        }
        break;
    case 3:
        if (event->type() == QEvent::MouseMove)
      {
            if(this->wg_listeItems.size()>0)
            {
                QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);

                this->wg_listeItems.first()->setY(mouseEvent->pos().y()-this->wg_listeItems.first()->boundingRect().center().y());
                this->wg_listeItems.first()->setX(this->wg_listeItems.first()->x()+0.2);
                this->wg_listeItems.last()->setX(this->wg_listeItems.last()->x()-0.5);
            }

      }
      return false;
        break;
    default:
        break;
    }

}

void MainWindow::changeStep(){
    this->step++;
    if(this->step >3)
        this->step = 1;
}
