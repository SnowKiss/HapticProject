#ifndef WALKGAME_H
#define WALKGAME_H


class WalkGame
{
private:
    bool gameover;
public:
    WalkGame();
    bool getGameover() const;
    void setGameover(bool value);
};

#endif // WALKGAME_H
