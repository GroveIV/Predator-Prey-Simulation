/************************************************************************************************
** Program Filename: doodleBug.hpp
** Author: Edwin Grove
** Date: 2/4/2016
** Description: The hpp file for doodleBug class
** Input: none
** Output: none
*************************************************************************************************/
#ifndef DOODLEBUG_HPP
#define DOODLEBUG_HPP
#include "critter.hpp"


class doodleBug : public critter
{
private:
	char sign;																						//the signifying character when displaying array of bugs
	int numMoves;																					//number of moves for a bug
	int numEatMoves;																				//how many moves have been taken since the bug ate
	int n;																							//variable to hold random numbers
public:
	doodleBug();
	virtual char getSign() const
	{
		return sign;
	}
	virtual void move(critter *currArray[], critter *newArray[], int i, int cols, int totalCell);	//rules for doodlebug movement
	virtual void breed(critter *currArray[], critter *newArray[], int i, int cols, int totalCell);	//rules for doodlebug breeding
	virtual void resetStat();																		//resets private member variables numMoves and numEatMoves
};

#endif // !DOODLEBUG_HPP
