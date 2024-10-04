#include "LinkedList.h"
#include <iostream>

// Constructor
LinkedList::LinkedList() : head(nullptr) {}

// Copy constructor
LinkedList::LinkedList(const LinkedList& otherList) {
    head = nullptr;
    Node* current = otherList.head;
    while (current != nullptr) {
        insert(new Ant(*current->data));  // Make a deep copy of each ant
        current = current->next;
    }
}

// Destructor
LinkedList::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current->data;  // Free each Ant
        delete current;
        current = next;
    }
}

// Insert an ant at the head of the list
void LinkedList::insert(Ant* ant) {
    Node* newNode = new Node(ant);
    newNode->next = head;
    head = newNode;
}

// Get the first ant in the list
Ant* LinkedList::get() {
    if (head != nullptr) {
        return head->data;
    }
    return nullptr;
}

// Reset the head of the list (if needed)
void LinkedList::reset() {
    head = nullptr;
}

// Print the list of ants
void LinkedList::print() {
    for (Node* temp = head; temp != nullptr; temp = temp->next) {
        std::cout << "Ant ID: " << temp->data->id << " at (" << temp->data->x << "," << temp->data->y << ")\n";
    }
}

// Remove an ant by pointer (returns true if successful)
bool LinkedList::remove(Ant* ant) {
    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr) {
        if (current->data == ant) {
            if (prev == nullptr) {
                head = current->next;  // Remove the head
            } else {
                prev->next = current->next;  // Remove from the middle or end
            }
            delete current->data;
            delete current;
            return true;
        }
        prev = current;
        current = current->next;
    }
    return false;
}

// Find an ant by ID
Ant* LinkedList::find(int id) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data->id == id) {
            return current->data;
        }
        current = current->next;
    }
    return nullptr;
}



