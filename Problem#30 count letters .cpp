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

short LetterCount(string S1 , char Letter) {

	short Count = 0; 

	for (int i = 0; i < S1.length(); i++) {

		if (S1[i] == Letter)
			Count++;

	}
	 return Count;
}

int main()
{
	string S1 = ReadString();

	char C1 = ReadChar();

	cout << "Letter '" << C1 << "' Count Is : " << LetterCount(S1, C1);

	system("pause>0");
}