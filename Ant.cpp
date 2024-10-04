// Ant.cpp
#include "Ant.h"
#include <cstdlib>

Ant::Ant(int id) : id(id), health(100), x(rand() % 10), y(rand() % 10), searchingForFood(true) {}

void Ant::move() {
    // Move randomly on a 2D grid (simple movement simulation)
    x += (rand() % 3) - 1;
    y += (rand() % 3) - 1;
}

void Ant::fight(Ant &other) {
    if (this->isAlive() && other.isAlive()) {
        // Simple fight mechanism: each hit reduces health
        this->health -= 10;
        other.health -= 10;
    }
}

bool Ant::isAlive() {
    return health > 0;
}
