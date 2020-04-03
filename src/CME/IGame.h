#ifndef IGAME_H
#define IGAME_H

#include "FileLogger.h"
#include "InputHandler.h"
#include "StateHandler.h"

namespace CME {

    class StateHandler;
    class InputHandler;

    class IGame {
        public:
            IGame();
            ~IGame();

            virtual int runGame();

            inline const InputHandler& getInputHandler() { return input_handler; }
            inline const StateHandler& getStateHandler() { return state_handler; }

        protected:

            InputHandler input_handler;

            StateHandler state_handler;

            bool m_running;

            int m_exit_code = 0;


            /**
            * Chance to init before loop
            * init Handlers and add components to them
            */
            virtual void init(void) = 0;

            /**
            * Chance to clean before deconstruct
            */
            virtual void clean(void) = 0;

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
