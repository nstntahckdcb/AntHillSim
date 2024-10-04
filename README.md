# AntHill Simulation

## Overview

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
   ```

2. Compile the project using `make`:
   ```bash
   make
   ```

3. Run the simulation:
   ```bash
   ./AntHillSim
   ```

4. (Optional) To clean up the object files and executable:
   ```bash
   make clean
   ```

## Usage

Once you run the simulation, ants will be created and placed on a grid with random positions. Each step of the simulation updates their positions and simulates fights between ants. You can modify the simulation parameters (like the number of ants, grid size, etc.) in the source code.

Example output:
```
Step 1:
Ant #4 at (6,7) Health: 100
Ant #3 at (9,6) Health: 100
Ant #2 at (4,3) Health: 100
Ant #1 at (5,0) Health: 100
Ant #0 at (3,6) Health: 100
-------------------
Step 2:
Ant #4 at (7,6) Health: 90
Ant #3 at (8,5) Health: 80
...
```

## Contributing

Contributions to improve the simulation or add new features are welcome. Fork the repository and submit a pull request with a description of your changes.

### Planned Features:
- **Food Gathering**: Ants can find food and return it to the colony.
- **Reproduction**: Ants can reproduce under certain conditions.
- **Death Mechanics**: Ants die when their health reaches 0 and can be removed from the simulation.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Contact

For questions, feel free to reach out via the [issues page](https://github.com/nstntahckdcb/AntHillSim/issues).
