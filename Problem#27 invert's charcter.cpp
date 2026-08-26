#include <iostream>
#include <string>
#include <iomanip>
#include<cctype>
using namespace std;

char ReadChar() {

	char C1;
	cout << "Please enter a charcter : \n";
	cin >> C1;
	return C1;

}

char InvertLetterCase(char C1) {
	
	return isupper(C1) ? tolower(C1) : toupper(C1);

}

int main()
{
	
	char C1 = ReadChar();

	cout << "\nChar after inverting case : \n";
	C1 = InvertLetterCase(C1);
	cout << C1 << endl;

	system("pause>0");
}