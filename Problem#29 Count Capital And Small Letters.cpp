#include <iostream>
#include <string>
#include <iomanip>
#include<cctype>
using namespace std;

enum enWhatCount {SmallLetters = 0 , CapitalLetters = 1 , AllLetters = 2};

short CountLetters(string s1 , enWhatCount WhatCount) {

	short Count = 0;

	if (WhatCount == enWhatCount::AllLetters)
		return s1.length();

	for (int i = 0; i < s1.length(); i++)
	{

		if (WhatCount == enWhatCount::CapitalLetters && isupper(s1[i]))
			Count++;
		
		if (WhatCount == enWhatCount::SmallLetters && islower(s1[i]))
			Count++;

	}
	return Count;
}

string ReadString() {

	string S1;
	cout << "Please enter youe string : \n";
	getline(cin, S1);
	return S1;

}

short CountCapitalLetters(string s1) {
	
	short CountCapitalLetters = 0;

	for (int i = 0; i < s1.length(); i++) {
		
		if (isupper(s1[i])) {
			CountCapitalLetters++;
		}

	}
	return CountCapitalLetters;
}

short CountSmallLetters(string s1) {

	short CountLowerLetters = 0;

	for (int i = 0; i < s1.length(); i++) {

		if (islower(s1[i])) {
			CountLowerLetters++;
		}

	}
	return CountLowerLetters;
}

int main()
{
	string S1 = ReadString();

	cout << "\nString Length : " << CountLetters(S1,enWhatCount::AllLetters) << endl;
	cout << "Capital Letters Count : " << CountLetters(S1,enWhatCount::CapitalLetters) << endl;
	cout << "Small Letters Count : " << CountLetters(S1, enWhatCount::SmallLetters) << endl;



	system("pause>0");
}