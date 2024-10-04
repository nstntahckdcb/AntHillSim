// AntHill.cpp
#include "AntHill.h"
#include <iostream>

AntHill::AntHill(int numAnts) {
    for (int i = 0; i < numAnts; i++) {
        ants.insert(Ant(i));
    }
}

void AntHill::simulateStep() {
    LinkedList<Ant>::Node *current = ants.head;
    while (current != nullptr) {
        current->data.move(); // Each ant moves
        // Simulate fight randomly between two ants
        if (rand() % 5 == 0 && current->next != nullptr) {
            current->data.fight(current->next->data);
        }
        current = current->next;
    }
}

void AntHill::showAnts() {
    LinkedList<Ant>::Node *current = ants.head;
    while (current != nullptr) {
        Ant &ant = current->data;
        std::cout << "Ant #" << ant.id << " at (" << ant.x << "," << ant.y << ") Health: " << ant.health << "\n";
        current = current->next;
    }
}
