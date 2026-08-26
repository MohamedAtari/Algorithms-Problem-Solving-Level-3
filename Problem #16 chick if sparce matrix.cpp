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

short CountNumberInMatrix(int Matrix1[3][3], int Number, short
	Rows, short Cols)
{
	short NumberCount = 0;
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix1[i][j] == Number)
			{
				NumberCount++;
			}
		}
	}
	return NumberCount;
}

bool IsSparceMatrix(int Matrix[3][3], short Rows, short Cols) {

	short MatrixSize = Rows * Cols;

	return (CountNumberInMatrix(Matrix, 0, 3, 3) > MatrixSize/2);

}

int main()
{
	int Matrix[3][3] = { {0,0,0},{1,2,3},{0,9,9} };
	cout << "\n  Matrix:\n";
	PrintMatrix(Matrix, 3, 3);
	
	if (IsSparceMatrix(Matrix, 3, 3)) {
		cout << "\nYes : it's sparce matrix \n";
	}
	else {
		cout << "\nNo : it' not sparce matrix \n";
	}

	system("pause>0");
}