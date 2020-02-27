#ifndef GAMECHESS_H
#define GAMECHESS_H

#include "CME/IGame.h"

#include <stdio.h>

const bool DEBUG = true;
const float FPS = 240.0f;

class GameChess : public CME::IGame
{
    const CME::ref_id GAME = 0;
    const CME::ref_id START = 1;
    const CME::ref_id POSTGAME = 2;
    const CME::ref_id HOLD = 3;

    public:
        GameChess(CME::FileLogger* log);

        ~GameChess();

        int runGame();

    protected:

    private:

        // ===========================

        void init(void);

        void clean(void);

        int gameLoop(void);

        void update(sf::RenderWindow& window, const float time_delta);

        void draw(sf::RenderTarget& target, const float interp);
};

#endif // GAMECHESS_H
