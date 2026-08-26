#include <iostream>
#include <string>
#include <iomanip>
#include<cctype>
using namespace std;

string ReadString() {

	string S1;
	cout << "Please Enter A String : \n";
	getline(cin, S1);
	return S1;

}

bool IsVowel(char Letter) {

	Letter = tolower(Letter);

	return ((Letter == 'a') || (Letter == 'o') || (Letter == 'u') || (Letter == 'i')
		|| (Letter == 'e'));
}

void PrintVowles(string S1) {

	cout << "\nVowels in string are : ";

	for (short i = 0; i < S1.length(); i++) {

		if (IsVowel(S1[i]))
			cout << S1[i]<<"   ";

	}

}

int main()
{

	string S1 = ReadString();

	PrintVowles(S1);

	system("pause>0");
}