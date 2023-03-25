#include "Swarm.h"

namespace mhered
{

    Swarm::Swarm()
    {
        m_pt_particles = new Particle[NUM_PARTICLES]; // allocate memory to array of Particles
    }

    Swarm::~Swarm()
    {
        delete[] m_pt_particles;
    }

    void Swarm::update()
    {
        for (int i = 0; i < Swarm::NUM_PARTICLES; i++)
        {
            m_pt_particles[i].update();
        }
    }
}