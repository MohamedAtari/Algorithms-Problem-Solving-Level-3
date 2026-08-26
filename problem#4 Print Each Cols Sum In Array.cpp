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

short ColSum(int Array[3][3], short Rows, short ColNumber) {

	short Sum = 0;

	for (short i = 0; i < Rows; i++) {

		Sum += Array[i][ColNumber];

	}
	return Sum;
}

void PrintEachColsSum(int Array[3][3], short Rows, short Cols) {

	cout << "\nThe flowing are the sum of each col in the matrix :\n";

	for (short i = 0; i < Cols; i++) {

		cout << "Col " << i + 1 << " Sum = " << ColSum(Array, Rows, i)<<endl;

	}

}

int main() {

	srand((unsigned)time(NULL));

	int RandomNumber2DArr[3][3];

	FillArrayWithRandomNumber(RandomNumber2DArr,3,3);
	cout << "The folowing is a 3*3 matrix : \n";
	Print2DArray(RandomNumber2DArr, 3, 3);

	PrintEachColsSum(RandomNumber2DArr, 3, 3);

	return 0;
}