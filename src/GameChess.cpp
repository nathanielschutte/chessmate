#include "GameChess.h"

using namespace sf;


GameChess::GameChess(CME::FileLogger* log)
{
    logger = log;
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
    input_handler = new CME::InputHandler();
    state_handler = new CME::StateHandler();

    // TODO: read saves ? player data, maybe separate handler?
    state_handler->init();
    state_handler->addState(GAME, (CME::IState *) new CME::StateGame());

    // set initial game state before first update
    state_handler->setInitialState(GAME);
}

/**
* Cleanup
*/
void GameChess::clean()
{
    logger->logMessage("Cleaning up GameChess...");
    logger->logMessage("Cleaning game states...");
    delete state_handler;

    logger->logMessage("Removing input handler...");
    delete input_handler;

    logger->logMessage("Done. Exiting game.");
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

        sf::sleep(sf::milliseconds(2));
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

    // check for state change before updating
    // assuming low load for now, consider a slightly longer update
    if(state_handler.requestFlag())
    {
        // pre loading

        try
        {
            state_handler.fulfillRequest();
        }
        catch (char* err_msg)
        {
            logger.logMessage(err_msg);
        }

        // post loading
    }

    state_handler.updateCurrentState(window, time_delta);
}


/**
* Internal draw called from game loop
*/
void GameChess::draw(sf::RenderTarget& target, const float interp)
{
    // this might be it for now

    state_handler.drawCurrentState(target, interp);
}
