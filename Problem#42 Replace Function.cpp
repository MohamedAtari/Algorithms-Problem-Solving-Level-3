#include <iostream>
#include <string>
#include <iomanip>
#include<cctype>
#include<vector>
using namespace std;

string ReplaceWordInStringUsingBuiltInFunction(string S1,string StringToReplace , string ReplaceTo) {

	short pos = S1.find(StringToReplace);

	while (pos != std::string::npos) {

		S1.replace(pos, StringToReplace.length(), ReplaceTo);
		pos = S1.find(StringToReplace);

	}
	return S1;
}

int main()
{
	string S1 = "Welcome to jordan , jordan is a nice country";
	string StringReplaceTo = "jordan";
	string ReplaceTo = "Usa";

	cout << "Original String Is : \n";
	cout << S1 << endl;

	cout << "String After Replace : \n";
	cout << ReplaceWordInStringUsingBuiltInFunction(S1,StringReplaceTo,ReplaceTo);

	system("pause>0");
}