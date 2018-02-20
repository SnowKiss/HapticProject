#ifndef PANNEAU_H
#define PANNEAU_H
#include "game.h"

#include <string>
/**
 * @brief La classe des panneau
 * Herite de game par commodité.
 */
class Panneau: public Game
{
private:
    std::string message;
public:
    Panneau(std::string msg, int profil);
    virtual void initView(QGraphicsView *vue);
};

#endif // PANNEAU_H
