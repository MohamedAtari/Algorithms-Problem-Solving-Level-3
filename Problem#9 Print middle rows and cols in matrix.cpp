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

void PrintMiddleRowOfMatrix(int Matrix[3][3], short Rows, short Cols) {

	short MiddleRows = Rows / 2;

	for (int i = 0; i < Cols; i++) {
		printf("%0*d   ", 2, Matrix[MiddleRows][Cols]);
	}

}

void PrintMiddleColOfMatrix(int Matrix[3][3], short Rows, short Cols) {

	short MiddleCols = Cols / 2;

	for (int i = 0; i < Rows; i++) {
		printf("%0*d   ", 2, Matrix[i][MiddleCols]);
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

int main() {

	srand((unsigned)time(NULL));

	int Matrix[3][3];

	FillMatrixWithRandomNumbers(Matrix, 3, 3);

	cout << "Matrix 1 :\n";
	PrintMatrix(Matrix, 3, 3);

	cout << "\nThe middle Row :\n";
	PrintMiddleRowOfMatrix(Matrix, 3,3);

	cout << "\n\nThe middle Col :\n";
	PrintMiddleColOfMatrix(Matrix, 3,3);

	system("pause>0");
}