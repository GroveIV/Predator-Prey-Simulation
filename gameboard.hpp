/****************************************************************************************************
** Program Filename: gameboard.hpp
** Author: Edwin Grove
** Date: 2/4/2016
** Description: header file for gameboard class
** Input: none
** Output: none
*****************************************************************************************************/

#ifndef GAMEBOARD_HPP
#define GAMEBOARD_HPP

#include "critter.hpp"
#include "ant.hpp"
#include "doodleBug.hpp"

class gameboard
{
public: 
	gameboard();
	~gameboard();
	gameboard(int a, int d, int r, int c);
	void fillBoard();
	void printBoard();
	void updateBoard();
private:
	int rows;
	int cols;
	int totalCells;
	int randNum;
	int numAnts;
	int numDoods;
	critter **newArray;
	critter **currArray;
};


#endif // !GAMEBOARD_HPP

