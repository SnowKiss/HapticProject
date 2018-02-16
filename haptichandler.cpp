#include "haptichandler.h"
//#include "mainwindow.h"

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
    if (projet->OpenFile("C:\\Users\\M2IHM\\Documents\\Antoine\\profil.ifr", souris))
   {//le chemin par d�faut est celui o� se trouve la g�n�ration : xxx-build-desktop/
        qDebug()<<"Projet ifr charg�";
        inertie = new CImmInertia();
        if (!inertie->InitializeFromProject(*projet, "Inertie", souris,
                            IMM_PARAM_NODOWNLOAD))
        {qDebug()<<"===>Erreur chargement Inertie";
            delete inertie;
            inertie = NULL;
        }
        momentum = new CImmInertia();
        if (!momentum->InitializeFromProject(*projet, "Momentum", souris,
                            IMM_PARAM_NODOWNLOAD))
        {qDebug()<<"===>Erreur chargement Momentum";
            delete momentum;
            momentum = NULL;
        }
    }
    else
    {
        qDebug()<<"===>Erreur chargement projet IFR avec code "<<CIFCErrors::GetLastErrorCode() ;
    }
}

HapticHandler::~HapticHandler()
{
    if(inertie)
        delete inertie;
    if(momentum)
        delete momentum;
    if(projet)
        delete projet;
    if(souris)
        delete souris;
}

CImmProject *HapticHandler::getProjet()
{
    return projet;
}

CImmInertia *HapticHandler::getInertie()
{
    return this->inertie;
}

CImmInertia *HapticHandler::getMomentum()
{
    return this->momentum;
}
