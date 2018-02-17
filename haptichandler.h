#ifndef HAPTICHANDLER_H
#define HAPTICHANDLER_H


#undef UNICODE

//#include "mainwindow.h"
#include <QDebug>
#include <QApplication>
#include <ifc.h>

class MainWindow;

class HapticHandler
{
private:
    CImmMouse *souris;
    CImmProject  *projet;
    MainWindow *mFenetre;

public:
    HapticHandler(MainWindow * fen);
    ~HapticHandler();
    CImmProject *getProjet();
};

#endif // HAPTICHANDLER_H
