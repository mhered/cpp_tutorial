// sdl_demo.cpp
// particle explosion

#include <iostream>
#include <SDL2/SDL.h>
#include "Screen.h"
#include <math.h>

using namespace std;
using namespace mhered;

int main()
{

    Screen screen;
    screen.init();

    // Main loop
    while (true)
    {
        // Update particles

        // Draw particles

        // 0x99e6ffff DeepSkyBlue 80%
        Uint8 red = 0x99;
        Uint8 green = 0xe6;
        Uint8 blue = 0xff;

        // shifting colors
        int elapsed = SDL_GetTicks();
        red = (1 + cos(0.0003 * elapsed)) * 128;
        green = (1 + sin(0.001 * elapsed)) * 128;
        blue = (1 + sin(0.0013 * elapsed)) * 128;
        //cout << (int)green << endl;

        for (int y = 0; y < Screen::SCREEN_HEIGHT; y++)
        {

            for (int x = 0; x < Screen::SCREEN_WIDTH; x++)
            {
                screen.set_pixel(x, y, red, green, blue);
            }
        };

        // Draw screen
        screen.update();

        // Check for all waiting events and process them
        if (!screen.process_events())
        {
            break;
        }
    };
    
    screen.close();

    return 0;
}