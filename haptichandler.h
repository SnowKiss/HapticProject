#ifndef HAPTICHANDLER_H
#define HAPTICHANDLER_H


#undef UNICODE

//#include "mainwindow.h"
#include <QDebug>
#include <QApplication>
#include <ifc.h>



class HapticHandler
{
public:
    HapticHandler(MainWindow * fen);
    ~HapticHandler();
    CImmProject *getProjet();

    CImmInertia *getInertie();
    CImmInertia *getMomentum();

private:
    CImmMouse *souris;
    CImmProject  *projet;

    CImmInertia *inertie;
    CImmInertia *momentum;
    MainWindow *mFenetre;

};

#endif // HAPTICHANDLER_H
