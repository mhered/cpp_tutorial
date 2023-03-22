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

    // destroy window
    SDL_DestroyWindow(window);

    // close SDL
    SDL_Quit();

    return 0;
}