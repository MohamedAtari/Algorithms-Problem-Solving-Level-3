#include<iostream>
#include<cstdlib>
#include<iomanip>

using namespace std;

int RandomNumber(int from, int to ) {

	return rand() % (to - from + 1) + from;

}

void FillRandomNumbersIn2DArray(int Array2D[3][3],short Rows,short Cols) {

	for (int i = 0; i < Rows; i++) {

		for (int j = 0; j < Cols; j++) {

			Array2D[i][j] = RandomNumber(1, 100);

		}
	}
}

void Print2DArrayContent(int Array2D[3][3], short Rows, short Cols) {

	for (int i = 0; i < Rows; i++) {

		for (int j = 0; j < Cols; j++) {

			cout <<left<<setw(7)<<Array2D[i][j];

		}
		cout << endl;
	}

}

int main() {

	srand((unsigned)time(NULL));

	int Random33arr[3][3];

	FillRandomNumbersIn2DArray(Random33arr,3,3);
	cout << "The folowing is 3*3 random matrix : \n";
	Print2DArrayContent(Random33arr,3,3);

	system("pause>0");

}