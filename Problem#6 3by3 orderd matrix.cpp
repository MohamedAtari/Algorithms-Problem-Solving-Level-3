#include<iostream>
#include<cstdlib>
#include<iomanip>

using namespace std;

void FillArrayWithOrderdNumbers(int Array[3][3], short Rows,short Cols) {

	int Number = 1;

	for (int i = 0; i < Rows; i++) {

		for (int j = 0; j < Cols; j++) {

			Array[i][j] = Number;
			Number++;
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

void Print2DArray(int Array[3][3], short Rows, short Cols) {

	for (int RowsNumber = 0; RowsNumber < Rows; RowsNumber++) {

		for (int ColsNumber = 0; ColsNumber < Cols; ColsNumber++) {

			cout << left << setw(7) << Array[RowsNumber][ColsNumber];

		}
		cout << "\n";
	}

}

int main() {

	srand((unsigned)time(NULL));



	system("pause>0");
}
