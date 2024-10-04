// Ant.h
#ifndef ANT_H
#define ANT_H

class Ant {
public:
    int id;
    int health;
    int x, y; // Position of the ant
    bool searchingForFood;

    Ant(int id);
    void move(); // Move randomly on the grid
    void fight(Ant &other); // Fight another ant
    bool isAlive(); // Check if the ant is still alive
};

#endif // ANT_H
