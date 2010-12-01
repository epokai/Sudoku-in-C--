#include <cstdlib>
#include <iostream>
#include <time.h>

using namespace std;

bool checkCol(int array[][9], int row, int col);
bool checkRow(int array[][9], int row, int col);
bool checkSection(int array[][9], int x, int y);

int main()
{
	srand ( time(NULL) );
	int thisNum = 0, prevNum = 0, someNum;
	int array [9][9];

	for (int a = 0; a < 9; a++)
	{
		for (int b = 0; b < 9; b++)
		{
			array[a][b] = 0;
		}
	}

	cout << "9 x 9 array of Zeros initialized" << endl;

	array[0][0] = rand() % 9 + 1;

	cout << "First Number (x0) initialized." << endl;

	bool runWhile = true;
	bool checkingRow = false;
	bool checkingCol = false;
	bool checkingSec = false;

	// Generates the first row.
	for (int b = 1; b < 9; b++)
	{
		do
		{
			array[0][b] = rand() % 9 + 1;

			checkingRow = checkRow(array,0,b);

			if (checkingRow == true)
			{
				runWhile = false;
			}
			else if (checkingRow == false)
			{
				runWhile = true;
			}
		} while (runWhile);
	}

	cout << "First Row initialized!" << endl;

	for (int a = 1; a < 3; a++)
	{
		for (int b = 0; b < 9; b++)
		{
			cout << "in the for//\n";
			int iter = 0;
			do
			{

				array[a][b] = rand() % 9 + 1;

				cout << array[a][b] << "|";

				checkingRow = checkRow(array,a,b);
				checkingCol = checkCol(array,a,b);
				checkingSec = checkSection(array,a,b);

				switch (checkingRow)
				{
					case true : cout << " row : true |";
								break;
					case false : cout << " row : false |";
								break;
				}
				switch (checkingCol)
				{
					case true : cout << " col : true |";
								break;
					case false : cout << " col : false ";
								break;
				}

				switch (checkingSec)
				{
					case true : cout << " sec : true |";
								break;
					case false : cout << " sec : false |";
								break;
				}

				cout << iter << " iterations for (" << a << "," << b << ")" << endl;

				if ((checkingRow == true) and (checkingCol == true) and (checkingSec == true))
				{
					runWhile = false;
				}
				else if ((checkingRow == false) or (checkingCol == false) or (checkingSec == false))
				{
					iter++;
					runWhile = true;
				}

				// Printing out our array
				for (int a = 0; a < 9; a++)
				{
					for (int b = 0; b < 9; b++)
					{
						cout << array[a][b] << " ";
					}
					cout << endl;
				}
			} while (runWhile);
		}
	}

	cout << "\n\n" << endl;

	// Printing out our array
	for (int a = 0; a < 9; a++)
	{
		for (int b = 0; b < 9; b++)
		{
			cout << array[a][b] << " ";
		}
		cout << endl;
	}

	return 0;
}

bool checkCol(int array[][9], int row, int col)
// Checks the entire column of a location to see if the number is valid
{
	int number = array[row][col];
	for (int a = 0; a < 9; a++)
	{
		int toCheck = array[a][col];
		if ((toCheck == number) and (a != row))
		{
			return false;
		}
	}
	return true;
}

bool checkRow(int array[][9], int row, int col)
// Checks the entire row of a location to see if the number is valid
{
	int number = array[row][col];
	for (int b = 0; b < 9; b++)
	{
		int toCheck = array[row][b];
		if ((toCheck == number) and (b != col))
		{
			return false;
		}
	}
	return true;
}

bool checkSection(int array[][9], int x, int y)
// Given a location we check a specific section for the validity of the number
{
	//Sections
	//1 2 3
	//4 5 6
	//7 8 9

	int number = array[x][y];

	if ((x >= 0) and (x <= 2) and (y >= 0) and (y <= 2)) // Section 1
	{
		for (int a = 0; a < 3; a++)
		{
			for (int b = 0; b < 3; b++)
			{
				int checkNum = array[a][b];
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
				int checkNum = array[a][b];
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
				int checkNum = array[a][b];
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
				int checkNum = array[a][b];
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
				int checkNum = array[a][b];
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
				int checkNum = array[a][b];
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
				int checkNum = array[a][b];
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
				int checkNum = array[a][b];
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
				int checkNum = array[a][b];
				if ((checkNum == number) and (a != x) and (b != y))
				{
					return false;
				}
			}
		}
	}

	return true;
}
