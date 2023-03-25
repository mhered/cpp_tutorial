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
using namespace std;
using namespace mhered;

int main()
{

    srand(time(NULL)); // seed random number generator

    Screen screen;
    screen.init();

    Swarm swarm;
    // 0x99e6ffff DeepSkyBlue 80%
    Uint8 red = 0x99;
    Uint8 green = 0xe6;
    Uint8 blue = 0xff;

    const Particle *const pt_particles = swarm.get_particles();

    // Main loop
    while (true)
    {
        // Update particles
        swarm.update();
        screen.clear();
        // Draw particles

        // shifting colors
        int elapsed = SDL_GetTicks();
        red = (1 + cos(0.001 * elapsed)) * 128;
        green = (1 + sin(0.001 * elapsed)) * 128;
        blue = (1 + sin(0.001 * elapsed)) * 128;

        for (int i = 0; i < Swarm::NUM_PARTICLES; i++)
        {
            int x = (pt_particles[i].m_x + 1) * Screen::SCREEN_WIDTH / 2;
            int y = (pt_particles[i].m_y + 1) * Screen::SCREEN_HEIGHT / 2;

            screen.set_pixel(x, y, red, green, blue);
        }

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