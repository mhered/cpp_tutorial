#ifndef SWARM_H
#define SWARM_H

#include "Particle.h"

#pragma once

namespace mhered
{

    class Swarm
    {
    public:
        const static int NUM_PARTICLES = 5000;

    public:
        Swarm();
        ~Swarm();
        const Particle *const get_particles() { return m_pt_particles; };
        void update(int timestamp);

    private:
        Particle *m_pt_particles; // a pointer to particles
        int last_timestamp;
    };

}

#endif