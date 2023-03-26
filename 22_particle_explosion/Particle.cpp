#include "Particle.h"
#include "Screen.h"
#include <stdlib.h>
#include <iostream>
#include <math.h>

using namespace std;

namespace mhered

{
    Particle::Particle() : m_x(0), m_y(0)
    {
        m_direction = (2.0 * M_PI * rand()) / RAND_MAX;
        m_speed = (0.0001 * rand()) / RAND_MAX;
    }

    Particle::~Particle()
    {
    }

    void Particle::update(int delta_t)
    {

        m_x += m_speed * cos(m_direction) * delta_t;
        m_y += m_speed * sin(m_direction) * delta_t;

        // bounce off the edges

        if (m_x <= -1.0 || m_x >= 1.0)
        {
            m_direction = M_PI - m_direction;
        };

        if (m_y <= -((double)Screen::SCREEN_HEIGHT / Screen::SCREEN_WIDTH) || m_y >= ((double)Screen::SCREEN_HEIGHT / Screen::SCREEN_WIDTH))
        {
            m_direction = -m_direction;
        };
    }
}