/***********************************************************************************
** Program Filename: ant.hpp
** Author: Edwin Grove
** Date: 2/4/2016
** Description: The header file for ant class
** Input: none
** Output: none
************************************************************************************/

#ifndef ANT_HPP
#define ANT_HPP

#include "critter.hpp"
class ant: public critter
{
private:
	int numMoves;
	int n;
	char sign;
public:
	ant();
	virtual char getSign() const
	{
		return sign;
	}
	virtual void move(critter *currArray[], critter *newArray[], int i, int cols, int totalCell);
	virtual void breed(critter *currArray[], critter *newArray[], int i, int cols, int totalCell);
	virtual void resetStat();

};

#endif // !ANT_HPP
