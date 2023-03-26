#include "Particle.h"
#include "Screen.h"
#include <stdlib.h>
#include <iostream>
#include <math.h>

using namespace std;

namespace mhered

{
    Particle::Particle()
    {
        init();
    }

    Particle::~Particle()
    {
    }

    void Particle::init()
    {
        m_x = 0;
        m_y = 0;
        m_direction = (2.0 * M_PI * rand()) / RAND_MAX;
        m_speed = (0.2 * rand()) / RAND_MAX;
        m_speed *= m_speed;
    }
    void Particle::update(int delta_t)
    {

        m_direction += delta_t * 0.0004;
        m_x += m_speed * cos(m_direction) * delta_t;
        m_y += m_speed * sin(m_direction) * delta_t;

        // bounce off the edges
        /*
        if (m_x <= -1.0 || m_x >= 1.0)
        {
            m_direction = M_PI - m_direction;
        };

        if (m_y <= -((double)Screen::SCREEN_HEIGHT / Screen::SCREEN_WIDTH) || m_y >= ((double)Screen::SCREEN_HEIGHT / Screen::SCREEN_WIDTH))
        {
            m_direction = -m_direction;
        };
        */
        // init when reaching edges
        if (m_x <= -1.0 ||
            m_x >= 1.0 ||
            m_y <= -((double)Screen::SCREEN_HEIGHT / Screen::SCREEN_WIDTH) ||
            m_y >= ((double)Screen::SCREEN_HEIGHT / Screen::SCREEN_WIDTH))
        {
            init();
        };

        // init randonly 1% of particles
        if (rand() < RAND_MAX / 100)
        {
            init();
        };
    }
}