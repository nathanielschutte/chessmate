/**
 * Outermost game shell.  Call the primary game loop.
 *
 * @file src/main.cpp
 * @author Nate Schutte
 * @date 20200113 - initial development
 *
 */

#include "CME/FileLogger.h"

using namespace CME;

int main(int argc, char* argv[]) {

    int exitCode = 0;

    FileLogger logger("output.txt", true);

    logger.logMessage("main.cpp logging message!");

    logger.logMessage(__FILE__, __LINE__, "message produced here!");

    return exitCode;
}
