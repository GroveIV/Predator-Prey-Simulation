/****************************************************************************************************
** Program Filename: gameboard.cpp
** Author: Edwin Grove
** Date: 2/4/2016
** Description: creates the arrays used through the game and contains functions that control the game exectution
** Input: none
** Output: none
*****************************************************************************************************/

#include "gameboard.hpp"
#include <iostream>
#include <time.h>
#include <stdlib.h>
using std::cout;
using std::endl;


/******************************************************************************************************
** Default constructor - gameboard class
*******************************************************************************************************/

gameboard::gameboard()
{
	srand(time(NULL));
	rows = 20;
	cols = 20;
	numAnts = 50;
	numDoods = 5;
	totalCells = rows * cols;
	newArray = new critter*[totalCells];
	currArray = new critter*[totalCells];
}

gameboard::~gameboard()
{
	for (int i = 0; i < totalCells; i++)
	{
			delete newArray[i];
	}
	delete[] newArray;
	delete[] currArray;
}
/******************************************************************************************************
** Secondary constructor - gameboard class
*******************************************************************************************************/


gameboard::gameboard(int a, int d, int r, int c)
{
	srand(time(NULL));
	rows = r;
	cols = c;
	numAnts = a;
	numDoods = d;
	totalCells = r * c;
	newArray = new critter*[totalCells];
	currArray = new critter*[totalCells];
}
/*******************************************************************************************************
** Function: fillboard()
** Description: This function fills the 'board' (array) critter class objects and their derived counterparts
** Parameters: none
** Pre-conditions: arrays must be initialized before using function
** Post-conditions: an array is filled with derived critter class objects and then copied to another array
********************************************************************************************************/


void gameboard::fillBoard()
{
	for (int i = 0; i < totalCells; i++)									//fill array with null pointers
	{
		currArray[i] = NULL;
	}
	for (int i = 0; i < numAnts; i++)										//for however many ants the user wants
	{
		randNum = rand() % totalCells;										//randomizes placement of ants
		if (currArray[i] == NULL)
			currArray[randNum] = new ant;
		else
			currArray[randNum + 1] = new ant;
	}
	for (int i = 0; i < numDoods; i++)										//for however many doodlebugs user wants
	{
		randNum = rand() % totalCells;										//randomizes placement
		if (currArray[i] == NULL)
			currArray[randNum] = new doodleBug;
		else
			currArray[randNum + 1] = new doodleBug;
	}
	for (int i = 0; i < totalCells; i++)									//copies array to newArray
	{
		newArray[i] = currArray[i];
	}
}
/**********************************************************************************************************
** Function: printBoard()
** Description: This outputs the array to the user
** Parameters: none
** Pre-conditions: newArray must have either null pointers or critter objects
** Post-conditions: prints array to screen
***********************************************************************************************************/

void gameboard::printBoard()
{
	for (int i = 0; i < cols + 2; i++)									//printing an upper border
		cout << '_';
	cout << endl;
	for (int i = 1; i <= totalCells; i++)								
	{
		if (i % cols == 1)
			cout << '|';												//Left most border
		if (newArray[i - 1] == NULL)									//printing blank spaces for where there is no critter
		{
			cout << ' ';
		}
		else
			cout << newArray[i - 1]->getSign();							//printing X or O for a critter that is present
		if (i % cols == 0)
		{
			cout << '|' << endl;										//right most border
		}
	}
	cout << '|';
	for (int i = 0; i < cols; i++)										//bottom edge of border
	{
		cout << "_";
	}
	cout << '|' << endl;
}

/*************************************************************************************************************
** Function: updateBoard()
** Description: Updates the board after a move from both doodlebugs and ants
** Parameters: none
** Pre-conditions: both newArray and currArray must be of equal size
** Post-condition: both arrays are updated according to the critters move function
**************************************************************************************************************/


void gameboard::updateBoard()
{
	for (int i = 0; i < totalCells; i++)
	{
		if (currArray[i] != NULL && currArray[i]->getSign() == 'X')
		{
			currArray[i]->move(currArray, newArray, i, cols, totalCells);
		}
	}
	for (int i = 0; i < totalCells; i++)
	{
		currArray[i] = newArray[i];
	}
	for (int i = 0; i < totalCells; i++)
	{
		if (currArray[i] != NULL && currArray[i]->getSign() == 'O')
		{
			currArray[i]->move(currArray, newArray, i, cols, totalCells);
		}
	}
	for (int i = 0; i < totalCells; i++)
	{
		currArray[i] = newArray[i];
	}
}
