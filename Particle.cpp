#include <stdlib.h>
#include <math.h>
#include <raylib.h>
#include "Particle.h"

Particle::Particle(Vector2 _position, float _vx, float _vy, float _ax, float _ay, float _mass) {
  position = _position;
  vx = _vx;
  vy = _vy;
  ax = _ax;
  ay = _ay;
  mass = _mass; 
}

Particle::Particle(Vector2 _position, float _vx, float _vy, float _ax, float _ay, float _mass, Color _color) {
  position = _position;
  vx = _vx;
  vy = _vy;
  ax = _ax;
  ay = _ay;
  color = _color;
  mass = _mass;
}

Vector2 Particle::getPosition() {
  return position;
}

float Particle::getVx() {
  return vx;
}

float Particle::getVy() {
  return vy;
}

float Particle::getAx() {
  return ax;
}

float Particle::getAy() {
  return ay;
}

float Particle::getMass() {
  return mass;
}

Color Particle::getColor() {
  return color;
}

void Particle::draw() {
  DrawPixelV(position, color);
}


void Particle::setPosition(Vector2 _position) {
  position = _position;
}

void Particle::setVx(float _vx) {
  vx = _vx;
}

void Particle::setVy(float _vy) {
  vy = _vy;
}

void Particle::setAx(float _ax) {
  ax = _ax;
}

void Particle::setAy(float _ay) {
  ay = _ay;
}

void Particle::setMass(float _mass) {
  mass = _mass;
}

void Particle::setColor(Color _color) {
  color = _color;
}
