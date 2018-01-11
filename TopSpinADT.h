#pragma once
class TopSpinADT {
public:

	virtual void shiftLeft() = 0;// shifts the pieces 1 to the left
	virtual void shiftRight() = 0;//shifts the pieces 1 to the right
	virtual void spin() = 0;//reverse the pieces in the spin mechanism
	virtual bool isSolved() = 0;//check to see if the puzzle is solved that is to say the pieces are in numerical order 1 - last number
}; //End of class TopSpinADT