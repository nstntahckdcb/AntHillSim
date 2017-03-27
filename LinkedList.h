#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <cstddef>
#include "Ant.h"

class Node{
    public:
      Node* next;
      Ant* data;
      Node(Ant* ant){
	  this -> data = ant;
          this -> next = NULL;
      }
};

class List{

  private:
	Node* head;
	Node* current;

  public:
	List();
	List(const List&);
	~List();
	int length;
	void insert(Ant* ant);
	void print();
	Ant* get();
	void reset();
	bool remove(Ant* ant);
	Ant* find(int val);
	void operator << (Ant* other);
};

#endif
