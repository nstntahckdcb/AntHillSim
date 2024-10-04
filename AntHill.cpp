#include "AntHill.h"
#include <iostream>

AntHill::AntHill(int numAnts) {
    for (int i = 0; i < numAnts; i++) {
        ants.insert(new Ant(i));  // Pass a pointer to a new Ant
    }
}

void AntHill::simulateStep() {
    LinkedList::Node *current = ants.head;  // Remove template syntax
    while (current != nullptr) {
        current->data->move();  // Each ant moves
        // Simulate fight randomly between two ants
        if (rand() % 5 == 0 && current->next != nullptr) {
            current->data->fight(*(current->next->data));
        }
        current = current->next;
    }
}

void AntHill::showAnts() {
    LinkedList::Node *current = ants.head;  // Remove template syntax
    while (current != nullptr) {
        Ant *ant = current->data;
        std::cout << "Ant #" << ant->id << " at (" << ant->x << "," << ant->y << ") Health: " << ant->health << "\n";
        current = current->next;
    }
}
