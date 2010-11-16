#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void printGame(int arg[][9]);
bool checkGame(int arg[][9]);

int main()
{
	int line = 0, col = 0, A = 0, B = 0, C = 0, D = 0, E = 0, F = 0, G = 0, H = 0, I = 0;
	int game[9][9];
	bool gameFinished = false;

	ifstream file;
	file.open("sudokuFalse.txt");
	for (line = 0; line < 9; line++)
	{
		file >> A >> B >> C >> D >> E >> F >> G >> H >> I;
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

	printGame(game);

	gameFinished = checkGame(game);

	if (gameFinished == true)
	{
		cout << "Game Over, good job!" << endl;
	}
	else if (gameFinished == false)
	{
		cout << "Something is wrong with your sudoku game." << endl;
	}

	return 0;
}

void printGame(int arg[][9])
{
	for (int a = 0; a < 9; a++)
	{
		for (int b = 0; b < 9; b++)
		{
			cout << arg[a][b] << " ";
		}
		cout << endl;
	}
}

bool checkGame(int arg[][9])
{
	bool checkGame = false, doneCheck = false;
	int numToCheck = 0, nextCheck = 1;
	for (int a = 0; a < 9; a++)
	{
		for (int b = 0; b < 9; b++)
		{
			numToCheck = arg[a][b];
			while (doneCheck == false)
			{
				int divCheck = numToCheck / nextCheck;
				int modCheck = numToCheck % nextCheck;

				if ((divCheck == 1) and (modCheck == 0))
				{
					doneCheck = true;
				}
				else
				{
					nextCheck++;
				}
			}
		}
	}

	for (int a = 0; a < 9; a++)
	{
		for (int b = 0; b < 9; b++)
		{
			numToCheck = arg[b][a];
			while (doneCheck == false)
			{
				int divCheck = numToCheck / nextCheck;
				int modCheck = numToCheck % nextCheck;

				if ((divCheck == 1) and (modCheck == 0))
				{
					doneCheck = true;
				}
				else
				{
					nextCheck++;
				}
			}
		}
	}

	if (doneCheck == true)
	{
		checkGame = true;
	}
	return checkGame;
}
