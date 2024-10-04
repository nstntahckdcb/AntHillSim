**AntHillSim** is a C++ project that simulates the behavior of ants in a colony. Ants move around a grid, engage in fights, and can be extended to gather food, reproduce, or other complex behaviors. This simulation serves as an educational tool for understanding basic object-oriented programming principles, simulation modeling, and the use of linked lists.

## Features

- Simulates ant movement in a grid-based environment.
- Implements a basic fighting system between ants.
- Uses a custom LinkedList class to manage ant objects.
- The grid is dynamically sized and can be expanded.

## Project Structure

- `main.cpp`: Entry point for the simulation.
- `Ant.cpp` / `Ant.h`: Implements the `Ant` class, handling ant behavior such as movement and fighting.
- `AntHill.cpp` / `AntHill.h`: Manages the colony of ants and simulates their interactions.
- `LinkedList.cpp` / `LinkedList.h`: A custom linked list implementation to manage ants in the simulation.

## Setup and Installation

### Prerequisites
To compile and run the project, ensure you have the following installed:

- **g++** (GNU C++ Compiler)
- **Make** (for using the Makefile)

### Installation Steps

1. Clone the repository:
   ```bash
   git clone https://github.com/nstntahckdcb/AntHillSim.git
   cd AntHillSim
