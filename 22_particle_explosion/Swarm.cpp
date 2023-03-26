#include "Swarm.h"

namespace mhered
{

    Swarm::Swarm() : last_timestamp(0)
    {
        m_pt_particles = new Particle[NUM_PARTICLES]; // allocate memory to array of Particles
    }

    Swarm::~Swarm()
    {
        delete[] m_pt_particles;
    }

    void Swarm::update(int timestamp)
    {
        int delta_t = timestamp - last_timestamp;

        for (int i = 0; i < Swarm::NUM_PARTICLES; i++)
        {
            m_pt_particles[i].update(delta_t);
            last_timestamp = timestamp;
        }
    }
}