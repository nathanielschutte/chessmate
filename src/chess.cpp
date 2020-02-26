/**
 * Game runner
 */

#include <stdio.h>
#include "chess.h"

namespace CME {

    const bool DEBUG = true;

    int runGame(FileLogger& logger)
    {

    }


    int gameLoop(FileLogger& logger)
    {

        const float FPS = 60.0f;
        const float DELTA = 1.0f / FPS;

        int frames = 0;
        int updates = 0;

        sf::Clock clock;
        sf::Clock timer;
        sf::RenderWindow window(sf::VideoMode(900, 600), "chessmate");

        float time_actual = clock.getElapsedTime().asSeconds();
        int32_t timer_last = clock.getElapsedTime().asMilliseconds();
        float acc = 0.0f;

        bool redraw = true;

        while(window.isOpen()) {

            window.clear();

            float time_new = clock.getElapsedTime().asSeconds();
            float time_frame = time_new - time_actual;
            time_actual = time_new;

            if(time_frame > 0.25f) {
                time_frame = 0.25f;
            }

            acc += time_frame;

            redraw = true;

            while(acc >= DELTA) {
                updates++;
                update(window, DELTA);
                acc -= DELTA;
                redraw = true;
            }

            const float interpolate = acc / DELTA;

            if(redraw) {
                frames++;
                draw(window, interpolate);
            }

            window.display();

            if(DEBUG && (timer.getElapsedTime().asMilliseconds() - timer_last) >= 1000) {
                timer_last += 1000;

                std::printf("FPS: %u\tUPS: %u\n", frames, updates);

                frames = 0;
                updates = 0;
            }

            sf::sleep(sf::milliseconds(1));
        }

        return 0;
    }

    void update(sf::RenderWindow& window, const float time_delta)
    {
sf::Event event;
        while(window.pollEvent(event)) {

            if(event.type == sf::Event::Closed) {
                window.close();
            }
        }

    }


    void draw(sf::RenderTarget& target, const float interp)
    {

    }

}
