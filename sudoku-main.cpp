#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include "sudoku-class.h"

using namespace std;

int mainMenu();

int gameMain();

void game(sudokuGame);

int main()
{
	sudokuGame puzzleA;
	int difficulty = 0;
	while (true)
	{
		int mainChoice = mainMenu();
		if (mainChoice == 4)
		{
			cout << "Good-bye!" << endl;
			break;
		}
		else if (mainChoice == 1)
		{
			cout << "New Game." << endl;
			cout << "Enter the difficulty level for your game:\n(1-2. Easy, 3-4 Medium, 5-6 Hard)\nDifficulty> " << endl;
			while(true)
			{
				cin >> difficulty;
				if ((difficulty <= 0) or (difficulty >= 7))
				{
					cout << "Invalid level.\nPlease re-enter the level.\nDifficulty> " << endl;
				}
				else if ((difficulty >= 1) or (difficulty <= 6))
				{
					break;
				}
			}
			cout << "You have chosen a difficulty of " << difficulty << "." << endl; 
			puzzleA.newGame(difficulty);
			game(puzzleA);
		}
		else if (mainChoice == 2)
		{
			cout << "Loading last saved game." << endl;
			puzzleA.loadGame();
			game(puzzleA);
		}
		else if (mainChoice == 3)
		{
			cout << "Set Options" << endl;
			puzzleA.setOptions();
		}
		else if (mainChoice == 99) // Debugging Menu
		{
			sudokuGame PuzzleB;
			bool runWhile = true, someCol = false, someRow = false, someSec = false, finishedPuzzle = false;
			int x = 0, y = 0, num = 0;
			while(runWhile)
			{
				char debugChoice;
				cout << "Debug Menu\nN. New Game\nL. Load Game\nS. Save Game\nP. Print Game\nK. Check Full Game\nR. Check Row\nC. Check Column\nZ. Check Section\nE. Edit Location\nU. Check Possiblities\nX. Exit\nTest> ";
				cin >> debugChoice;
				switch (debugChoice)
				{
					case 'N' : cout << "New Game (default Difficulty: 1)" << endl;
								PuzzleB.newGame(1);
								break;
					case 'L' : cout << "Loading Game (default load file: sudokuSAVED.txt)" << endl;
								PuzzleB.loadGame();
								break;
					case 'S' : cout << "Saving Game (default save file: sudokuSAVED.txt)" << endl;
								PuzzleB.saveGame();
								break;
					case 'P' : cout << "Print Game" << endl;
								PuzzleB.printGame();
								break;
					case 'K' : finishedPuzzle = PuzzleB.checkPuzzle();
								if (finishedPuzzle == true)
								{
									cout << "Game is finished." << endl;
								}
								else if (finishedPuzzle == false)
								{
									cout << "Game is not finished!" << endl;
								}
								break;
					case 'R' : cout << "Enter an (x,y) location to check the row." << endl;
								cout << "X> ";
								cin >> x;
								cout << "Y> ";
								cin >> y;
								someRow = PuzzleB.checkRow(y,x);
								if (someRow == true)
								{
									cout << "There is nothing wrong with the row." << endl;
								}
								else if (someRow == false)
								{
									cout << "There is something wrong with the row." << endl;
								}
								break;
					case 'C' : cout << "Enter an (x,y) location to check the column." << endl;
								cout << "X> ";
								cin >> x;
								cout << "Y> ";
								cin >> y;
								someCol = PuzzleB.checkCol(y,x);
								if (someCol == true)
								{
									cout << "There is nothing wrong with the column" << endl;
								}
								else if (someCol == false)
								{
									cout << "There is something wrong with the column" << endl;
								}
								break;
					case 'Z' : cout << "Enter an (x,y) location to check the section." << endl;
								cout << "X> ";
								cin >> x;
								cout << "Y> ";
								cin >> y;
								someSec = PuzzleB.checkSection(y,x);
								if (someSec == true)
								{
									cout << "There is nothing wrong with the section" << endl;
								}
								else if (someSec == false)
								{
									cout << "There is something wrong with the section" << endl;
								}
								break;
					case 'E' : cout << "Edit a location.\n(x,y,num) (0-8,0-8,1-9)" << endl;
								num = 0;
								cout << "X> ";
								cin >> x;
								cout << "Y> ";
								cin >> y;
								cout << "NUM> ";
								cin >> num;
								PuzzleB.changeNum(num,y,x);
								break;
					case 'U' : cout << "Finding Numbers for a location. (x,y)" << endl;
								cout << "X> ";
								cin >> x;
								cout << "Y> ";
								cin >> y;
								PuzzleB.possibleNum(y,x);
								break;
					case 'X' : cout << "Exiting Debugger." << endl;
								runWhile = false;
								break;
					default : cout << "Incorrect input." << endl;
								break;
				}
			}
		}
	}
	return 0;
}

