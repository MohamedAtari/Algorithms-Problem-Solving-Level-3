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

void Transpose2DMatrix(int Array[3][3],int TransposedArray[3][3], short Rows, short Cols) {

	for (int i = 0; i < Rows; i++) {

		for (int j = 0; j < Cols; j++) {

			TransposedArray[i][j] =  Array[j][i];

		}
	
	}

}

int main() {

	int Array[3][3],TransposedArray[3][3];

	FillArrayWithOrderdNumbers(Array, 3, 3);
	cout << "The folowing is a 3*3 matrix\n";
	Print2DArray(Array, 3, 3);

	Transpose2DMatrix(Array,TransposedArray ,3, 3);
	cout << "\nThe folowing is the transposed matrix\n";
	Print2DArray(TransposedArray, 3, 3);

	system("pause>0");
}