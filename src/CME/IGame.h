#ifndef IGAME_H
#define IGAME_H

#include <SFML/Graphics.hpp>

#include "FileLogger.h"
#include "InputHandler.h"
#include "StateHandler.h"
#include "IState.h"

namespace CME {
    class IGame {
        public:
            IGame();

            virtual ~IGame();

            virtual int runGame() = 0;

        protected:

            InputHandler input_handler;

            StateHandler state_handler;

            IState* state_cur;

            bool m_running;

            int m_exit_code = 0;

            /**
            * Chance to init before loop
            * init Handlers and add components to them
            */
            virtual void init(void) = 0;

            /**
            * Game loop
            */
            virtual int gameLoop(void) = 0;

            /**
            * Internal update called from game loop
            */
            virtual void update(sf::RenderWindow& window, const float time_delta) = 0;

            /**
            * Internal draw called from game loop
            */
            virtual void draw(sf::RenderTarget& target, const float interp) = 0;

    };
}

#endif // IGAME_H
