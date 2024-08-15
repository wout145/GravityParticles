#pragma once
#include <stdlib.h>
#include <math.h>
#include <raylib.h>

class Particle {
  private:
    Vector2 position;
    float vx;
    float vy;
    float ax;
    float ay;
    float mass;
    Color color;

  public:
    Particle(Vector2 position, float vx, float vy, float ax, float ay, float mass);
    Particle(Vector2 position, float vx, float vy, float ax, float ay, float mass, Color color);

    Vector2 getPosition();
    float getVx();
    float getVy();
    float getAx();
    float getAy();
    float getMass();
    Color getColor();
    void setPosition(Vector2 position);
    void setVx(float vx);
    void setVy(float vy);
    void setAx(float ax);
    void setAy(float ay);
    void setMass(float mass);
    void setColor(Color color);
    void draw();
};

