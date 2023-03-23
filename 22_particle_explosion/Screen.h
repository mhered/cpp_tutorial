#ifndef SCREEN_H
#define SCREEN_H

#include <SDL2/SDL.h>

namespace mhered
{

    class Screen
    {
    public:
        const static int SCREEN_WIDTH = 800;
        const static int SCREEN_HEIGHT = 600;

    private:
        SDL_Window *m_window;
        SDL_Renderer *m_renderer;
        SDL_Texture *m_texture;
        Uint32 *m_buffer;

    public:
        Screen();
        ~Screen();

        bool init();
        void update();
        void set_pixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
        bool process_events();
        void close();
    };

}

#endif