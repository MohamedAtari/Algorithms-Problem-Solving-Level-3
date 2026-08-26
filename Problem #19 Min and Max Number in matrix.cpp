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

short MinNumberInMatrix(int Matrix[3][3], short Rows, short Cols) {

	short MinNumber = Matrix[0][0];

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (MinNumber > Matrix[i][j])
				MinNumber = Matrix[i][j];

		}
	    
	}
	return MinNumber;
}

short MaxNumberInMatrix(int Matrix[3][3], short Rows, short Cols) {

	short MaxNumber = Matrix[0][0];

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (MaxNumber < Matrix[i][j])
				MaxNumber = Matrix[i][j];
		}
		
	}
	return MaxNumber;
}

int main()
{
	int Matrix1[3][3] = { {9,1,30},{0,9,1},{0,9,9} };
	short NumberToCheck;

	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix1, 3, 3);

	cout << "\nMinimum Number in matrix is : " << MinNumberInMatrix(Matrix1, 3, 3) << endl;

	cout << "\nMax Number in the matrix is : " << MaxNumberInMatrix(Matrix1, 3, 3) << endl;

	system("pause>0");
}