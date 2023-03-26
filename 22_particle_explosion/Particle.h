#ifndef PARTICLE_H
#define PARTICLE_H

#pragma once

namespace mhered
{

    struct Particle // struct is identical to class except that variables are public by default
    {
        double m_x; // double for smoother calculations
        double m_y;

        double m_direction;
        double m_speed;

    public:
        Particle();
        ~Particle();
        void update();
    };
}
#endif