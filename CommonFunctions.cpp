#include <math.h>
#include "Particle.h"
#include <stdio.h>

double calculateGravitationalForce(Particle* particle1, Particle* particle2) {

  float gravityMultiplier = 0.1;
  double G = gravityMultiplier * 6.67408; 
  double dx = particle1->getPosition().x - particle2->getPosition().x;
  double dy = particle1->getPosition().y - particle2->getPosition().y;


  double r = sqrt(pow(dx, 2) + pow(dy, 2));


  if (r == 0.0) {
    return 0.0;
  }

  double m1 = particle1->getMass();
  double m2 = particle2->getMass();
  return G * ((m1 * m2) / r);
}

Vector2 calculateGravitationalDirection(Particle* particle1, Particle* particle2) {
  return {particle2->getPosition().x - particle1->getPosition().x, particle2->getPosition().y - particle1->getPosition().y};
}

Vector2 calculateDecomposedGravity(Particle* particle1, Particle* particle2) {
  float force = calculateGravitationalForce(particle1, particle2);  
  Vector2 direction = calculateGravitationalDirection(particle1, particle2);

  if (fabs(direction.x) + fabs(direction.y) == 0.0) {
    return {0.0f, 0.0f};
  }
  float forceX = (direction.x / (fabs(direction.x) + fabs(direction.y))) * force;
  float forceY = (direction.y / (fabs(direction.x) + fabs(direction.y))) * force;
  return {forceX, forceY};
}


Vector2 calculateTotalGravity(Particle* particle, Particle* particles, int particleAmount) {
  float totalX = 0;
  float totalY = 0;
  for (int i = 0; i < particleAmount; i++) {
    totalX = totalX + calculateDecomposedGravity(particle, &particles[i]).x;
    totalY = totalY + calculateDecomposedGravity(particle, &particles[i]).y;
  }
  return {totalX, totalY};
}
