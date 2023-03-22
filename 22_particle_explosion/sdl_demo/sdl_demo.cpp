// sdl_demo.cpp

#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

int main()
{

    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "Error initializing SDL: " << SDL_GetError() << endl;
        return 1;
    }
    else
    {
        cout << "SDL initialization succeded." << endl;
    }

    SDL_Window *window = SDL_CreateWindow("Particle Fire Explosion", // creates a window
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SCREEN_WIDTH,
                                          SCREEN_HEIGHT,
                                          SDL_WINDOW_SHOWN);

    if (window == NULL)
    {
        cout << "Error creating window: " << SDL_GetError() << endl;
        SDL_Quit();
        return 2;
    };

    // create a renderer object, synchronized with the refresh rate
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL)
    {
        cout << "Error creating renderer: " << SDL_GetError() << endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 3;
    };

    // create a texture object
    SDL_Texture *texture = SDL_CreateTexture(renderer,
                                             SDL_PIXELFORMAT_RGBA8888, // RGB+Alpha 8 bits each
                                             SDL_TEXTUREACCESS_STATIC, // changes rarely, not lockable
                                             SCREEN_WIDTH,
                                             SCREEN_HEIGHT);
    if (texture == NULL)
    {
        cout << "Error creating texture: " << SDL_GetError() << endl;
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 4;
    };

    // allocate memory for the buffer
    // Uint32 is a 32bits unsigned int type implemented by SDL (to hold 8 bits per each of the 4 channels RGBA)
    Uint32 *buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT]; // we should check but need exception handling

    memset(buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

    for (int i = 0; i < SCREEN_HEIGHT * SCREEN_WIDTH; i++)
    {
        buffer[i] = 0x99e6ffFF; // DeepSkyBlue 80%
    };

    SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WIDTH * sizeof(Uint32));
    SDL_RenderClear(renderer);                     // clear the render
    SDL_RenderCopy(renderer, texture, NULL, NULL); // pass it the buffer
    SDL_RenderPresent(renderer);                   // present it

    bool quit = false;
    SDL_Event event;

    // Main loop
    while (!quit)
    {
        // Update particles
        // Draw particles

        // Check for all waiting events and process them
        while (SDL_PollEvent(&event))
        {
            // Quit
            if (event.type == SDL_QUIT)
            {
                quit = true;
            }
        };
    };

    // delete buffer
    delete[] buffer;

    // destroy texture
    SDL_DestroyTexture(texture);

    // destroy renderer
    SDL_DestroyRenderer(renderer);

    // destroy window
    SDL_DestroyWindow(window);

    // close SDL
    SDL_Quit();

    return 0;
}