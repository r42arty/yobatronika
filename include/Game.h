//
//  Game.h
//  yobatronika
//
//  Created by Maxim Fedorenko on 07.04.15.
//
//

#ifndef __yobatronika__Game__
#define __yobatronika__Game__

#include <SDL.h>

namespace Yoba {
    class Game {
    public:
        static constexpr char const *title = "YOBAtronika";
        
        Game(int xpos, int ypos, int width, int height);
        ~Game();
        
        void render();
        void update();
        void handleEvents();
        
        bool running();
        
    private:
        static constexpr int sdl_init_flags = SDL_WINDOW_SHOWN;
        static constexpr int sdl_render_flags = SDL_RENDERER_PRESENTVSYNC;
        
        bool m_bRunning = false;
        
        SDL_Window* m_pWindow = nullptr;
        SDL_Renderer* m_pRenderer = nullptr;
        
        bool init(int xpos, int ypos, int width, int height);
        void clean();
    };
}

#endif /* defined(__yobatronika__Game__) */