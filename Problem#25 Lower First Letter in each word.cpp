#include <iostream>
#include <string>
#include <iomanip>
#include<cctype>
using namespace std;

string LowerFirstLettersOfEachWord(string S1) {

	bool IsFirstLetter = true;

	for (int i = 0; i < S1.length(); i++) {

		if (S1[i] != ' ' && IsFirstLetter) {
			S1[i] = tolower(S1[i]);
		}

		IsFirstLetter = (S1[i] == ' ');

	}
	return S1;
}

string ReadString() {

	string S1;
	cout << "Please enter youe string : \n";
	getline(cin, S1);
	return S1;

}

int main()
{

	string S1 = ReadString();

	S1 = LowerFirstLettersOfEachWord(S1);

	cout << "\nString after conversion : \n";
	cout << S1;

	system("pause>0");
}