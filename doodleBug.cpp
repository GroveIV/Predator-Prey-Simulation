/********************************************************************************************
** Program Filename: doodleBug.cpp
** Author: Edwin Grove
** Date: 2/4/2016
** Description: This file contains the derived class doodleBug from its parent class critter
				and outlines the rules of the doodlebug in the predator prey game
** Input: none
** Output: none
*********************************************************************************************/

#include "doodleBug.hpp"
#include <iostream>
#include <stdlib.h>
using std::cout;
using std::endl;

/*********************************************************************************************
**Default constructor- doodleBug class
**********************************************************************************************/
doodleBug::doodleBug()
{
	numMoves = 0;
	numEatMoves = 0;
	n = 0;
	sign = 'X';
}
/*********************************************************************************************
** Function: move(critter *currArray[], critter *newArray[], int i, int cols, int totalCell)
** Description: This function allows the doodlebug to move or eat an ant nearby
** Paramters: critter *currArray[], critter *newArray[], int i, int cols, int totalCell
** Pre-conditions: both critter arrays must be of equal size 
** Post-conditions: one 'doodlebug' will be moved according to its surrounding circumstances
**********************************************************************************************/


void doodleBug::move(critter *currArray[], critter *newArray[], int i, int cols, int totalCell)
{
	numMoves++;																						//increment number of moves by one
	numEatMoves++;
	n = rand() % 4;																					//randomly generating four numbers to decide where to move
	if (numMoves % 8 == 0)
	{
		breed(currArray, newArray, i, cols, totalCell);
	}
	else
	{
		if (i - cols >= 0)																			//check if there is an ant to eat above doodlebug
		{
			if (currArray[i - cols] != NULL && currArray[i - cols]->getSign() == 'O')
			{
				numEatMoves = 0;
				newArray[i - cols] = currArray[i];
				newArray[i] = NULL;
				return;
			}
		}
		if (i - (cols + 1) >= 0)																	//check if there is an ant to eat above and to the right of doodlebug
		{
			if (currArray[i - (cols + 1)] != NULL && currArray[i - (cols + 1)]->getSign() == 'O')
			{
				numEatMoves = 0;
				newArray[i - (cols + 1)] = currArray[i];
				newArray[i] = NULL;
				return;
			}
		}
		if (i - (cols - 1) >= 0)																	//check if there is an ant to eat above and to the left of doodlebug
		{
			if (currArray[i - (cols - 1)] != NULL && currArray[i - (cols - 1)]->getSign() == 'O')
			{
				numEatMoves = 0;
				newArray[i - (cols - 1)] = currArray[i];
				newArray[i] = NULL;
				return;
			}
		}
		if (i + cols <= totalCell - 1)																//check if there is an ant to eat below doodlebug
		{
			if (currArray[i + cols] != NULL && currArray[i + cols]->getSign() == 'O')
			{
				numEatMoves = 0;
				newArray[i + cols] = currArray[i];
				newArray[i] = NULL;
				return;
			}
		}
		if (i + (cols - 1) <= totalCell - 1)														//check if there is an ant to eat below and to the left doodlebug
		{
			if (currArray[i + (cols - 1)] != NULL && currArray[i + (cols - 1)]->getSign() == 'O')
			{
				numEatMoves = 0;
				newArray[i + (cols - 1)] = currArray[i];
				newArray[i] = NULL;
				return;
			}
		}
		if (i + (cols + 1) < totalCell)																//check if there is an ant to eat below and to the right doodlebug
		{
			if (currArray[i + (cols + 1)] != NULL && currArray[i + (cols + 1)]->getSign() == 'O')
			{
				numEatMoves = 0;
				newArray[i + (cols + 1)] = currArray[i];
				newArray[i] = NULL;
				return;
			}
		}
		if (i % cols != 0)																			//check if there is an ant to eat to the left of doodlebug
		{
			if (currArray[i - 1] != NULL && currArray[i - 1]->getSign() == 'O')
			{
				numEatMoves = 0;
				newArray[i - 1] = currArray[i];
				newArray[i] = NULL;
				return;
			}
		}
		if (i % cols != cols + 1 && i + 1 < totalCell)
		{
			if (currArray[i + 1] != NULL && currArray[i + 1]->getSign() == 'O')						//check if there is an ant to eat to the right of doodlebug
			{
				numEatMoves = 0;
				newArray[i + 1] = currArray[i];
				newArray[i] = NULL;
				return;
			}
		}
		if (numEatMoves > 3)
		{
			newArray[i] = NULL;
			return;
		}
		if (n == 0)																					//moving left
		{
			if (i % cols == 0)																		//checking bounds of the board
			{
				return;
			}
			else if (currArray[i - 1] == NULL)														//checking if movement is to an empty space
			{
				newArray[i - 1] = currArray[i];
				newArray[i] = NULL;
				return;
			}
			else																					//if trying to move to a non empty space
			{
				return;
			}
		}
		else if (n == 1)																			//moving right
		{
			if (i % cols == cols + 1)																//checking bounds of the board
			{
				return;
			}
			else if (currArray[i + 1] == NULL)														//checking if movement is to an empty space
			{
				newArray[i + 1] = currArray[i];
				newArray[i] = NULL;
				return;
			}
			else																					//if trying to move to a non-empty space
			{
				return;
			}
		}
		else if (n == 2)																			//moving up
		{
			if (i - cols < 0)																		//checking bounds of the board
			{
				return;
			}
			else if (currArray[i - cols] == NULL)													//checking if movement is to an empty space
			{
				newArray[i - cols] = currArray[i];
				newArray[i] = NULL;
				return;
			}
			else																					//if trying to move to a non-empty space 
			{
				return;
			}
		}
		else																						//moving down
		{
			if (i + cols > totalCell - 1)															//checking the bounds of the board
			{
				return;
			}
			else if (currArray[i + cols] == NULL)													//checking if movement is to an empty space
			{
				newArray[i + cols] = currArray[i];
				newArray[i] = NULL;
				return;
			}
			else																					//if space to move is not empty it stays in the same place
			{
				return;
			}
		}
	}
}

