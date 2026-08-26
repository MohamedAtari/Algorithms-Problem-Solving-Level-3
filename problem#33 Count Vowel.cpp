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

short CountVowel(string S1) {

	short Count = 0;

	for (short i = 0; i < S1.length(); i++) {

		if (IsVowel(S1[i]))
			Count++;

	}
	return Count;
}

int main()
{

	string S1 = ReadString();

	cout << "\nVowel Letters Number Is : " << CountVowel(S1) << endl;

	system("pause>0");
}