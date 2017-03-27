#include "LinkedList.h" 
#include <iostream>
using namespace std;

//default constructor
List::List(){
	int length = 0;
	head = NULL;
	current = NULL;
}

//copy constructor
List::List(const List& otherList){
	if(otherList.head == NULL){
		head = NULL;
		current = NULL;
		int length = 0;
	}else{
		head = new Node(otherList.head->data);
		current = head;
		length++;
		Node* temp = otherList.head;
		while(temp -> next != NULL){
			current -> next = new Node(temp->next->data);
			current = current-> next;
			temp = temp->next;
			length++;
		}
	}

}

//destructor
List::~List(){

	Node* temp = head;
	Node *next = NULL;
	while(temp != NULL){
		next = temp->next;
		delete temp;
		temp = next;
	}

}



void List::insert(Ant* ant){
     if(head == NULL){
	head = new Node(ant);
     }
     else if(head != NULL){

	Node* temp = this -> head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = new Node(ant);
     }
     length++;
}


//get next values
Ant* List::get(){
	if(current == NULL){
		current = head;
	}
	Ant* val = current -> data;
	if(current->next != NULL){
		current = current->next;
	}
	return val;
}

void List::reset(){
	current = NULL;
}

//print
void List::print(){

	for(Node* temp = this-> head; temp != NULL; temp = temp->next){
		cout << temp -> data -> getID() << endl;
	}

}

bool List::remove(Ant *ant)
{
	Node *temp = this->head;
	Node *prev = NULL;

	while (temp)
	{
		if (temp->data->getID() == ant->getID())
		{
			if (prev)
				prev->next = temp->next;
			else
				this->head = temp->next;

			delete temp->data;
			delete temp;
			temp = NULL;
			return true;
		}
		else
		{
			prev = temp;
			temp = temp->next;
		}
	}

	return false;
}


Ant* List::find(int val){
	Node* temp = this->head;
	while(temp){
		if(temp->data->getID() == val){
			return temp->data;
		}else{
			temp = temp->next;
		}
	}
	return NULL;

}

void List::operator << (Ant* other){
	this->insert(other);
}




