//#include "sudoku-lib.h"
/*
methods in class sudokuGame
void setOptions()
bool returnHints()
void printGame()
int printLoc(int x, int y)
void newGame(int diff)
void loadGame()
void saveGame()
bool checkSection(int x, int y)
bool checkRow(int x, int y)
bool checkCol(int x, int y)
bool checkPuzzle()
void changeNum(int num, int a, int b)
bool isValid(int a, int b)
void possibleNum(int x, int y)
*/
using namespace std;

class sudokuGame
{
	private:
		int game[9][9], solution[9][9];
		int toCheck;
		char hintLevel;
		//string gameToLoad = "sudokuTrue.txt";

	public:
		void setOptions()
		//sets up some of the game options
		{
			bool runWhile = true;
			cout << "\nSet Game Options\nWould you like hints?\nHints (Y/N)> " << endl;
			while(runWhile)
			{
				cin >> hintLevel;
				switch (hintLevel)
				{
					case 'y' :
					case 'Y' : cout << "Hints will be displayed!" << endl;
								runWhile = false;
								break;
					case 'n' :
					case 'N' : cout << "No hints will be displayed!" << endl;
								runWhile = false;
								break;
					default : cout << "Invalid level.\nPlease re-enter the level.\nDifficulty> " << endl;
								break;
				}
			}
		}

		bool returnHints()
		//checks to see if hints are on or off
		{
			switch(hintLevel)
			{
				case 'y' :
				case 'Y' : return true;
							break;
				case 'n' :
				case 'N' : return false;
							break;
				default : return false;
							break;
			}
		}

		void printGame()
		// Prints the sudoku game array as in a readable format
		{
			cout << "0| 1 2 3 | 4 5 6 | 7 8 9 (x)\n |-----------------------" << endl;
			for (int a = 0; a < 3; a++)
			{
				cout << a + 1 << "| ";
				for (int b = 0; b < 3; b++)
				{
					if (game[a][b] != 0)
					{					
						cout << game[a][b] << " ";
					}
					else if (game[a][b] == 0)
					{
						cout << ". ";
					}
				}
				cout << "| ";
				for (int b = 3; b < 6; b++)
				{
					if (game[a][b] != 0)
					{					
						cout << game[a][b] << " ";
					}
					else if (game[a][b] == 0)
					{
						cout << ". ";
					}
				}
				cout << "| ";
				for (int b = 6; b < 9; b++)
				{
					if (game[a][b] != 0)
					{					
						cout << game[a][b] << " ";
					}
					else if (game[a][b] == 0)
					{
						cout << ". ";
					}
				}
				cout << endl;
			}
			cout << " | ------|-------|-------" << endl;
			for (int a = 3; a < 6; a++)
			{
				cout << a + 1 << "| ";
				for (int b = 0; b < 3; b++)
				{
					if (game[a][b] != 0)
					{					
						cout << game[a][b] << " ";
					}
					else if (game[a][b] == 0)
					{
						cout << ". ";
					}
				}
				cout << "| ";
				for (int b = 3; b < 6; b++)
				{
					if (game[a][b] != 0)
					{					
						cout << game[a][b] << " ";
					}
					else if (game[a][b] == 0)
					{
						cout << ". ";
					}
				}
				cout << "| ";
				for (int b = 6; b < 9; b++)
				{
					if (game[a][b] != 0)
					{					
						cout << game[a][b] << " ";
					}
					else if (game[a][b] == 0)
					{
						cout << ". ";
					}
				}
				cout << endl;
			}
			cout << " | ------|-------|-------" << endl;
			for (int a = 6; a < 9; a++)
			{
				cout << a + 1 << "| ";
				for (int b = 0; b < 3; b++)
				{
					if (game[a][b] != 0)
					{					
						cout << game[a][b] << " ";
					}
					else if (game[a][b] == 0)
					{
						cout << ". ";
					}
				}
				cout << "| ";
				for (int b = 3; b < 6; b++)
				{
					if (game[a][b] != 0)
					{					
						cout << game[a][b] << " ";
					}
					else if (game[a][b] == 0)
					{
						cout << ". ";
					}
				}
				cout << "| ";
				for (int b = 6; b < 9; b++)
				{
					if (game[a][b] != 0)
					{					
						cout << game[a][b] << " ";
					}
					else if (game[a][b] == 0)
					{
						cout << ". ";
					}
				}
				cout << endl;
			}
			cout << "(y)" << endl;
		}

