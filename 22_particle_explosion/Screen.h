#ifndef SCREEN_H
#define SCREEN_H

#include <SDL2/SDL.h>

namespace mhered
{

    class Screen
    {
    public:
        const static int SCREEN_WIDTH = 640;
        const static int SCREEN_HEIGHT = 480;

    private:
        SDL_Window *m_window;
        SDL_Renderer *m_renderer;
        SDL_Texture *m_texture;
        Uint32 *m_buffer1;
        Uint32 *m_buffer2;
    public:
        Screen();
        ~Screen();

        bool init();
        void update();
        void box_blur();
        void set_pixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
        bool process_events();
        void close();
    };

}

#endif