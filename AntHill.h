
#ifndef ANTHILL_H
#define ANTHILL_H

#include "Ant.h"
#include "LinkedList.h"
#include <iostream>
#include <fstream>

class AntHill{
	private:
	   int current_ants;
	   int id;
	   int food;
	   int turnNum;
	   int success;
	   int loss;
   	   std::ofstream out;//("anthill.log");

	public:
	   List* ants;
	   AntHill();
	   ~AntHill();
	   void turn();
	   void addFood();
	   void check(Ant* ant);
	   void addAnt();
	   bool removeAnt(Ant* ant);
	   Ant* getAnt(int id_num);
	   void move();
	   bool changeMax(int max);
	   bool attack();
	   void printHillInfo();
	   int getCurrentNumAnts(){return current_ants;};
//	   Ant* fight(Ant* challenger);
};

#endif
