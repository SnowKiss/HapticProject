#ifndef KEYGAME_H
#define KEYGAME_H

#include "game.h"

class KeyGame: public Game
{
private:
    bool gameover;
public:
    KeyGame(int id);
    bool getGameover() const;
    void setGameover(bool value);
};

#endif // KEYGAME_H
