/**
 * Outermost game shell.  Call the primary game loop.
 *
 * @file src/main.cpp
 * @author Nate Schutte
 * @date 20200113 - initial development
 *
 */

#include <assert.h>
#include <stddef.h>
#include "GameChess.h"

int main(int argc, char* argv[]) {

    int exitCode = 0;

    CME::FileLogger logger("output.txt", true);
    logger.setActive(true);

    GameChess* chess = new(std::nothrow) GameChess();
    assert(NULL != chess && "main() failed to create game");

    exitCode = chess->runGame();

    delete chess;
    chess = NULL;

    return exitCode;
}


