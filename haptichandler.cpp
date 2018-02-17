#include "haptichandler.h"
#include "mainwindow.h"
HapticHandler::HapticHandler(MainWindow * fen):mFenetre(fen)
{
    souris = new CImmMouse();


    // if (!souris->Initialize(qApp->applicationPid(),  fen->effectiveWinId()  ))
    if (!souris->Initialize(qWinAppInst(),  (HWND)mFenetre->effectiveWinId()  )){
        qDebug()<<"===>Erreur chargement souris "<<souris;
        delete souris;
        souris = NULL;
        qApp->quit();
    }

    projet = new CImmProject();

    if (projet->OpenFile("C:\\Users\\M2IHM\\Documents\\Antoine\\HapticProject\\profil.ifr", souris)){
        //le chemin par d�faut est celui o� se trouve la g�n�ration : xxx-build-desktop/
        qDebug()<<"Projet ifr charg�";
    }
    else
    {
        qDebug()<<"===>Erreur chargement projet IFR avec code "<<CIFCErrors::GetLastErrorCode() ;
    }
    qDebug()<<"I'm done creating";
}

HapticHandler::~HapticHandler()
{
    if(projet)
        delete projet;
    if(souris)
        delete souris;
}

CImmProject *HapticHandler::getProjet()
{
    return projet;
}
