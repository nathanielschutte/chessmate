#include "GameChess.h"

using namespace sf;

CircleShape shape(20.f);

GameChess::GameChess()
{
    m_pos = 20.0f;
    m_speed = SPEED;
}

GameChess::~GameChess()
{

}

int GameChess::runGame()
{
    m_running = true;

    init();

    gameLoop();

    // handle cleanup

    // self cleanup

    m_running = false;

    return m_exit_code;
}


/**
* Chance to init before loop
* init Handlers and add components to them
*/
void GameChess::init(void)
{
    // TODO: read from config file

    // add game states
    // set initial game state
}

/**
* Game loop
*/
int GameChess::gameLoop(void)
{
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


/**
* Internal update called from game loop
*/
void GameChess::update(sf::RenderWindow& window, const float time_delta)
{

    // SFML events
    sf::Event event;
    while(window.pollEvent(event)) {

        if(event.type == sf::Event::Closed) {
            window.close();
        }
    }

    if(m_pos > 880 || m_pos < 20)
    {
        m_speed *= -1;
    }

    m_pos += m_speed*time_delta;

    shape.setPosition(m_pos, 150.0f);

    // the rest

    // call state update
}


/**
* Internal draw called from game loop
*/
void GameChess::draw(sf::RenderTarget& target, const float interp)
{
    target.draw(shape);
}
