/****************************************************************************************************
** Program Filename: main.cpp
** Author: Edwin Grove
** Date: 2/4/2016
** Description: the driver that runs that predator prey game
** Input: none
** Output: none
*****************************************************************************************************/

#include "gameboard.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
	int numAnts = 0;
	int numDoods = 0;
	int rows = 0;
	int cols = 0;
	int numSteps = 0;
	cout << "How many rows would you like to use? ";
	cin >> rows;
	cout << "\nHow many columns would you like to use? ";
	cin >> cols;
	cout << "\nHow many ants would you like to start with? ";
	cin >> numAnts;
	cout << "\nHow many doodlebugs would you like to start with? ";
	cin >> numDoods;
	cout << "\nHow many steps would you like to see? ";
	cin >> numSteps;
	gameboard game(numAnts, numDoods, rows, cols);
	game.fillBoard();
	game.printBoard();
        cout << "\033[22A";
	for (int i = 0; i < numSteps; i++)
	{
	        usleep(150000);
		game.updateBoard();
		game.printBoard();
		if (i < numSteps - 1)
		{
		   cout << "\033[22A";
		}
	}
	//game.~gameboard();
	return 0;


}
