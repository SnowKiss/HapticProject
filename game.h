#ifndef GAME_H
#define GAME_H


class Game
{
private:
    int id;
public:
    Game(int id);
    virtual int getId();
};

#endif // GAME_H
