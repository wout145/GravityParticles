#include "Particle.h"

float calculateGravitationalForce(Particle* particle1, Particle* particle2);
Vector2 calculateGravitationalDirection(Particle* particle1, Particle* particle2); 
Vector2 calculateDecomposedGravity(Particle* particle1, Particle* particle2);
Vector2 calculateTotalGravity(Particle* particle, Particle* particles, int particleAmount);
