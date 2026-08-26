#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void PrintFibonacciUsingRecursion(short Number , short Prev1,short Prev2) {

	short FibNumber = 0;

	if (Number > 0) {

		FibNumber = Prev1 + Prev2;

		cout << FibNumber << "   ";

		Prev2 = Prev1;
		Prev1 = FibNumber;
		PrintFibonacciUsingRecursion(Number - 1, Prev1, Prev2);
	}

}

int main()
{

	PrintFibonacciUsingRecursion(10,0,1);

	system("pause>0");
}