#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void PrintFibonacciUsingLoop(int NumberOfSeries) {

	int FibNumber = 0;
	int Prev2 = 0, Prev1 = 1;
	cout << "1   ";
	for (int i = 2; i <= NumberOfSeries; i++) {

		FibNumber = Prev1 + Prev2;
		cout << FibNumber << "   ";

		Prev2 = Prev1;
		Prev1 = FibNumber;
		FibNumber = Prev1 + Prev2;
	}

}

int main()
{

	PrintFibonacciUsingLoop(22);

	system("pause>0");
}