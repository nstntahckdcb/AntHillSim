#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Ant.h"

class LinkedList {
public:
    struct Node {
        Ant* data;
        Node* next;
        Node(Ant* d) : data(d), next(nullptr) {}
    };

    Node* head;

    LinkedList();  // Constructor
    LinkedList(const LinkedList& otherList);  // Copy Constructor
    ~LinkedList();  // Destructor

    void insert(Ant* ant);  // Insert an ant into the list
    Ant* get();  // Get the first ant in the list
    void reset();  // Reset the current pointer
    void print();  // Print the list of ants
    bool remove(Ant* ant);  // Remove an ant from the list
    Ant* find(int id);  // Find an ant by ID
};

#endif // LINKEDLIST_H
