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
		void setOptions() // will be void setOptions(option a, option b, option c, etc...)
		{
			cout << "set options" << endl;
			//variables that can be set by the other functions with in the class
			//and can then be check in either the main or by the other functions
			//so that we can have some leg room for later
			//w00t woo!
		}

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

		void newGame(int diff) // right now just builds a 9 x 9 array of zeros
		{
			for (int a = 0; a < 9; a++)
			{
				for (int b = 0; b < 9; b++)
				{
					game[a][b] = diff;
				}
			}
		}

		void loadGame() //was void loadGame(string gameToLoad)
		{
			int A = 0, B = 0, C = 0, D = 0, E = 0, F = 0, G = 0, H = 0, I = 0;			
			ifstream openingFile;
			openingFile.open("sudokuFALSE.txt"); // openingFile.open(gameToLoad);
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

		bool checkSection(int m, int n) // Given a location we check a specific section
		{
			//Sections
			//1 2 3
			//4 5 6
			//7 8 9
			// It feels like this could be condensed.
			// Any thoughts?
			int number = game[m][n];

			if ((m >= 0) and (m <= 2) and (n >= 0) and (n <= 2)) // Section 1
			{
				for (int a = 0; a < 3; a++)
				{
					for (int b = 0; b < 3; b++)
					{
						int checkNum = game[a][b];
						if ((checkNum == number) and (a != m) and (b != n))
						{
							return false;
						}
					}
				}
			}

			else if((m >= 0) and (m <= 2) and (n >= 3) and (n <= 5)) // Section 2
			{
				for (int a = 0; a < 3; a++)
				{
					for (int b = 3; b < 6; b++)
					{
						int checkNum = game[a][b];
						if ((checkNum == number) and (a != m) and (b != n))
						{
							return false;
						}
					}
				}
			}

			else if((m >= 0) and (m <= 2) and (n >= 6) and (n <= 8)) // Section 3
			{
				for (int a = 0; a < 3; a++)
				{
					for (int b = 6; b < 9; b++)
					{
						int checkNum = game[a][b];
						if ((checkNum == number) and (a != m) and (b != n))
						{
							return false;
						}
					}
				}
			}

			else if((m >= 3) and (m <= 5) and (n >= 0) and (n <= 2)) // Section 4
			{
				for (int a = 3; a < 6; a++)
				{
					for (int b = 0; b < 3; b++)
					{
						int checkNum = game[a][b];
						if ((checkNum == number) and (a != m) and (b != n))
						{
							return false;
						}
					}
				}
			}

			else if((m >= 3) and (m <= 5) and (n >= 3) and (n <= 5)) // Section 5
			{
				for (int a = 3; a < 6; a++)
				{
					for (int b = 3; b < 6; b++)
					{
						int checkNum = game[a][b];
						if ((checkNum == number) and (a != m) and (b != n))
						{
							return false;
						}
					}
				}
			}

			else if((m >= 3) and (m <= 5) and (n >= 6) and (n <= 8)) // Section 6
			{
				for (int a = 3; a < 6; a++)
				{
					for (int b = 6; b < 9; b++)
					{
						int checkNum = game[a][b];
						if ((checkNum == number) and (a != m) and (b != n))
						{
							return false;
						}
					}
				}
			}

			else if((m >= 6) and (m <= 8) and (n >= 0) and (n <= 2)) // Section 7
			{
				for (int a = 6; a < 9; a++)
				{
					for (int b = 0; b < 3; b++)
					{
						int checkNum = game[a][b];
						if ((checkNum == number) and (a != m) and (b != n))
						{
							return false;
						}
					}
				}
			}

			else if((m >= 6) and (m <= 8) and (n >= 3) and (n <= 5)) // Section 8
			{
				for (int a = 6; a < 9; a++)
				{
					for (int b = 3; b < 6; b++)
					{
						int checkNum = game[a][b];
						if ((checkNum == number) and (a != m) and (b != n))
						{
							return false;
						}
					}
				}
			}

			else if((m >= 6) and (m <= 8) and (n >= 6) and (n <= 8)) // Section 9
			{
				for (int a = 6; a < 9; a++)
				{
					for (int b = 6; b < 9; b++)
					{
						int checkNum = game[a][b];
						if ((checkNum == number) and (a != m) and (b != n))
						{
							return false;
						}
					}
				}
			}

			return true;
		}

		bool checkRow(int x, int y)
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

		bool checkCol(int x, int y)
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
			for (int j = 0; j < 9; j++)
			{
				for (int k = 0; k < 9; k++)
				{
					bool cols = checkCol(j,k);
					bool rows = checkRow(j,k);
					bool secs = checkSection(j,k);
					if ((cols == false) or (rows == false) or (secs == false))
					{
						return false;
					}
				}
			}
			return true;
		}

		void changeNum(int x, int a, int b)
		{
			game[a][b] = x;
		}

		bool isValid(int a, int b) // check the recently entered number to see if it is valid.
		{
			bool col = false, row = false, sec = false;
			
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
		
		if (choice == 10)
		{
			cout << "Good-Bye" << endl;
			newGame.saveGame();
			break;
		}

		else if (choice == 1)
		{
			cout << endl << "New Game" << endl;
			int difficulty = 0;
			cout << "Enter the Difficulty you want:" << endl;
			cout << "1. Easy" << endl;
			cout << "2. Medium" << endl;
			cout << "3. Hard" << endl;
			cin >> difficulty;
			newGame.newGame(difficulty);
		}
		else if (choice == 2)
		{
			//string oldGame = "";
			cout << endl << "Load Game" << endl << "Enter the name of the game you wish to load:" << endl;
			//cin >> oldGame;
			newGame.loadGame(); // was newGame.loadGame(oldGame);
		}
		else if (choice == 3)
		{
			cout << endl << "Print Game" << endl << endl;
			newGame.printGame();
		}
		else if (choice == 4)
		{
			cout << endl << "Check Location" << endl;
			bool isTrueRow = false, isTrueCol = false, isTrueSec = false;
			int locX = -1, locY = -1;

			cout << "Enter the location of the digit you wish to check:" << endl;
			cin >> locX >> locY; // Remember to check to see that the location exists!
			locX -= 1;
			locY -= 1;
			if (((locX < 9) and (locX > -1)) and ((locY < 9) and (locY > -1)))
			{
				isTrueRow = newGame.checkRow(locX,locY);
				isTrueCol = newGame.checkCol(locX,locY);
				isTrueSec = newGame.checkSection(locX,locY);
			}
			else
			{
				cout << "You entered incorrect location." << endl;
			}

			if (isTrueSec == false)
			{
				cout << newGame.printLoc(locX,locY) << " is not valid it's section." << endl;
			}

			if ((isTrueRow == true) and (isTrueCol == true) and (isTrueSec == true))
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
			bool goodGame = newGame.checkGame();
			if (goodGame == true)
			{
				cout << "This game is complete." << endl;
			}
			else
			{
				cout << "This game is incomplete." << endl;
			}
		}
		else if (choice == 6)
		{
			int x = 0, y = 0, num = 0;
			cout << endl << "edit location" << endl;
			cout << endl << "Enter the x and y location of the number you want to change:" << endl;
			cin >> x >> y; // remember to check to see if these coordinates are valid (0-8)(0-8)
			cout << "Enter the number:" << endl;
			cin >> num; // remember to check to see if this is a valid # (1-9)
			newGame.changeNum(num,x - 1,y - 1);
			// check to see that the number is valid in here.
			newGame.printGame();
			
		}
		else if (choice == 7)
		{
			cout << endl << "Generate Game" << endl;
		}
		else if (choice == 8)
		{
			cout << endl << "Solve Game" << endl;
		}
		else if (choice == 9)
		{
			cout << endl << "Set Options" << endl;
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
		cout << "4. Check Location" << endl;
		cout << "5. Check Game" << endl;
		cout << "6. Edit Location" << endl;
		cout << "#7 Generate Game" << endl;
		cout << "#8 Solve Game" << endl;
		cout << "#9 Set Options" << endl;
		cout << "10. Exit" << endl;
		cout << "Enter choice" << endl;
		cout << "(# denotes unfinished options)" << endl;
		cin >> userChoice;

		if ((userChoice <= 10) and (userChoice >= 1))
		{
			return userChoice;
		}
	}
}
