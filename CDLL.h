#pragma once
#include <iostream>

template <class Item>
class LinkedList {

private:
	class Node {
	public:
		Item value;
		Node * next;
		Node * previous;
		Node(Item val, Node * nx = NULL, Node * pr = NULL) {//Node Constructor
			value = val;
			next = nx;
			previous = pr;
		}
	};//End of Node class

public:
	
	LinkedList(); //construct an empty linked list
	~LinkedList(); //destroy a linked list
	void addData(Item d); //add a new node to the end of the linked list with value d
	void incrementHead(); //advance head to next node
	void decrementHead(); //move head to previous node
	void swap(unsigned int src, unsigned int dst); //swap the data in the 2 nodes (easier than swapping the nodes themselves)
	Item getData(unsigned int i) const; //will return the data associated in the i-th node of the list		

	Node * m_head;
	Node * m_tail;
	unsigned int m_size;
};//end of LinkedList Class

//Function Definitions
template <class Item>
LinkedList<Item> ::LinkedList() {//Create Empty linked list
	m_head= NULL;
	m_tail= NULL;
	m_size=0;
}

template <class Item>
LinkedList<Item> ::~LinkedList() {
	Node * nextNode=m_tail; 

	while (nextNode != m_tail) {
		delete nextNode->next;
		nextNode = nextNode->previous;
	}
	delete m_tail;
}

template <class Item>
void LinkedList<Item> ::addData(Item d) {
	Node *  _new=new Node(d);

	if (m_size == 0) { //case: empty list
		_new->next = (_new);
		_new->previous = (_new);
		m_head = (_new);
	}

	else{ //case: non-empty list
		_new->previous = m_tail;
		(*m_tail).next = (_new);
		(*m_head).previous = (_new);
		_new->next = m_head;
	}

	m_tail = (_new); 
	m_size++;//incremenent the size to indicate a node has been added

}

template <class Item>
void LinkedList<Item> ::incrementHead() {
	m_head = m_head->next; 
}

template <class Item>
void LinkedList<Item> ::decrementHead() {
	m_head = m_head->previous;
}

template <class Item>
void LinkedList<Item> ::swap(unsigned int src, unsigned int dst) {
	Node * here = m_head;
	Node *here2 = m_head;

	for (unsigned int j = 1; j < dst; j++) {
		here2 = here2->next;
	}

	Item temp1 = here2->value;

	for (unsigned int k = 1; k < src; k++)
	{
		here = (*here).next; 
	}
	Item temp2 = here->value;
	
	here2->value=temp2;
	here->value=temp1;
}

template <class Item>
Item LinkedList<Item> ::getData(unsigned int i)const {
	Node *temp = m_head;
	for (unsigned int k = 1; k <= i; k++) 
	{
		temp = temp->next;
	}
	
	return temp->value;//return value of desired item
};