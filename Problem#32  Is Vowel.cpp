#include <iostream>
#include <string>
#include <iomanip>
#include<cctype>
using namespace std;

char ReadChar() {

	char C1;
	cout << "Please Enter A Character : \n";
	cin >> C1;
	return C1;

}

bool IsVowel(char Letter) {

	Letter = tolower(Letter);

	return ((Letter == 'a') || (Letter == 'e') || (Letter == 'i') || (Letter == 'u')
		|| (Letter == 'o'));

}

int main()
{

	char Letter = ReadChar();

	if (IsVowel(Letter))
		cout << "\nLetter '" << Letter << "' Is Vowel ";
	else 
		cout << "\nLetter '" << Letter << "' Is Not Vowel ";

	system("pause>0");
}