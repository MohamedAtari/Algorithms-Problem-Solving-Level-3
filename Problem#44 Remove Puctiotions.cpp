#include<iostream>
#include <string>
#include<cctype>
#include<vector>
using namespace std;

string RemoveAllPunctuations(string S1) {

	string S2 = "";

	for (short i = 0; i < S1.length(); i++) {

		if (!ispunct(S1[i]))
			S2 += S1[i];

	}
	return S2;
}

int main()
{
	
	string S1 = "Welcome to jordan, jordan is a nice country ;it's amazing .";
	
	cout << "Original String:\n";
	cout << S1 << endl;

	cout << "\nPunctuations Removed:\n";
	cout << RemoveAllPunctuations(S1);

	system("pause>0");
}