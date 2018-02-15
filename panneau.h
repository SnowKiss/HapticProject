#ifndef PANNEAU_H
#define PANNEAU_H
#include "game.h"

#include <string>

class Panneau: public Game
{
private:
    std::string message;
public:
    Panneau(std::string msg);
    virtual void initView(QGraphicsView *vue);
};

#endif // PANNEAU_H
