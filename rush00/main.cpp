
#include <ncurses.h>
#include "GameSpace.hpp"


int main()
{
    GameSpace *game = new GameSpace();
    srand(time(NULL));
    game->Render();
    std::cout << "\033[1;31m GAME OVER! \033[0m\n" << std::endl;

    delete game;
    return 0;
}
