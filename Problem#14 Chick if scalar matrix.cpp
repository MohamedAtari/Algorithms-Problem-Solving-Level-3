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

bool IsScalarMatrix(int Matrix[3][3], short Rows, short Cols) {

	short FirstDigitInDigonal = Matrix[0][0];

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			
			if (i != j && Matrix[i][j] != 0) {

				return false;

			}
			else if (i == j && Matrix[i][j] != FirstDigitInDigonal) {
				
				return false;

			}

		}
		
	}
	return true;
}

int main()
{
	int Matrix[3][3] = { {2,0,0},{0,18,0},{0,0,4} };
	cout << "\nMatrix:\n";
	PrintMatrix(Matrix, 3, 3);
	
	if (IsScalarMatrix(Matrix,3,3)) {
		cout << "\nYes : it's scalar matrix \n";
	}
	else {
		cout << "\nNo : it's not scalar matrix \n";
	}

	system("pause>0");
}