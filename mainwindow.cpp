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

MainWindow::MainWindow(Scenario *scenario, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->scenario = scenario;
    this->setMouseTracking(true);
    ui->setupUi(this);
    this->setMaximumWidth(900);
    this->setMaximumHeight(600);
    this->setFixedSize(this->maximumSize());
    this->vue=ui->graphicsView;
    this->vue->setFixedSize(850,550);
    qApp->installEventFilter(this);
    this->hHandler = new HapticHandler(this);
    hHandler->getProjet()->Start("Momentum");
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

    if(this->scenario)
    {
        switch (this->scenario->getCurrentGame()->getType()) {
        case GameType::DG:
            if(buttonPressed)
            {
                this->scenario->getCurrentGame()->getAssetList().first()->setTransformOriginPoint(this->scenario->getCurrentGame()->getAssetList().first()->boundingRect().center());
                this->scenario->getCurrentGame()->getAssetList().first()->setRotation(this->scenario->getCurrentGame()->getAssetList().first()->rotation()+0.005);
                if(this->scenario->getCurrentGame()->getAssetList().first()->rotation()>90)
                {
                    if((this->scenario->getCurrentGame()->getAssetList().first()->x() > 530)&&(this->scenario->getCurrentGame()->getAssetList().first()->x() < 600))
                    {
                        this->scenario->getCurrentGame()->setWin(true);
                        this->scenario->nextGame();
                        this->scenario->getCurrentGame()->initView(this->getVue());
                    }
                    else
                    {
                        //qInfo("Perdu");
                        this->buttonPressed=false;
                        this->scenario->getCurrentGame()->initView(this->getVue());
                    }
                }
            }
            if (event->type() == QEvent::MouseMove)
            {
                  if(this->scenario->getCurrentGame()->getAssetList().size()>0)
                  {
                      QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
                      this->scenario->getCurrentGame()->getAssetList().first()->setX(mouseEvent->pos().x()-this->scenario->getCurrentGame()->getAssetList().first()->boundingRect().center().x());
                  }

            }
            if (event->type() == QEvent::MouseButtonPress)
            {
                this->buttonPressed=true;
            }
            if (event->type() == QEvent::MouseButtonRelease)
            {
                this->buttonPressed=false;
            }

          return false;
            break;
        case GameType::KG:
            if (event->type() == QEvent::MouseMove)
            {
                  if(this->scenario->getCurrentGame()->getAssetList().size()>0)
                  {
                      QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
                      this->scenario->getCurrentGame()->getAssetList().first()->setX(mouseEvent->pos().x()-this->scenario->getCurrentGame()->getAssetList().first()->boundingRect().center().x());
                      this->scenario->getCurrentGame()->getAssetList().first()->setY(mouseEvent->pos().y()-this->scenario->getCurrentGame()->getAssetList().first()->boundingRect().center().y());
                  }

            }
            if (event->type() == QEvent::MouseButtonPress)
            {
                if(this->scenario->getCurrentGame()->getAssetList().first()->collidingItems().size()>0)
                {
                    //qInfo("Bravo");
                    this->scenario->getCurrentGame()->setWin(true);
                    this->scenario->nextGame();
                    this->scenario->getCurrentGame()->initView(this->getVue());
                }
                else
                {
                    //qInfo("Perdu");
                    this->scenario->getCurrentGame()->initView(this->getVue());
                }
            }

          return false;
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
                      this->scenario->getCurrentGame()->getAssetList().at(2)->setX(this->scenario->getCurrentGame()->getAssetList().at(2)->x()-0.1);
                      if(this->scenario->getCurrentGame()->getAssetList().first()->x()>850)
                      {
                          //this->scenario->getCurrentGame()->setWin(true);
                          this->scenario->nextGame();
                          this->scenario->getCurrentGame()->initView(this->getVue());
                      }

                      else if(this->scenario->getCurrentGame()->getAssetList().first()->collidingItems().size()>0)
                      {
                          //qInfo("Perdu");
                          this->scenario->getCurrentGame()->initView(this->getVue());
                      }

                  }

            }
            return false;
            break;
        case GameType::PAN:
            if (event->type() == QEvent::MouseButtonPress)
            {
                if(next==false)
                {
                    //qInfo("passe");
                    this->scenario->nextGame();
                    this->scenario->getCurrentGame()->initView(this->getVue());
                    next=true;
                }

            }
            if (event->type() == QEvent::MouseButtonRelease)
            {
                next=false;
            }
            return false;
            break;
        default:
            return false;
            break;
        }
    }

}


