#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cstddef>

#include <QMouseEvent>

QGraphicsView *MainWindow::getVue() const
{
    return vue;
}

void MainWindow::setScenario(Scenario *s)
{
    this->scenario = s;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->step = 3; // En dur, comme ça c'est bien dégueu
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


// COORDONNEES DU CURSEUR + Gameloop
bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    switch (this->scenario->getCurrentGame()->getType()) {
    case GameType::DG:
        if(event->type() == QEvent::KeyPress){
            this->changeStep();
        }
        break;
    case GameType::KG:
        if(event->type() == QEvent::KeyPress){
            this->changeStep();
        }
        break;
    case GameType::WG:
        if (event->type() == QEvent::MouseMove)
      {
            if(this->scenario->getCurrentGame()->getAssetList().size()>0)
            {
                QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);

                this->scenario->getCurrentGame()->getAssetList().first()->setY(mouseEvent->pos().y()-this->scenario->getCurrentGame()->getAssetList().first()->boundingRect().center().y());
                this->scenario->getCurrentGame()->getAssetList().first()->setX(this->scenario->getCurrentGame()->getAssetList().first()->x()+0.2);
                this->scenario->getCurrentGame()->getAssetList().last()->setX(this->scenario->getCurrentGame()->getAssetList().last()->x()-0.5);
                if(this->scenario->getCurrentGame()->getAssetList().first()->x()>850)
                    qInfo("Bravo"); //TODO faire la condition de victoire
                if(this->scenario->getCurrentGame()->getAssetList().first()->collidingItems().size()>0)
                    qInfo("Perdu"); //TODO faire la condition de défaite
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
