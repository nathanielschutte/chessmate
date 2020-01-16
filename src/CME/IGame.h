#ifndef IGAME_H
#define IGAME_H

#include <SFML/Graphics.hpp>

#include "FileLogger.h"
#include "IPlayer.h"

namespace CME {
    class IGame {
        public:
            IGame(FileLogger& logger);

            virtual ~IGame();

            int runGame();

        protected:

            FileLogger logger;

            // InputHandler input_handler

            // StateHandler state_handler

            IState state_cur;

            // InputHandler
            // StateHandler

            /**
            * Chance to init before loop
            * init Handlers and add components to them
            */
            void init(void);

            /**
            * Game loop
            */
            int gameLoop(void);

            /**
            * Internal update called from game loop
            */
            void update(sf::RenderWindow& window, const float time_delta);

            /**
            * Internal draw called from game loop
            */
            void draw(sf::RenderTarget& target, const float interp);

    };
}

#endif // IGAME_H
