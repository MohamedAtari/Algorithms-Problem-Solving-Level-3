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

void PrintIntersected(int Matrix1[3][3],int Matrix2[3][3],short Rows,short Cols) {

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{

			if (IsNumberInMatrix(Matrix1,Matrix2[i][j],3,3))
				cout << Matrix2[i][j] << "  ";

		}
		
	}

}

int main()
{
	int Matrix1[3][3] = { {9,1,30},{0,9,1},{0,9,9} };
	short NumberToCheck;

	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix1, 3, 3);

	int Matrix2[3][3] = { {1,2,3},{29,30,31},{30,31,32} };

	cout << "\nMatrix2:\n";
	PrintMatrix(Matrix2, 3, 3);

	cout << "\nIntersected numbers are : \n";
	PrintIntersected(Matrix1, Matrix2, 3, 3);
	
	
	system("pause>0");
}