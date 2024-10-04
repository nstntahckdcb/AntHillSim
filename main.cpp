// main.cpp
#include "AntHill.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(0)); // Seed random number generator
    AntHill hill(5); // Create an anthill with 5 ants

    // Run simulation for 10 steps
    for (int i = 0; i < 10; i++) {
        std::cout << "Step " << i + 1 << ":\n";
        hill.simulateStep(); // Each ant moves and may fight
        hill.showAnts(); // Display the current status of ants
        std::cout << "-------------------\n";
    }

    return 0;
}
