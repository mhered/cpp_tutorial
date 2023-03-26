// sdl_demo.cpp
// particle explosion

#include <iostream>
#include <SDL2/SDL.h>
#include "Screen.h"
#include "Particle.h"
#include "Swarm.h"

#include <math.h>
#include <stdlib.h>
#include <time.h>

#include <unistd.h>

using namespace std;
using namespace mhered;

int main()
{

    srand(time(NULL)); // seed random number generator

    Screen screen;
    screen.init();

    usleep(8000000); // pause 8 secs (for easy video capture)

    Swarm swarm;
    // 0x99e6ffff DeepSkyBlue 80%
    Uint8 red = 0x99;
    Uint8 green = 0xe6;
    Uint8 blue = 0xff;

    const Particle *const pt_particles = swarm.get_particles();

    // Main loop
    while (true)
    {
        int timestamp = SDL_GetTicks();

        // Update particles
        swarm.update(timestamp);
        // screen.clear();
        // Draw particles

        // shifting colors
        red = (1 + cos(0.0012 * timestamp)) * 128;
        green = (1 + sin(0.0007 * timestamp)) * 128;
        blue = (1 + sin(0.001 * timestamp)) * 128;

        for (int i = 0; i < Swarm::NUM_PARTICLES; i++)
        {
            int x = (pt_particles[i].m_x + 1) * Screen::SCREEN_WIDTH / 2;
            int y = Screen::SCREEN_HEIGHT / 2 + pt_particles[i].m_y * Screen::SCREEN_WIDTH / 2;

            screen.set_pixel(x, y, red, green, blue);
        }

        // Blur effect
        screen.box_blur();

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