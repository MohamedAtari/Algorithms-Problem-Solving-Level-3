#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			cout << setw(3) << arr[i][j] << " ";
		}
		cout << "\n";
	}

}

bool IsPalendrome(int Matrix[3][3], short Rows, short Cols) {

	for (int i = 0; i < Rows; i++) {

		for (int j = 0; j < Cols / 2; j++) {

			if (Matrix[i][j] != Matrix[i][Cols - 1 - j])
				return false;

		}

	}
	return true;
}

int main()
{
	int Matrix1[3][3] = { {1,3,1},{2,5,2},{1,3,1} };
	short NumberToCheck;

	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix1, 3, 3);

	if (IsPalendrome(Matrix1, 3, 3)) {
		cout << "\nYes : it's palendrom matrix\n";
	}
	else {
		cout << "\nNo : it's palendrom matrix\n";
	}

	system("pause>0");
}