int mainMenu()
// This is the pre-game menu. From here, you may set various options in the game, load old games, and start new ones.
{
	while(true)
	{
		int userChoice;
		cout << "\n\nMain Menu\n1. New Game\n2. Load Game\n3. Set Options\n4. Exit\nEnter choice> ";
		cin >> userChoice;

		if (((userChoice <= 4) and (userChoice >= 1)) or (userChoice == 99))
		{
			return userChoice;
		}
	}
}

int gameMenu()
// This is the in-game menu. From here you will interact with the sudoku game.
{
	while (true)
	{
		int command = 0;
		cout << "1. Edit Location, 2. GoTo Main Menu\nCommand> ";
		cin >> command;
		if ((command == 2) or (command == 1))
		{
			return command;
		}
	}
}

void game(sudokuGame puzzle)
// This is the actual game program. This the program will react to information given by the user.
{
	bool runWhile = true;
	while (runWhile)
	{
		int commands;
		bool hints = puzzle.returnHints();
		puzzle.printGame();
		commands = gameMenu();

		if (commands == 2)
		// GoTo Main Menu (With saving option)
		{
			char save;
			cout << "Would you like to save your game?\nThis will save over any previously existing game.\nSave? (Y/N)> ";
			while(runWhile)
			{
				cin >> save;
				switch(save)
				{
					case 'Y' :
					case 'y' : puzzle.saveGame();
								cout << "Your game has been saved!" << endl;
								runWhile = false;
								break;
					case 'n' :
					case 'N' : cout << "Your game has not been saved!" << endl;
								runWhile = false;
								break;
					default : cout << "Invalid Entry.\nPlease re-enter.\nSave? (Y/N)> ";
								break;
				}
			}
		}
		else if (commands == 1)
		// Edit a location in the Sudoku Game
		{
			int x = -1, y = -1, num = -1;
			cout << "\nEnter the location (x,y coordinates):\nx> ";
			cin >> x;
			cout << "y> ";
			cin >> y;
			while (true)
			{
				if ((x > 10) or (x < 1))
				{
					cout << "Invalid x location.\nEnter a new X coordinate: ";
					cin >> x;
				}
				if ((y > 10) or (y < 1))
				{
					cout << "Invalid y location.\nEnter a new Y coordinate: ";
					cin >> y;
				}
				else if ((y < 10) and (y >= 1) and (x < 10) and (x >= 1))
				{
					break;
				}
			}
			cout << "Enter a number for (" << x << "," << y << ").\n(Enter 0 to reset the value): ";
			do
			{
				cin >> num;
				if ((num <= -1) or (num >= 10))
				{
					cout << "This is an invalid number.\nEnter a new number: ";
				}
			} while ((num <= -1) or (num >= 10));

			puzzle.changeNum(num,y,x);

			if ((hints == true) and (num != 0))
			{
				bool isTrueRow = puzzle.checkRow(y,x);
				bool isTrueCol = puzzle.checkCol(y,x);
				bool isTrueSec = puzzle.checkSection(y,x);

				cout << "\n\n\n" << num << " at (" << x << "," << y << ")" ;

				if ((isTrueRow == true) and (isTrueCol == true) and (isTrueSec == true))
				{
					cout <<  " is valid." << endl;
				}
				if ((isTrueRow == false) or (isTrueCol == false) or (isTrueSec == false))
				{
					cout << " is not valid." << endl;
				}
				if (isTrueSec == false)
				{
					cout << num << " is repeated in it's section." << endl;
				}
				if (isTrueRow == false)
				{
					cout << num << " is repeated in it's row." << endl;
				}
				if (isTrueCol == false)
				{
					cout << num << " is repeated in it's column." << endl;
				}
				if ((isTrueRow == false) or (isTrueCol == false) or (isTrueSec == false))
				{
					puzzle.possibleNum(y,x);
				}
			}
		}
	}
}
