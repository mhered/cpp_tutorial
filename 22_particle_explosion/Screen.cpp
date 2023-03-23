#include "Screen.h"
#include <SDL2/SDL.h>
#include <iostream>
using namespace std;

namespace mhered
{
    
    Screen::Screen() : m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer(NULL)
    {
    }


    Screen::~Screen()
    {
    }


    bool Screen::init()
    {
        if (SDL_Init(SDL_INIT_VIDEO) < 0)
        {
            cout << "Error initializing SDL: " << SDL_GetError() << endl;
            return false;
        }
        else
        {
            cout << "SDL initialization succeded." << endl;
        }

        m_window = SDL_CreateWindow("Particle Fire Explosion", // creates a window
                                    SDL_WINDOWPOS_UNDEFINED,
                                    SDL_WINDOWPOS_UNDEFINED,
                                    SCREEN_WIDTH,
                                    SCREEN_HEIGHT,
                                    SDL_WINDOW_SHOWN);

        if (m_window == NULL)
        {
            cout << "Error creating window: " << SDL_GetError() << endl;
            SDL_Quit();
            return false;
        };

        // create a renderer object, synchronized with the refresh rate
        m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
        if (m_renderer == NULL)
        {
            cout << "Error creating renderer: " << SDL_GetError() << endl;
            SDL_DestroyWindow(m_window);
            SDL_Quit();
            return false;
        };

        // create a texture object
        m_texture = SDL_CreateTexture(m_renderer,
                                      SDL_PIXELFORMAT_RGBA8888, // RGB+Alpha 8 bits each
                                      SDL_TEXTUREACCESS_STATIC, // changes rarely, not lockable
                                      SCREEN_WIDTH,
                                      SCREEN_HEIGHT);
        if (m_texture == NULL)
        {
            cout << "Error creating texture: " << SDL_GetError() << endl;
            SDL_DestroyRenderer(m_renderer);
            SDL_DestroyWindow(m_window);
            SDL_Quit();
            return false;
        };

        // allocate memory for the buffer
        // Uint32 is a 32bits unsigned int type implemented by SDL (to hold 8 bits per each of the 4 channels RGBA)
        m_buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT]; // we should check but need exception handling

        memset(m_buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

        return true;
    }


    bool Screen::process_events()
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            // Quit
            if (event.type == SDL_QUIT)
            {
                return false;
            }
        };
        return true;
    }


    void Screen::update()
    {
        SDL_UpdateTexture(m_texture, NULL, m_buffer, SCREEN_WIDTH * sizeof(Uint32));
        SDL_RenderClear(m_renderer);                       // clear the render
        SDL_RenderCopy(m_renderer, m_texture, NULL, NULL); // pass it the buffer
        SDL_RenderPresent(m_renderer);                     // present it
    }


    void Screen::set_pixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue)
    {
        Uint32 rgba = 0;
        rgba += red;
        rgba <<= 8;
        rgba += green;
        rgba <<= 8;
        rgba += blue;
        rgba <<= 8;
        rgba += 0xFF;

        m_buffer[y * SCREEN_WIDTH + x] = rgba;
    }


    void Screen::close()
    {
        // delete buffer
        delete[] m_buffer;

        // destroy texture
        SDL_DestroyTexture(m_texture);

        // destroy renderer
        SDL_DestroyRenderer(m_renderer);

        // destroy window
        SDL_DestroyWindow(m_window);

        // close SDL
        SDL_Quit();
    }
}