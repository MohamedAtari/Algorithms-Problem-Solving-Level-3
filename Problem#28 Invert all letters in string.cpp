#include <iostream>
#include <string>
#include <iomanip>
#include<cctype>
using namespace std;

string ReadString() {

	string S1;
	cout << "Please enter youe string : \n";
	getline(cin, S1);
	return S1;

}

char InvertLetterCase(char char1) {

	return isupper(char1) ? tolower(char1) : toupper(char1);

}

string InvertAllLettersCase(string s1) {

	for (int i = 0; i < s1.length(); i++) {
		s1[i] = InvertLetterCase(s1[i]);
	}
	return s1;
}

int main()
{

	string s1 = ReadString();

	cout << "\nString after invert all letters : \n";
	s1 = InvertAllLettersCase(s1);
	cout << s1 << endl;

	system("pause>0");
}