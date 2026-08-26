#include<iostream>
#include<cstdlib>
#include<iomanip>

using namespace std;

short RandomNumber(short Min, short Max) {

	return rand() % (Max - Min + 1) + Min;

}

void FillArrayWithRandomNumber(int arr[3][3], short Rows, short Cols) {

	for (int i = 0; i < Rows; i++) {

		for (int j = 0; j < Cols; j++) {
			arr[i][j] = RandomNumber(1, 100);
		}

	}

}

void Print2DArray(int arr[3][3], short Rows, short Cols) {

	for (int i = 0; i < Rows; i++) {

		for (int j = 0; j < Cols; j++) {
			cout << left << setw(7) << arr[i][j];
		}
		cout << endl;
	}

}

short RowSum(int arr[3][3], short RowNumber, short Cols) {

	short SumOfRow = 0;

	for (short i = 0; i < Cols; i++) {
		SumOfRow += arr[RowNumber][i];
	}
	return SumOfRow;
}

void FillSumMatrixRowsIn1DArray(int arr[3][3], int SumOfRows[3], short Rows, short Cols) {

	for (int i = 0; i < Rows; i++) {
		SumOfRows[i] = RowSum(arr, i, Cols);
	}

}

void PrintRowsSumArray(int SumOfRows[],short Rows) {

	cout << "\nThe folowing are the sum of each row in the matrix :\n";

	for (int i = 0; i < 3; i++) {
		cout << "Row " << i + 1 << " Sum = " << SumOfRows[i] << endl;
	}

}

int main() {

	srand((unsigned)time(NULL));

	int RandomNumbersArr[3][3], SumOfRows[3];

	FillArrayWithRandomNumber(RandomNumbersArr, 3, 3);
	cout << "The folowing is a 3*3 random matrix : \n";
	Print2DArray(RandomNumbersArr,3,3);

	FillSumMatrixRowsIn1DArray(RandomNumbersArr, SumOfRows,3,3);
	
	PrintRowsSumArray(SumOfRows,3);

	return 0;
}