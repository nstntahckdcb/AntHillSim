#ifndef ANTHILL_H
#define ANTHILL_H

#include "LinkedList.h"
#include "Ant.h"

class AntHill {
private:
    LinkedList ants;  // Remove template usage

public:
    AntHill(int numAnts);
    void simulateStep(); // Simulate one step of the simulation
    void showAnts(); // Display ants' status
};

#endif // ANTHILL_H
