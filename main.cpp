#include "TopSpin.h";
#include <iostream>
#include <iomanip>

int main() {

	cout << "WELCOME TO TOPSPIN"<<endl;
	cout << "By: Tosho Toshev" << endl <<  "-----------------------------------------" << endl;
	int moves;

	cout << "Please enter a number to randomize the spinner (integer value only): ";
	cin >> moves; cout << endl;

	TopSpin _board(20,4);
	cout << "Game of size " << "20" << " has been created with a spinner of size " << "4" <<"."<< endl;
	cout << "-----------------------------------------" << endl<<endl;
	cout << _board;
	_board.random(moves);
	
	int end = 0;
	int attempts = 0;

	while (true) {
		cout << _board;
		cout << endl << "Attempts: " <<attempts<< endl;
		if (_board.isSolved()) {//check if puzzle has been solved
			cout <<endl<< "************Congratulations! You won!**************" << endl;
			cout <<"Solved: " <<endl<< _board;
			cout << endl << "Attempts used: " << attempts << endl;
			break;
			
		}
		
		
		int choice = 0;
		cout << "(1) - Spin      (2) - Shift Left      (3) - Shift Right" << endl;
		cout << "Input: "; cin >> choice;
		while ((choice > 3) || (choice < 1)) {
			cout << endl << "Invalid input. Try again." << endl;
			cout << "(1) - Spin      (2) - Shift Left      (3) - Shift Right" << endl;
			cout << "Input: "; cin >> choice;
		}
		if (choice == 1) {
			_board.spin();
			attempts++;
		}
		if (choice == 2) {
			_board.shiftLeft();
			attempts++;
		}
		if (choice == 3) {
			_board.shiftRight();
			attempts++;
		}
	}
}
