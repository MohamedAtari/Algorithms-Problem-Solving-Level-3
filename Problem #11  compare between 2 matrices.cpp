#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int RandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;

}

void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			arr[i][j] = RandomNumber(1, 10);
		}
	}
}

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			printf("%0*d   ", 2, arr[i][j]);

		}
		cout << "\n";
	}
}

short SumOfMatrix(int Matrix[3][3], short Rows, short Cols) {

	short Sum = 0;

	for (int i = 0; i < Rows; i++) {

		for (int j = 0; j < Cols; j++) {
			Sum += Matrix[i][j];
		}

	}
	return Sum;
}

bool AreEqualMatrices(int Matrix1[3][3],int Matrix2[3][3], short Rows, short Cols) {

	return (SumOfMatrix(Matrix1, 3, 3) == SumOfMatrix(Matrix2, 3, 3));

}

int main() {

	srand((unsigned)time(NULL));

	int Matrix1[3][3],Matrix2[3][3];

	FillMatrixWithRandomNumbers(Matrix1, 3, 3);
	cout << "Matrix  1 : \n";
	PrintMatrix(Matrix1, 3, 3);

	FillMatrixWithRandomNumbers(Matrix2, 3, 3);
	cout << "\nMatrix 2 : \n";
	PrintMatrix(Matrix2, 3, 3);

	if (AreEqualMatrices(Matrix1, Matrix2, 3, 3)) {
		cout << "\nYes : Matrices are equal";
	}
	else {
		cout << "\nNo : Matrices are not equal";
	}

	system("pause>0");
}