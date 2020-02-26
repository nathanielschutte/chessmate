#ifndef CHESS_H_INCLUDED
#define CHESS_H_INCLUDED

#include <SFML/Graphics.hpp>

#include "FileLogger.h"
#include "IPlayer.h"


namespace CME {

    int runGame(FileLogger& logger);

    void update(sf::RenderWindow& window, const float time_delta);

    void draw(sf::RenderTarget& target, const float interp);


    // private
    int gameLoop(FileLo)

    // references
    FileLogger& logger;
}


#endif // CHESS_H_INCLUDED

