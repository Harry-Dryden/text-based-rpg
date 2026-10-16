#include "Game.h"
#include "Logger.h"

int main()
{
    Game game;
    Logger log;
    log.Log(LogLevel::INFO, "Start Up");

    game.Run();

    return 0;
}