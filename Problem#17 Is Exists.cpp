#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			cout << setw(3) << arr[i][j] << " ";
		}
		cout << "\n";
	}

}

bool IsNumberInMatrix(int Matrix[3][3], short NumberToCheck, short Rows, short Cols) {

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{

			if (NumberToCheck == Matrix[i][j])
				return true;

		}

	}
	return false;
}

	int main()
	{
		int Matrix1[3][3] = { {9,1,12},{0,9,1},{0,9,9} };
		short NumberToCheck;
		cout << "\nMatrix1:\n";
		PrintMatrix(Matrix1, 3, 3);

		cout << "\nPlease enter the number to look for in the matrix : \n";
		cin >> NumberToCheck;

		if (IsNumberInMatrix(Matrix1, NumberToCheck, 3, 3)) {
			cout << "\nYes it's there\n";
		}
		else {
			cout << "\nNo it's not there\n";
		}
		
		system("pause>0");
	}