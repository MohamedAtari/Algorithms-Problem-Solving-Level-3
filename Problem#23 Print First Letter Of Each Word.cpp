#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

string ReadString() {

	string Statement;

	cout << "Please enter your string : \n";
	getline(cin, Statement);

	return Statement;
}

void PrintFirstLetterOfEachWord(string Statement) {

	cout << "\nFirst Letters Of Each Word Is :\n";

	bool IsFirstLetter = true;

	for (int i = 0; i < Statement.length(); i++) {

		if (Statement[i] != ' ' && IsFirstLetter) {
			cout << Statement[i] << endl;
		}
		IsFirstLetter = (Statement[i] == ' ');
	}

}

int main()
{

	PrintFirstLetterOfEachWord(ReadString());
	
	system("pause>0");
}