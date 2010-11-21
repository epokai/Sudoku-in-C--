#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class sudokuGame
{
	private:
		int game[9][9];
		int toCheck;
		//string gameToLoad = "sudokuTrue.txt";

	public:
		// using structures in classes?
		// we need something like a structure or a recursive element that we can call to see what its status is

		void printGame()
		{
			for (int a = 0; a < 9; a++)
			{
				for (int b = 0; b < 9; b++)
				{
					cout << game[a][b] << " ";
				}
				cout << endl;
			}
		}

		int printLoc(int x, int y)
		{
			return game[x][y];
		}

		void loadGame() //was void loadGame(string gameToLoad)
		{
			int A = 0, B = 0, C = 0, D = 0, E = 0, F = 0, G = 0, H = 0, I = 0;			
			ifstream openingFile;
			openingFile.open("sudokuFalse.txt"); // openingFile.open(gameToLoad);
			for (int line = 0; line < 9; line++)
			{
				openingFile >> A >> B >> C >> D >> E >> F >> G >> H >> I;
				game[line][0] = A;
				game[line][1] = B;
				game[line][2] = C;
				game[line][3] = D;
				game[line][4] = E;
				game[line][5] = F;
				game[line][6] = G;
				game[line][7] = H;
				game[line][8] = I;
			}

			openingFile.close();
		}

		void saveGame()
		{
			ofstream savingFile;
			savingFile.open("sudokuSaved.txt");
			for (int row = 0; row < 9; row++)
			{
				for (int col = 0; col < 9; col++)
				{
					savingFile << game[row][col] << " ";
				}
				savingFile << endl;
			}
			savingFile.close();
		}

		int numToCheck(int n) // checking the viability for a number in an area.
		{
			return 0;
		}

		bool checkRow(int x, int y) // unchecked
		{
			int number = game[x][y];
			for (int a = 0; a < 9; a++)
			{
				toCheck = game[x][a];
				if ((toCheck == number) and (a != y))
				{
					return false;
				}
			}
			return true;
		}

		bool checkCol(int x, int y) // unchecked
		{
			int number = game[x][y];
			for (int b = 0; b < 9; b++)
			{
				toCheck = game[b][y];
				if ((toCheck == number) and (b != x))
				{
					return false;
				}
			}
			return true;
		}

		bool checkGame()
		{
			return false;
		}
};

int menu();

int main()
{
	sudokuGame newGame;

	while(true)
	{
		int choice = menu();
		cout << endl;
		
		if (choice == 7)
		{
			cout << "Good-Bye" << endl;
			newGame.saveGame();
			break;
		}

		else if (choice == 1)
		{
			cout << endl << "New Game" << endl << endl;
		}
		else if (choice == 2)
		{
			cout << endl << "Load Game" << endl << endl;
			newGame.loadGame();
		}
		else if (choice == 3)
		{
			cout << endl << "Print Game" << endl << endl;
			newGame.printGame();
		}
		else if (choice == 4)
		{
			cout << endl << "Check Game" << endl << endl;
			bool isTrueRow = false, isTrueCol = false;
			int locX = -1, locY = -1;

			cout << "Enter the location of the digit you wish to check:" << endl;
			cin >> locX >> locY; // Remember to check to see that the location exists!
			locX -= 1;
			locY -= 1;
			if (((locX < 9) and (locX > -1)) and ((locY < 9) and (locY > -1)))
			{
				isTrueRow = newGame.checkRow(locX,locY);
				isTrueCol = newGame.checkCol(locX,locY);
			}
			else
			{
				cout << "You entered incorrect location." << endl;
			}

			if ((isTrueRow == true) and (isTrueCol == true))
			{
				cout << newGame.printLoc(locX,locY) << " at this location is legitimate" << endl;
			}
			else if ((isTrueRow == false) and (isTrueCol == true))
			{
				cout << "There is a repetition of " << newGame.printLoc(locX,locY) << " in the row." << endl;
			}
			else if ((isTrueRow == true) and (isTrueCol == false))
			{
				cout << "There is a repetition of " << newGame.printLoc(locX,locY) << "in the column." << endl;
			}
			else
			{
				cout << newGame.printLoc(locX,locY) << " is in both the row and the column." << endl;
			}

		}
		else if (choice == 5)
		{
			cout << endl << "Generate Game" << endl << endl;
		}
		else if (choice == 6)
		{
			cout << endl << "Solve Game" << endl << endl;
		}

	}
	return 0;
}

int menu()
{
	while(true)
	{
		int userChoice;
		cout << "Main Menu" << endl;
		cout << "#1. New Game" << endl;
		cout << "2. Load Game" << endl;
		cout << "3. Print Game" << endl;
		cout << "4. Check Game" << endl;
		cout << "#5 Generate Game" << endl;
		cout << "#6 Solve Game" << endl;
		cout << "7. Exit" << endl;
		cout << "Enter choice" << endl;
		cout << "(# denotes unfinished options)" << endl;
		cin >> userChoice;

		if ((userChoice <= 7) and (userChoice >= 1))
		{
			return userChoice;
		}
	}
}
