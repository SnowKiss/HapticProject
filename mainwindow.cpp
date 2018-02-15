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
                QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
                this->scenario->getCurrentGame()->getAssetList().first()->setRotation(this->scenario->getCurrentGame()->getAssetList().first()->rotation()+0.2);
                this->scenario->getCurrentGame()->getAssetList().first()->setX(mouseEvent->pos().x()-this->scenario->getCurrentGame()->getAssetList().first()->boundingRect().center().x());
                this->scenario->getCurrentGame()->getAssetList().first()->setY(mouseEvent->pos().y()-this->scenario->getCurrentGame()->getAssetList().first()->boundingRect().center().y());
                if(this->scenario->getCurrentGame()->getAssetList().first()->rotation()>90)
                {
                    if(this->scenario->getCurrentGame()->getAssetList().first()->x() > 200) //TODO refaire la condition
                    {
                        std::string s = std::to_string(this->scenario->getCurrentGame()->getAssetList().first()->x());
                        char const *pchar = s.c_str();
                        qInfo(pchar);
                    }
                    else
                    {
                        qInfo("Perdu");
                    }
                }

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
                    qInfo("Bravo");
                }
                else
                {
                    qInfo("Perdu");
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
                      //this->scenario->getCurrentGame()->initView(this->getVue());
                      this->scenario->getCurrentGame()->getAssetList().first()->setY(mouseEvent->pos().y()-this->scenario->getCurrentGame()->getAssetList().first()->boundingRect().center().y());
                      this->scenario->getCurrentGame()->getAssetList().first()->setX(this->scenario->getCurrentGame()->getAssetList().first()->x()+0.2);
                      this->scenario->getCurrentGame()->getAssetList().last()->setX(this->scenario->getCurrentGame()->getAssetList().last()->x()-0.5);
                      if(this->scenario->getCurrentGame()->getAssetList().first()->x()>850)
                      {
                          qInfo("Bravo"); //TODO faire la condition de victoire
                          this->scenario->getCurrentGame()->setWin(true);
                          this->scenario->nextGame();
                          this->scenario->getCurrentGame()->initView(this->getVue());
                      }

                      if(this->scenario->getCurrentGame()->getAssetList().first()->collidingItems().size()>0)
                      {
                          qInfo("Perdu"); //TODO faire la condition de défaite
                          this->scenario->getCurrentGame()->initView(this->getVue());
                      }

                  }

            }


          return false;

            break;
        default:
            break;
        }
    }

}


