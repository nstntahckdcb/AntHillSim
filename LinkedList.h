// LinkedList.h (Minimalist template for handling ants)
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <typename T>
class LinkedList {
public:
    struct Node {
        T data;
        Node *next;
        Node(T d) : data(d), next(nullptr) {}
    };

    Node *head;

    LinkedList() : head(nullptr) {}
    void insert(T data) {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
};

#endif // LINKEDLIST_H
