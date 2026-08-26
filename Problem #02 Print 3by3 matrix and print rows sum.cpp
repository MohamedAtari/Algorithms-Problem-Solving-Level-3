#include<iostream>
#include<cstdlib>
#include<iomanip>

using namespace std;

short RandomNumber(short From, short To) {
	return rand() % (To - From + 1) + From;
}

void Fill2DArrayWithRandomNumber(int Array[3][3], short Rows, short Cols) {

	for (int RowsNumber = 0; RowsNumber < Rows; RowsNumber++) {

		for (int ColsNumber = 0; ColsNumber < Cols; ColsNumber++) {

			Array[RowsNumber][ColsNumber] = RandomNumber(1, 100);

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

int RowSum(int arr[3][3], short RowNumber, short Cols) {

	int Sum = 0;
	for (int i = 0; i < Cols; i++) {
		Sum += arr[RowNumber][i];
	}
	return Sum;
}

void PrintEachRowSum(int arr[3][3], short Rows, short Cols) {

	for (int i = 0; i < Rows; i++) {
		cout << "Row " << i + 1 << " Sum = " << RowSum(arr, i, Cols) << endl;
	}
	
}

int main() {

	srand((unsigned)time(NULL));

	int Array[3][3];

	Fill2DArrayWithRandomNumber(Array, 3, 3);
	cout << "The folowing is 3by3 random matrix: \n";
	Print2DArray(Array, 3, 3);

	cout << "\nThe folowing is the the sum of each row in the matrix: \n";
	PrintEachRowSum(Array, 3, 3);

	return 0;
}