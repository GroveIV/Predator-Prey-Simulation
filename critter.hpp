/****************************************************************************************************
** Program Filename: critter.hpp
** Author: Edwin Grove
** Date: 2/4/2016
** Description: header file for critter class
** Input: none
** Output: none
*****************************************************************************************************/

#ifndef CRITTER_HPP
#define CRITTER_HPP	

class critter
{
public:
	critter() {};
	virtual char getSign() const = 0;
	virtual void move(critter *currArray[], critter *newArray[], int i, int cols, int totalCell) = 0;
	virtual void breed(critter *currArray[], critter *newArray[], int i, int cols, int totalCell) = 0;
	virtual void resetStat() = 0;
};



#endif // !CRITTER_HPP
