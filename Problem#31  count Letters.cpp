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

char ReadChar() {

	char C1;
	cout << "\n\nPlease Enter A Character : \n";
	cin >> C1;
	return C1;

}

char InvertLetterCase(char C1) {

	return isupper(C1) ? tolower(C1) : toupper(C1);

}

short CountLetter(string S1,char Letter,bool MatchCase = true ) {

	short Count = 0;

	for (int i = 0; i < S1.length(); i++) {

		if (MatchCase) {

			if (S1[i] == Letter)
				Count++;

		}
		else {

			if (tolower(S1[i]) == tolower(Letter)) {
				Count++;
			}

		}	

	}
	return Count;
}


int main()
{
	string S1 = ReadString();
	char C1 = ReadChar();

	cout << "Letter '" << C1 << "' Count Is : " << CountLetter(S1, C1) << endl;
	cout << "Letter '" << C1 << "' Or '" << InvertLetterCase(C1) << "' Count Is : " << CountLetter(S1, C1 , false) << endl;


	system("pause>0");
}