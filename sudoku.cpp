#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

//void checkBlock(string);

int main()
{
	int A = 0, B = 0, C = 0, D = 0, E = 0, F = 0, G = 0, H = 0, I = 0, sum = 0;
	string sdf = "sudoku.txt";
	//cout << "Enter the sdf file> " << endl;
	//cin >> sdf;

	if (sdf == "")
	{
		cout << "end" << endl;
	}
	else
	{
		ifstream sdfRead;
		sdfRead.open("sudoku.txt");
		for (int line = 1; line < 10; line++)
		{
			sdfRead >> A >> B >> C >> D >> E >> F >> G >> H >> I;
			for (int y = 0; y < 9; y++)
			{
				for (int z = 0; z < 9; z++)
				{
					game[y][z] = A;
				}
			}

			sum = A + B + C + D + E + F + G + H + I;
			cout << sum << endl;
		}
		if (sum == 45)
		{
			cout << "true" << endl;
		}
		sdfRead.close();
	}
	int game[9][9];
	for (int y = 0; y < 9; y++)
	{
		for (int z = 0; z < 9; z++)
		{
			cout << game[y][z] << endl;
		}
	}
	return 0;
}
