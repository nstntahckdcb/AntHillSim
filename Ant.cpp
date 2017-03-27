
#include "Ant.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

//static int id = 0;
//constructor definition with unique id
Ant::Ant(int id){
   x = 0;
   y = 0;
   this-> id_number = id;
   experience = rand() % 10 + 1;
   MAX_X = 5;
   MAX_Y = 5;
}

Ant::Ant(const Ant& other){
	this->x = other.x;
	this->y = other.y;
	this->id_number = other.id_number;
	this->experience = other.experience;
	this->MAX_X = other.MAX_X;
	this->MAX_Y = other.MAX_Y;

}

//moving ant in a random direction
void Ant::move(){
  switch(rand() % 4 + 1){
     case 1:
	x += 1;
	break;
     case 2:
	x -= 1;
	break;
     case 3:
	y += 1;
	break;
     case 4:
	y -= 1;
	break;
     default:
	break;
  }

  if(x > MAX_X){
  	x--;
  }else if(x < -MAX_X){
	x++;
  }
  if(y > MAX_Y){
  	y--;
  }else if(y < -MAX_Y){
	y++;
  }

}


//Fight Ants
bool Ant::fight(Ant* challenger){

   int round = 0;
   int points_ant=0;
   int points_challenger = 0;

   while(round < 3){

        points_ant += rand()%25;

        points_challenger += rand()%25;

	round++;
   }

   points_ant += this-> getExperience();
   points_challenger += challenger -> getExperience();

   if(points_ant > points_challenger){
        if((this -> getExperience()) + (challenger -> getExperience()) <= 20){
                this -> setExperience(this -> getExperience() + challenger -> getExperience());
        }else{
                this -> setExperience(20);
	}
	return false;

   }else if(points_ant < points_challenger){

        if((this -> getExperience()) + (challenger -> getExperience()) <= 20){
                challenger -> setExperience(this -> getExperience() + challenger -> getExperience());
        }else{
                challenger -> setExperience(20);
	}
	return true;
   }else{
   	return false;
   }

}

