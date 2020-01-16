/**
 * Outermost game shell.  Call the primary game loop.
 *
 * @file src/main.cpp
 * @author Nate Schutte
 * @date 20200113 - initial development
 *
 */

#include "CME/FileLogger.h"
#include "CME/

using namespace CME;

int main(int argc, char* argv[]) {

    int exitCode = 0;

    FileLogger logger("output.txt", true);

    // InputHandler input_handler

    // StateHandler state_handler

    // GameChess chess(logger, input_handler, state_handler);

    exitCode = chess.runGame(logger);

    return exitCode;
}
