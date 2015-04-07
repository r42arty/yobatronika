

#include "Game.h"
using namespace Yoba;


int main(int argc, char* args[])
{
    Game game(100, 100, 640, 480);
    while(game.running())
    {
        game.handleEvents();
        game.update();
        game.render();
        
        SDL_Delay(10);
    }
    
    return 0;
}
