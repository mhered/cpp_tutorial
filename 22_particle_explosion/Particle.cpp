#include "Particle.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

namespace mhered

{
    Particle::Particle()
    {
        m_x = (2.0 * rand() / RAND_MAX) - 1; // random double in [-1, 1]
        m_y = (2.0 * rand() / RAND_MAX) - 1; // random double in [-1, 1]
        // cout << "x: " << m_x << " y: " << m_y << endl;
        m_x_speed = (0.005 * ((2.0 * rand()) / RAND_MAX - 1));
        m_y_speed = (0.005 * ((2.0 * rand()) / RAND_MAX - 1));
    }

    Particle::~Particle()
    {
    }

    void Particle::update()
    {

        m_x += m_x_speed;
        m_y += m_y_speed;

        // bounce off the edges

        if (m_x <= -1.0 || m_x >= 1.0)
        {
            m_x_speed = -m_x_speed;
        };

        if (m_y <= -1.0 || m_y >= 1.0)
        {
            m_y_speed = -m_y_speed;
        };
    }
}