#ifndef STATEGAME_H
#define STATEGAME_H

#include "IState.h"
#include <fstream>

namespace CME {
    class StateGame : public IState
    {
        public:
            StateGame();
            ~StateGame();

            int init();

            int deinit();

            int reinit();

            void clean(); // save and clean

            void update(sf::RenderWindow& window, const float time_delta);

            void draw(sf::RenderTarget& target, const float interp);


        protected:

        private:

            std::string test_data;
            sf::Font font;
            sf::Text text;
            int test_counter;

    };
}

#endif // STATEGAME_H