		int printLoc(int x, int y)
		// returns the number at a specific location
		{
			return game[x][y];
		}

		void newGame(int diff)
		//builds a new sudoku puzzle for the user
		{
			int A = 0, B = 0, C = 0, D = 0, E = 0, F = 0, G = 0, H = 0, I = 0, randPuzzle = 0;
			ifstream solnFile;
			srand ( time(NULL) );
			randPuzzle = rand() % 3 + 1;
			if (randPuzzle == 1)
			{
				solnFile.open("sudoku0.txt");
				for (int line = 0; line < 9; line++)
				{
					solnFile >> A >> B >> C >> D >> E >> F >> G >> H >> I;
					solution[line][0] = A;
					solution[line][1] = B;
					solution[line][2] = C;
					solution[line][3] = D;
					solution[line][4] = E;
					solution[line][5] = F;
					solution[line][6] = G;
					solution[line][7] = H;
					solution[line][8] = I;
				}
				solnFile.close();
			}
			else if (randPuzzle == 2)
			{
				solnFile.open("sudoku1.txt");
				for (int line = 0; line < 9; line++)
				{
					solnFile >> A >> B >> C >> D >> E >> F >> G >> H >> I;
					solution[line][0] = A;
					solution[line][1] = B;
					solution[line][2] = C;
					solution[line][3] = D;
					solution[line][4] = E;
					solution[line][5] = F;
					solution[line][6] = G;
					solution[line][7] = H;
					solution[line][8] = I;
				}
				solnFile.close();
			}
			else if (randPuzzle == 3)
			{
				solnFile.open("sudoku2.txt");
				for (int line = 0; line < 9; line++)
				{
					solnFile >> A >> B >> C >> D >> E >> F >> G >> H >> I;
					solution[line][0] = A;
					solution[line][1] = B;
					solution[line][2] = C;
					solution[line][3] = D;
					solution[line][4] = E;
					solution[line][5] = F;
					solution[line][6] = G;
					solution[line][7] = H;
					solution[line][8] = I;
				}
				solnFile.close();
			}
			for (int a = 0; a < 9; a++)
			{
				for (int b = 0; b < 9; b++)
				{
					game[a][b] = 0;
				}
			}

			if((diff == 1) or (diff == 2))
			{
				//write a function set the pattern.
				game[0][0] = solution[0][0];
				game[0][1] = solution[0][1];
				game[0][2] = solution[0][2];
				game[0][3] = solution[0][3];
				game[1][1] = solution[1][1];
				game[1][5] = solution[1][5];
				game[1][6] = solution[1][6];
				game[1][7] = solution[1][7];
				game[2][1] = solution[2][1];
				game[2][4] = solution[2][4];
				game[3][1] = solution[3][1];
				game[3][2] = solution[3][2];
				game[3][4] = solution[3][4];
				game[4][0] = solution[4][0];
				game[4][8] = solution[4][8];
				game[5][4] = solution[5][4];
				game[5][6] = solution[5][6];
				game[5][7] = solution[5][7];
				game[6][4] = solution[6][4];
				game[6][7] = solution[6][7];
				game[7][1] = solution[7][1];
				game[7][2] = solution[7][2];
				game[7][3] = solution[7][3];
				game[7][7] = solution[7][7];
				game[8][5] = solution[8][5];
				game[8][6] = solution[8][6];
				game[8][7] = solution[8][7];
				game[8][8] = solution[8][8];

			}
			else if((diff == 3) or (diff == 4))
			{
				//pattern 2
				game[0][2] = solution[0][2];
				game[0][3] = solution[0][3];
				game[0][4] = solution[0][4];
				game[0][8] = solution[0][8];
				game[1][0] = solution[1][0];
				game[1][2] = solution[1][2];
				game[1][3] = solution[1][3];
				game[1][6] = solution[1][6];
				game[1][7] = solution[1][7];
				game[2][1] = solution[2][1];
				game[3][1] = solution[3][1];
				game[3][4] = solution[3][4];
				game[3][5] = solution[3][5];
				game[3][8] = solution[3][8];
				game[4][0] = solution[4][0];
				game[4][3] = solution[4][3];
				game[4][5] = solution[4][5];
				game[4][8] = solution[4][8];
				game[5][0] = solution[5][0];
				game[5][3] = solution[5][3];
				game[5][4] = solution[5][4];
				game[5][7] = solution[5][7];
				game[6][7] = solution[6][7];
				game[7][1] = solution[7][1];
				game[7][2] = solution[7][2];
				game[7][5] = solution[7][5];
				game[7][6] = solution[7][6];
				game[7][8] = solution[7][8];
				game[8][0] = solution[8][0];
				game[8][4] = solution[8][4];
				game[8][5] = solution[8][5];
				game[8][6] = solution[8][6];
			}
			else if((diff == 5) or (diff == 6))
			{
				//pattern 3
				game[0][0] = solution[0][0];
				game[0][1] = solution[0][1];
				game[0][4] = solution[0][4];
				game[0][6] = solution[0][6];
				game[1][1] = solution[1][1];
				game[1][6] = solution[1][6];
				game[2][0] = solution[2][0];
				game[2][3] = solution[2][3];
				game[2][5] = solution[2][5];
				game[2][6] = solution[2][6];
				game[3][1] = solution[3][1];
				game[3][6] = solution[3][6];
				game[3][8] = solution[3][8];
				game[4][2] = solution[4][2];
				game[4][4] = solution[4][4];
				game[4][6] = solution[4][6];
				game[5][0] = solution[5][0];
				game[5][2] = solution[5][2];
				game[5][7] = solution[5][7];
				game[6][2] = solution[6][2];
				game[6][3] = solution[6][3];
				game[6][5] = solution[6][5];
				game[6][8] = solution[6][8];
				game[7][2] = solution[7][2];
				game[7][7] = solution[7][7];
				game[8][0] = solution[8][0];
				game[8][1] = solution[8][1];
				game[8][3] = solution[8][3];
				game[8][5] = solution[8][5];
				game[8][6] = solution[8][6];
			}
		}

