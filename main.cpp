#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "Particle.h"
#include "CommonFunctions.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600


void updateParticles(Particle* particles, int particlesAmount) {
  for (int i = 0; i < particlesAmount; i++) {
    Particle* particle = &particles[i];
    float mass = particle->getMass();
    float ax = calculateTotalGravity(particle, particles, particlesAmount).x / mass;
    float ay = calculateTotalGravity(particle, particles, particlesAmount).y / mass;
    particle->setAx(ax);
    particle->setAy(ay);

    float vx = particle->getVx() + particle->getAx();
    particle->setVx(vx);
    float vy = particle->getVy() + particle->getAy();
    particle->setVy(vy);

    float posx = particle->getPosition().x + particle->getVx();
    float posy = particle->getPosition().y + particle->getVy();
    particle->setPosition({posx, posy});

  }
}

int main() {

  int counter = 0;

  SetRandomSeed(1);

  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Testing Raylib in Cpp");

  const int particleCount = 100;

  Particle *particles = (Particle*)malloc(particleCount * sizeof(Particle));


  float x = 1;
  float y = 2;

  for (int i = 0; i < particleCount; i++) {
    Vector2 position = {0, 0};
    position.x = (float)(rand()%SCREEN_WIDTH);
    position.y = (float)(rand()%SCREEN_HEIGHT);

    float vx = 0;

    float vy = 0;

    float ax = 0;

    float ay = 0;

    float mass = 1;

    Color color = WHITE;

    particles[i] = Particle(position, vx, vy, ax, ay, mass, color);
  }

  SetTargetFPS(60);

  bool windowShouldClose = false;

  while (!windowShouldClose) {
    
    if (IsKeyDown(KEY_ESCAPE)) {
      windowShouldClose = true;
    };

    updateParticles(particles, particleCount);
    counter += 1;

    BeginDrawing();

    ClearBackground(BLACK);

    for (int i = 0; i < particleCount; i++) {
      particles[i].draw();
    }

    DrawFPS(100, 100);

    EndDrawing();

  }

  CloseWindow();

  printf("%d\n", counter);
  MemFree(particles); 

  return 0;
}


