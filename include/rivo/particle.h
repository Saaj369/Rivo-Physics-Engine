
#ifndef RIVO_PARTICLE_H
#define RIVO_PARTICLE_H

#include <rivo/core.h>

namespace rivo
{
    /** A particle is the simplest object which contains properties like 
     * position, velocity, acceleration but no orientation.*/

    class Particle
    {
        protected:
            /**
                * Holds linear position of the particle in world.
                */
           Vector3 position;

            /**
                * Holds linear velocity of the particle in world.
                */
           Vector3 velocity;

           /**
                * Holds linear acceleration of the particle in world.
                */
           Vector3 acceleration;

           /**
                * Holds the accumulated force to be applied at the next
                * simulation iteration only. This value is zeroed at each
                * integration step.
                */
           Vector3 forceAccum;

           /**
            * Holds the amount of damping applied to linear motion.
            * Dmaping is required to remove the energy added through
            * numerical instability in the integrator.
            */
           real damping;

            /**
             * Holds the inverse of the mass of the particle.
            */
           real inverseMass;
        
        public:
            /** Sets the mass of the particle. */
            void setMass(const real mass);

            real getMass() const;

            void setInverseMass(const real inverseMass);

            real getInverseMass() const;

            bool hasFiniteMass() const;

            void setDamping(const real damping);

            real getDamping() const;

            void setPosition(const Vector3& position);

            void setPosition(const real x, const real y, const real z);

            void getPosition(Vector3 *position) const;

            Vector3 getPosition() const;

            void setVelocity(const Vector3& velocity);

            void setVelocity(const real x, const real y, const real z);

            void getVelocity(Vector3 *position) const;

            Vector3 getVelocity() const;

            void setAcceleration(const Vector3& acceleration);

            void setAcceleration(const real x, const real y, const real z);

            void getAcceleration(Vector3 *position) const;

            Vector3 getAcceleration() const;

            void integrate(real duration);

            void clearAccumulator();

            void addForce(const Vector3& force);
    };
}


#endif