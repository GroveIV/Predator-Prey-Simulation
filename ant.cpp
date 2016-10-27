/******************************************************************************************
** Program Filename: ant.cpp
** Author: Edwin Grove
** Date: 2/4/2016
** Description: This dictates the actions of the ant class; a derived class from the critter class
** Input: none
** Output: none
*******************************************************************************************/
#include "ant.hpp"
#include <iostream>
#include <stdlib.h>
using std::cout;


/*******************************************************************************************
** Default constructor - ant class
********************************************************************************************/
ant::ant()
{
	numMoves = 0;
	n = 0;
	sign = 'O';
}

/*******************************************************************************************
** Function: move(critter *currArray[], critter *newArray[], int i, int cols, int totalCell)
** Description: dictates how ant moves in the game
** Paramters: critter *currArray[], critter *newArray[], int i, int cols, int totalCell
** Pre-conditions: currArray and newArray must be the same size
** Post-conditions: 'ant' will be in a different place in newArray
********************************************************************************************/


void ant::move(critter *currArray[], critter *newArray[], int i, int cols, int totalCell)
{
	numMoves++;
	n = rand() % 4;													//randomly generating four numbers to decide where to move
	if (numMoves % 3 == 0)
	{
		breed(currArray, newArray, i, cols, totalCell);

	}
	else
	{
		if (n == 0)													//moving left
		{
			if (i % cols == 0)										//checking bounds of the board
			{
				return;
			}
			else if (currArray[i - 1] == NULL)						//checking if movement is to an empty space
			{
				newArray[i - 1] = currArray[i];
				newArray[i] = NULL;
				return;
			}
			else													//if trying to move to a non empty space
			{
				return;
			}
		}
		else if (n == 1)											//moving right
		{
			if (i % cols == cols + 1)								//checking bounds of the board
			{
				return;
			}
			else if (currArray[i + 1] == NULL)						//checking if movement is to an empty space
			{
				newArray[i + 1] = currArray[i];
				newArray[i] = NULL;
				return;
			}
			else													//if trying to move to a non-empty space
			{
				return;
			}
		}
		else if (n == 2)											//moving up
		{
			if (i - cols < 0)										//checking bounds of the board
			{
				return;
			}
			else if (currArray[i - cols] == NULL)					//checking if movement is to an empty space
			{
				newArray[i - cols] = currArray[i];
				newArray[i] = NULL;
				return;
			}
			else													//if trying to move to a non-empty space 
			{
				return;
			}
		}
		else														//moving down
		{
			if (i + cols > totalCell - 1)										//checking the bounds of the board
			{
				return;
			}
			else if (currArray[i + cols] == NULL)					//checking if movement is to an empty space
			{
				newArray[i + cols] = currArray[i];
				newArray[i] = NULL;
				return;
			}
			else													//if space to move is not empty it stays in the same place
			{
				return;
			}
		}
	}
}
/********************************************************************************************
** Function: breed(critter *currArray[], critter *newArray[], int i, int cols, int totalCell)
** Description: copies itself into a new cell in newArray
** Parameters: critter *currArray[], critter *newArray[], int i, int cols, int totalCell
** Pre-conditions: currArray and newArray must be same size
** Post-conditions: an adjacent cell will have an ant
*********************************************************************************************/


void ant::breed(critter *currArray[], critter *newArray[], int i, int cols, int totalCell)
{
	n = rand() % 4;												//randomly generating four numbers to decide where to move
	if (n == 0)													//moving left
	{
		if (i % cols == 0)										//checking bounds of the board
		{
			return;
		}
		else if (currArray[i - 1] == NULL)						//checking if new ant is to an empty space
		{
			newArray[i - 1] = new ant;
		}
		else													//if trying to move to a non empty space
		{
			return;
		}
	}
	else if (n == 1)											//moving right
	{
		if (i % cols == cols + 1)								//checking bounds of the board
		{
			return;
		}
		else if (currArray[i + 1] == NULL)						//checking if new ant is to an empty space
		{
			newArray[i + 1] = new ant;
		}
		else													//if trying to move to a non-empty space
		{
			return;
		}
	}
	else if (n == 2)											//moving up
	{
		if (i - cols < 0)										//checking bounds of the board
		{
			return;
		}
		else if (currArray[i - cols] == NULL)					//checking if new ant is to an empty space
		{
			newArray[i - cols] = new ant;
		}
		else													//if trying to move to a non-empty space 
		{
			return;
		}
	}
	else														//moving down
	{
		if (i + cols > totalCell - 1)							//checking the bounds of the board
		{
			return;
		}
		else if (currArray[i + cols] == NULL)					//checking if new ant is to an empty space
		{
			newArray[i + cols] = new ant;
		}
		else													//if space to move is not empty it stays in the same place
		{
			return;
		}
	}
}

void ant::resetStat()
{}
