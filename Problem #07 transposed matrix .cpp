#include<iostream>
#include<cstdlib>
#include<iomanip>

using namespace std;

void FillArrayWithOrderdNumbers(int arr[3][3], short Rows, short Cols) {

	int Number = 0;

	for (int i = 0; i < Rows; i++) {

		for (int j = 0; j < Cols; j++) {
			Number++;
			arr[i][j] = Number;
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

void Transpose2DMatrix()