		void loadGame()
		// loads a previously saved sudoku puzzle
		{
			int A = 0, B = 0, C = 0, D = 0, E = 0, F = 0, G = 0, H = 0, I = 0;			
			ifstream openingFile;
			openingFile.open("sudokuSAVED.txt");
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
		// Saves the current sudoku puzzle as a .txt file to be loaded later.
		{
			ofstream savingFile;
			savingFile.open("sudokuSAVED.txt");
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

		bool checkSection(int x, int y)
		// Given a location we check a specific section for the validity of the number
		{
			//Sections
			//1 2 3
			//4 5 6
			//7 8 9
			x -= 1;
			y -= 1;

			int number = game[x][y];

			if ((x >= 0) and (x <= 2) and (y >= 0) and (y <= 2)) // Section 1
			{
				for (int a = 0; a < 3; a++)
				{
					for (int b = 0; b < 3; b++)
					{
						int checkNum = game[a][b];
						if ((checkNum == number) and (a != x) and (b != y))
						{
							return false;
						}
					}
				}
			}

			else if((x >= 0) and (x <= 2) and (y >= 3) and (y <= 5)) // Section 2
			{
				for (int a = 0; a < 3; a++)
				{
					for (int b = 3; b < 6; b++)
					{
						int checkNum = game[a][b];
						if ((checkNum == number) and (a != x) and (b != y))
						{
							return false;
						}
					}
				}
			}

			else if((x >= 0) and (x <= 2) and (y >= 6) and (y <= 8)) // Section 3
			{
				for (int a = 0; a < 3; a++)
				{
					for (int b = 6; b < 9; b++)
					{
						int checkNum = game[a][b];
						if ((checkNum == number) and (a != x) and (b != y))
						{
							return false;
						}
					}
				}
			}

			else if((x >= 3) and (x <= 5) and (y >= 0) and (y <= 2)) // Section 4
			{
				for (int a = 3; a < 6; a++)
				{
					for (int b = 0; b < 3; b++)
					{
						int checkNum = game[a][b];
						if ((checkNum == number) and (a != x) and (b != y))
						{
							return false;
						}
					}
				}
			}

			else if((x >= 3) and (x <= 5) and (y >= 3) and (y <= 5)) // Section 5
			{
				for (int a = 3; a < 6; a++)
				{
					for (int b = 3; b < 6; b++)
					{
						int checkNum = game[a][b];
						if ((checkNum == number) and (a != x) and (b != y))
						{
							return false;
						}
					}
				}
			}

			else if((x >= 3) and (x <= 5) and (y >= 6) and (y <= 8)) // Section 6
			{
				for (int a = 3; a < 6; a++)
				{
					for (int b = 6; b < 9; b++)
					{
						int checkNum = game[a][b];
						if ((checkNum == number) and (a != x) and (b != y))
						{
							return false;
						}
					}
				}
			}

			else if((x >= 6) and (x <= 8) and (y >= 0) and (y <= 2)) // Section 7
			{
				for (int a = 6; a < 9; a++)
				{
					for (int b = 0; b < 3; b++)
					{
						int checkNum = game[a][b];
						if ((checkNum == number) and (a != x) and (b != y))
						{
							return false;
						}
					}
				}
			}

			else if((x >= 6) and (x <= 8) and (y >= 3) and (y <= 5)) // Section 8
			{
				for (int a = 6; a < 9; a++)
				{
					for (int b = 3; b < 6; b++)
					{
						int checkNum = game[a][b];
						if ((checkNum == number) and (a != x) and (b != y))
						{
							return false;
						}
					}
				}
			}

			else if((x >= 6) and (x <= 8) and (y >= 6) and (y <= 8)) // Section 9
			{
				for (int a = 6; a < 9; a++)
				{
					for (int b = 6; b < 9; b++)
					{
						int checkNum = game[a][b];
						if ((checkNum == number) and (a != x) and (b != y))
						{
							return false;
						}
					}
				}
			}

			return true;
		}

		bool checkRow(int x, int y)
		// Checks the entire row of a location to see if the number is valid
		{
			x -= 1;
			y -= 1;
			int number = game[x][y];
			for (int b = 0; b < 9; b++)
			{
				toCheck = game[x][b];
				if ((toCheck == number) and (b != y))
				{
					return false;
				}
			}
			return true;
		}

		bool checkCol(int x, int y)
		// Checks the entire column of a location to see if the number is valid
		{
			x -= 1;
			y -= 1;
			int number = game[x][y];
			for (int a = 0; a < 9; a++)
			{
				toCheck = game[a][y];
				if ((toCheck == number) and (a != x))
				{
					return false;
				}
			}
			return true;
		}

		bool checkPuzzle()
		//Using checkRow, checkCol, and checkSection methods to see if the puzzle is complete and valid.
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

		void changeNum(int num, int x, int y)
		//Changes the number at a specific location of the sudoku puzzle
		{
			x -= 1;
			y -= 1;
			game[x][y] = num;
		}

		bool isValid(int x, int y)
		//check the recently entered number to see if it is valid.
		{
			bool col = false, row = false, sec = false;
			col = checkCol(x,y);
			row = checkRow(x,y);
			sec = checkSection(x,y);

			if ((col == false) or (row == false) or (sec == false))
			{
				return false;
			}
			return true;
		}

		void possibleNum(int x, int y)
		{
			bool ONE = false, TWO = false, THREE = false, FOUR = false, FIVE = false, SIX = false, SEVEN = false, EIGHT = false, NINE = false;
			x -= 1;
			y -= 1;
			for (int a = 0; a < 9; a++) // Check row
			{
				int numCheck = game[a][y];
				switch (numCheck)
				{
					case 1 : ONE = true;
							break;
					case 2 : TWO = true;
							break;
					case 3 : THREE = true;
							break;
					case 4 : FOUR = true;
							break;
					case 5 : FIVE = true;
							break;
					case 6 : SIX = true;
							break;
					case 7 : SEVEN = true;
							break;
					case 8 : EIGHT = true;
							break;
					case 9 : NINE = true;
							break;
				}
			}
			for (int b = 0; b < 9; b++) // Check column
			{
				int numCheck = game[x][b];
				switch (numCheck)
				{
					case 1 : ONE = true;
							break;
					case 2 : TWO = true;
							break;
					case 3 : THREE = true;
							break;
					case 4 : FOUR = true;
							break;
					case 5 : FIVE = true;
							break;
					case 6 : SIX = true;
							break;
					case 7 : SEVEN = true;
							break;
					case 8 : EIGHT = true;
							break;
					case 9 : NINE = true;
							break;
				}
			}
			if ((x >= 0) and (x <= 2) and (y >= 0) and (y <= 2)) // Section 1
			{
				for (int a = 0; a < 3; a++)
				{
					for (int b = 0; b < 3; b++)
					{
						int numCheck = game[a][b];
						switch (numCheck)
						{
							case 1 : ONE = true;
									break;
							case 2 : TWO = true;
									break;
							case 3 : THREE = true;
									break;
							case 4 : FOUR = true;
									break;
							case 5 : FIVE = true;
									break;
							case 6 : SIX = true;
									break;
							case 7 : SEVEN = true;
									break;
							case 8 : EIGHT = true;
									break;
							case 9 : NINE = true;
									break;
						}
					}
				}
			}

			else if((x >= 0) and (x <= 2) and (y >= 3) and (y <= 5)) // Section 2
			{
				for (int a = 0; a < 3; a++)
				{
					for (int b = 3; b < 6; b++)
					{
						int numCheck = game[a][b];
						switch (numCheck)
						{
							case 1 : ONE = true;
									break;
							case 2 : TWO = true;
									break;
							case 3 : THREE = true;
									break;
							case 4 : FOUR = true;
									break;
							case 5 : FIVE = true;
									break;
							case 6 : SIX = true;
									break;
							case 7 : SEVEN = true;
									break;
							case 8 : EIGHT = true;
									break;
							case 9 : NINE = true;
									break;
						}
					}
				}
			}

			else if((x >= 0) and (x <= 2) and (y >= 6) and (y <= 8)) // Section 3
			{
				for (int a = 0; a < 3; a++)
				{
					for (int b = 6; b < 9; b++)
					{
						int numCheck = game[a][b];
						switch (numCheck)
						{
							case 1 : ONE = true;
									break;
							case 2 : TWO = true;
									break;
							case 3 : THREE = true;
									break;
							case 4 : FOUR = true;
									break;
							case 5 : FIVE = true;
									break;
							case 6 : SIX = true;
									break;
							case 7 : SEVEN = true;
									break;
							case 8 : EIGHT = true;
									break;
							case 9 : NINE = true;
									break;
						}
					}
				}
			}

			else if((x >= 3) and (x <= 5) and (y >= 0) and (y <= 2)) // Section 4
			{
				for (int a = 3; a < 6; a++)
				{
					for (int b = 0; b < 3; b++)
					{
						int numCheck = game[a][b];
						switch (numCheck)
						{
							case 1 : ONE = true;
									break;
							case 2 : TWO = true;
									break;
							case 3 : THREE = true;
									break;
							case 4 : FOUR = true;
									break;
							case 5 : FIVE = true;
									break;
							case 6 : SIX = true;
									break;
							case 7 : SEVEN = true;
									break;
							case 8 : EIGHT = true;
									break;
							case 9 : NINE = true;
									break;
						}
					}
				}
			}

			else if((x >= 3) and (x <= 5) and (y >= 3) and (y <= 5)) // Section 5
			{
				for (int a = 3; a < 6; a++)
				{
					for (int b = 3; b < 6; b++)
					{
						int numCheck = game[a][b];
						switch (numCheck)
						{
							case 1 : ONE = true;
									break;
							case 2 : TWO = true;
									break;
							case 3 : THREE = true;
									break;
							case 4 : FOUR = true;
									break;
							case 5 : FIVE = true;
									break;
							case 6 : SIX = true;
									break;
							case 7 : SEVEN = true;
									break;
							case 8 : EIGHT = true;
									break;
							case 9 : NINE = true;
									break;
						}

					}
				}
			}

			else if((x >= 3) and (x <= 5) and (y >= 6) and (y <= 8)) // Section 6
			{
				for (int a = 3; a < 6; a++)
				{
					for (int b = 6; b < 9; b++)
					{
						int numCheck = game[a][b];
						switch (numCheck)
						{
							case 1 : ONE = true;
									break;
							case 2 : TWO = true;
									break;
							case 3 : THREE = true;
									break;
							case 4 : FOUR = true;
									break;
							case 5 : FIVE = true;
									break;
							case 6 : SIX = true;
									break;
							case 7 : SEVEN = true;
									break;
							case 8 : EIGHT = true;
									break;
							case 9 : NINE = true;
									break;
						}
					}
				}
			}

			else if((x >= 6) and (x <= 8) and (y >= 0) and (y <= 2)) // Section 7
			{
				for (int a = 6; a < 9; a++)
				{
					for (int b = 0; b < 3; b++)
					{
						int numCheck = game[a][b];
						switch (numCheck)
						{
							case 1 : ONE = true;
									break;
							case 2 : TWO = true;
									break;
							case 3 : THREE = true;
									break;
							case 4 : FOUR = true;
									break;
							case 5 : FIVE = true;
									break;
							case 6 : SIX = true;
									break;
							case 7 : SEVEN = true;
									break;
							case 8 : EIGHT = true;
									break;
							case 9 : NINE = true;
									break;
						}
					}
				}
			}

			else if((x >= 6) and (x <= 8) and (y >= 3) and (y <= 5)) // Section 8
			{
				for (int a = 6; a < 9; a++)
				{
					for (int b = 3; b < 6; b++)
					{
						int numCheck = game[a][b];
						switch (numCheck)
						{
							case 1 : ONE = true;
									break;
							case 2 : TWO = true;
									break;
							case 3 : THREE = true;
									break;
							case 4 : FOUR = true;
									break;
							case 5 : FIVE = true;
									break;
							case 6 : SIX = true;
									break;
							case 7 : SEVEN = true;
									break;
							case 8 : EIGHT = true;
									break;
							case 9 : NINE = true;
									break;
						}
					}
				}
			}

			else if((x >= 6) and (x <= 8) and (y >= 6) and (y <= 8)) // Section 9
			{
				for (int a = 6; a < 9; a++)
				{
					for (int b = 6; b < 9; b++)
					{
						int numCheck = game[a][b];
						switch (numCheck)
						{
							case 1 : ONE = true;
									break;
							case 2 : TWO = true;
									break;
							case 3 : THREE = true;
									break;
							case 4 : FOUR = true;
									break;
							case 5 : FIVE = true;
									break;
							case 6 : SIX = true;
									break;
							case 7 : SEVEN = true;
									break;
							case 8 : EIGHT = true;
									break;
							case 9 : NINE = true;
									break;
						}
					}
				}
			}

			cout << "Potential Numbers for (" << x + 1 << "," << y + 1 << ") are";
			if (ONE == false)
			{
				cout << " 1";
			}
			if (TWO == false)
			{
				cout << " 2";
			}
			if (THREE == false)
			{
				cout << " 3";
			}
			if (FOUR == false)
			{
				cout << " 4";
			}
			if (FIVE == false)
			{
				cout << " 5";
			}
			if (SIX == false)
			{
				cout << " 6";
			}
			if (SEVEN == false)
			{
				cout << " 7";
			}
			if (EIGHT == false)
			{
				cout << " 8";
			}
			if (NINE == false)
			{
				cout << " 9";
			}
			cout << "." << endl;
		}
};
