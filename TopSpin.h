#pragma once
#include "CDLL.h";
#include <iostream>
#include "TopSpinADT.h";
using namespace std;

class TopSpin :public TopSpinADT {
private:
	int _numbers; //size of the game, total numbers
	int _spin_size; //numbers in spinner
	LinkedList<int>_topspin;//create board instance in topspin file
	

public:
	TopSpin::TopSpin(); //default constructor
	TopSpin::TopSpin(int size, int spinSize); //constructor
	void random(unsigned int times);//randomize board
	friend ostream &operator << (ostream& os, const TopSpin& ts);


	void shiftLeft();
	void shiftRight();
	void spin();
	bool isSolved();

}; //end of class TopSpin

ostream& operator<< (ostream& os, const TopSpin& ts);//overloading declaration for "<<" operator
