#include "TopSpin.h";
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

TopSpin::TopSpin() { //default: 20 numbers, spinner = 4
	_numbers = 20;
	_spin_size = 4;
	for (int i(0); i < _numbers; i++) { //crete the board
		_topspin.addData(i + 1); 
	}
}

TopSpin::TopSpin(int size, int spinSize) { 
	if ((size >= 1) && (spinSize <= size)) {
		_numbers = size;
		_spin_size = spinSize;
	}

	else { 
		_numbers = 20;
		_spin_size = 4;
	}

	for (int i(0); i < _numbers; i++) {
		_topspin.addData(i + 1);
	}
}

void TopSpin::random(unsigned int times) {//randomize the board
	srand(time(NULL));
	for (int i = 0; i < times; i++) {
		int spins = (rand()%_numbers)+1;
		for (int j = 0; j < spins; j++) {
			shiftLeft();
		}
		spin();
	}
		cout << "The numbers have been randomized." << endl;//let user know the numbers have been randomized
	
}

void TopSpin::shiftLeft() {
	_topspin.incrementHead();
}

void TopSpin::shiftRight() {
	_topspin.decrementHead();
}

void TopSpin::spin() {
	for (int i = 1; i <= _spin_size; i++) {
		_topspin.swap(i, _spin_size - i);
	}
}
bool TopSpin::isSolved() {
	for (int i = 1; i<= _numbers; i++) {
		if(!(_topspin.getData(i-1)==i)){
				return 0;//return 0 if not solved
		}
	}
	return 1;//return 1 if solved
}
ostream &operator<< (ostream& os, const TopSpin& ts) {//printing the board
	os << endl<<"|";//print indicator top (format)

	for (int i(0); i < ts._spin_size; i++) {
		os << "-----";
	}

	os<< "|"<<endl;

	for (int i = 0; i < ts._numbers; i++) {//print numbers
		if (((ts._numbers) - i) == 1){//check if number printed is the last number
			os << "  ";
			os <<left<< setw(2) << ts._topspin.getData(i) ;
			}
		else {
			os << "  ";
			os << left<<setw(2) << ts._topspin.getData(i) << "," ;
		}

	}

	os << endl<<"|";//print indicator bottom
	for (int i(0); i < ts._spin_size; i++) {
		os << "-----";
	}
	os << "|" << endl<<endl;
	return os;
}