/*********************************************************************************************
** Function: breed(critter *currArray[], critter *newArray[], int i, int cols, int totalCell
** Description: This function breeds another doodlebug next to the existing one
** Parameters: critter *currArray[], critter *newArray[], int i, int cols, int totalCell
** Pre-Conditions: both currArray[] and newArray[] must be of the same size
** Post-Conditions: another doodlebug will appear on the map next to an existing one
**********************************************************************************************/


void doodleBug::breed(critter *currArray[], critter *newArray[], int i, int cols, int totalCell)
{
	numMoves = 0;
	n = rand() % 4;																					//randomly generating four numbers to decide where to move
	if (n == 0)																						//moving left
	{
		if (i % cols == 0)																			//checking bounds of the board
		{
			return;
		}
		else if (currArray[i - 1] == NULL)															//checking if new doodleBug is to an empty space
		{
			newArray[i - 1] = new doodleBug;
		}
		else																						//if trying to move to a non empty space
		{
			return;
		}
	}
	else if (n == 1)																				//moving right
	{
		if (i % cols == cols + 1)																	//checking bounds of the board
		{
			return;
		}
		else if (currArray[i + 1] == NULL)															//checking if new doodlebug is to an empty space
		{
			newArray[i + 1] = new doodleBug;
		}
		else																						//if trying to move to a non-empty space
		{
			return;
		}
	}
	else if (n == 2)																				//moving up
	{
		if (i - cols < 0)																			//checking bounds of the board
		{
			return;
		}
		else if (currArray[i - cols] == NULL)														//checking if new doodlebug is to an empty space
		{
			newArray[i - cols] = new doodleBug;
		}
		else																						//if trying to move to a non-empty space 
		{
			return;
		}
	}
	else																							//moving down
	{
		if (i + cols > totalCell - 1)																//checking the bounds of the board
		{
			return;
		}
		else if (currArray[i + cols] == NULL)														//checking if new doodlebug is to an empty space
		{
			newArray[i + cols] = new doodleBug;
		}
		else																						//if space to move is not empty it stays in the same place
		{
			return;
		}
	}
}
/***********************************************************************************************
** Function: resetStat()	
** Description: resets the private member variables of doodlebug for when a new bug is spawned
** Parameters: none
** Pre-conditions: none
** Post-conditions: private member variables numMoves and numEatMoves are set to zero
************************************************************************************************/


void doodleBug::resetStat()
{
	numMoves = 0;
	numEatMoves = 0;
}
