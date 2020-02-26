#ifndef GAMECHESS_H
#define GAMECHESS_H

#include "CME/IGame.h"

#include <stdio.h>

const bool DEBUG = true;
const float FPS = 240.0f;

class GameChess : public CME::IGame
{
    public:
        GameChess();

        ~GameChess();

        int runGame();

    protected:

    private:

        void init(void);

        int gameLoop(void);

        void update(sf::RenderWindow& window, const float time_delta);

        void draw(sf::RenderTarget& target, const float interp);
};

#endif // GAMECHESS_H
