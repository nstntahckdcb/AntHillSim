
#include "AntHill.h" 
#include <stdlib.h> 
#include <fstream> 
#include <iostream>

using namespace std;

//constructor
AntHill::AntHill(){
   out.open("anthill.log");
   current_ants = 0;
   ants = new List();
   food = 0;
   id = 0;
   success = 0;
   loss = 0;
   for(int x = 0; x < 3; x++){
	this->addAnt();
   }
   turnNum = 0;
}


//destructor
AntHill::~AntHill(){
	out.close();
	for(int x = 0; x <= id; x++){
		delete ants->find(x);
	}

	delete ants;
}


void AntHill::turn(){

	//produce all ants
	for(food; food > 0; food--){
		addAnt();
	}
	move();

	if(current_ants > 0){
	//calculate if Hill will be attacked
		int random = rand()%100+1;
		if(random > 0 && random <= 20){
			if(attack()){
				success++;
			}else{
				loss++;
			}
		}
	}

	out << "======== Turn # "<< turnNum << " =========" << endl;
	out << "The hill currently has: " << endl;
	out <<  "\tFood: " << food << endl;
	out <<  "\tAnts: " << current_ants << endl;
	out <<  "The hill has been attacked " << success+loss << " times\n";
	out <<  "\tSuccessfully defended: " << success << endl;
	out <<  "\tFailed to defend: " << loss << endl;

	turnNum++;

}


//attack AntHill
bool AntHill::attack(){

	bool retVal = true;

	int ants_attacking = rand()%current_ants+1;
	int ants_defending = 0;

	int end = current_ants;

	for(int x = 0; x < end; x++){
		Ant* ant = ants->get();
		//check to see if it is within half the grid
		if((ant->getX() < (ant->getMax_X()/2) && ant->getX() > (ant->getMax_X()/-2)) && (ant->getY() < ant->getMax_Y()/2 && ant->getY() > ant->getMax_Y()/-2)){
			ants_defending++;
		}
	}
	ants->reset();

	//remove the ants defending
	if(ants_defending <= ants_attacking){

		food = 0;

		for(int x = 0; x < end; x++){
			Ant* ant = ants->get();

			if((ant->getX() < (ant->getMax_X()/2) && ant->getX() > (ant->getMax_X()/-2)) && (ant->getY() < ant->getMax_Y()/2 && ant->getY() > ant->getMax_Y()/-2)){
 				removeAnt(ant);
			}
		}
		retVal = false;
	}

	ants_defending = 0;
	ants->reset();
	return retVal;
}

//add ants
void AntHill::addAnt(){
      id++;
      ants->insert(new Ant(id));
      current_ants++;
}


//remove Ant
bool AntHill::removeAnt(Ant* ant){
	current_ants--;
	return ants->remove(ant);
}

//get Ants
Ant* AntHill::getAnt(int id_num){
     return ants->find(id_num);
}


//move Ants
void AntHill::move(){
   int end = current_ants;
   for(int i = 0; i < end; i++){
	Ant* ant = ants->get();
	ant->move();
	check(ant);
   }
	ants->reset();
}

void AntHill::check(Ant* ant){
	int random = rand()%100+1;

        if(random > 0 && random <= 20){
		 this->addFood();


        }else if(random > 20 && random <= 40){
		out << "Ant # " << ant->getID() << " has run into a rival ant" << endl;
		Ant *tmp = new Ant(0);
                bool del = ant->fight(tmp);
        	if(del){
			out << "Ant # " << ant->getID() << " loses the fight and dies" << endl;
			this->removeAnt(ant);
		}else{
			out << "Ant # " << ant->getID() << " has won" << endl;
		}

		delete tmp;
	}
}

void AntHill::addFood(){
        food++;
}


//print Hill information
void AntHill::printHillInfo(){
   for(int x = 0; x < current_ants; x++){
	Ant* ant = ants->get();
	cout << "Ant ID " << ant->getID() << " [" << ant->getX();
	cout << "," <<  ant->getY() << "]" << endl;
   }
   ants->reset();
}

