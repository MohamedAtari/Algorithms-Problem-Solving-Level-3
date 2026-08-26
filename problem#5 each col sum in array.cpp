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

void Print2DArray(int Array[3][3], short Rows, short Cols) {

	for (int RowsNumber = 0; RowsNumber < Rows; RowsNumber++) {

		for (int ColsNumber = 0; ColsNumber < Cols; ColsNumber++) {

			cout << left << setw(7) << Array[RowsNumber][ColsNumber];

		}
		cout << "\n";
	}

}

short ColSum(int arr[3][3], short Rows, short ColNumber) {

	int SumOfCols = 0;

	for (int i = 0; i < Rows; i++) {
		SumOfCols += arr[i][ColNumber];
	}
	return SumOfCols;
}

void FillColsSumIn1DArray(int arr[3][3],int array[], short Rows,short Cols) {

	for (int i = 0; i < Cols; i++) {
		array[i] = ColSum(arr, Rows, i);
	}

}

void PrintColsSumArray(int arr[],short Cols) {

	cout << "\nThe flowing are the sum of each col in the matrix :\n";

	for (int i = 0; i < Cols; i++) {
		cout << "Cols " << i + 1 << " Sum = " << arr[i] << endl;
	}

}

int main() {

	srand((unsigned)time(NULL));

	int RandomNumberArr[3][3], ColsSumArr[3];

	FillArrayWithRandomNumber(RandomNumberArr, 3, 3);
	cout << "The folowing is a 3*3 matrix : \n";
	Print2DArray(RandomNumberArr, 3, 3);

	FillColsSumIn1DArray(RandomNumberArr, ColsSumArr, 3, 3);
	
	PrintColsSumArray(ColsSumArr, 3);

	system("pause>0");
}