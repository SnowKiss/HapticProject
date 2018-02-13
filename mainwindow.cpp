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

void MainWindow::setListeItems(const QList<QGraphicsItem *> &value)
{
    listeItems = value;
}


// COORDONNEES DU CURSEUR + Gameloop
bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseMove)
  {
        if(this->listeItems.size()>0)
        {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);

            this->listeItems.first()->setY(mouseEvent->pos().y()-this->listeItems.first()->boundingRect().center().y());
            this->listeItems.first()->setX(this->listeItems.first()->x()+0.2);
            this->listeItems.last()->setX(this->listeItems.last()->x()-0.5);
        }
  }
  return false;
}
