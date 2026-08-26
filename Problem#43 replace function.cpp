#include <iostream>
#include <string>
#include<cctype>
#include<vector>
using namespace std;

vector<string>SplitString(string S1, string const &Delim) {

	vector<string>vString;
	string Sword = "";
	int pos = 0;

	while ((pos = S1.find(Delim)) != std::string::npos) {

		Sword = S1.substr(0, pos);

		if (Sword != "") {
			vString.push_back(Sword);
		}

		S1.erase(0, pos + Delim.length());
	}

	if (S1 != "")
		vString.push_back(S1);

	return vString;
}

string JoinString(vector<string>&vString,string const &delimeter) {

	if (vString.empty()) return"";

	string S1 = "";

	for (string& s : vString) {

		S1 += s + delimeter;

	}

	return S1.substr(0, S1.length() - delimeter.length());
}

string ToLower(string S1) {

	for (char& c : S1) {
		c = tolower(c);
	}

	return S1;
}

string ReplaceWordInStringUsingSplit(string &S1, string &StringReplaceTo, string &ReplaceTo, bool MatchCase = true) {

	vector<string>vString = SplitString(S1, " ");
	
	for (string& s : vString) {

		if (MatchCase) {

			if (s == StringReplaceTo)
				s = ReplaceTo;

		}
		else {

			if (ToLower(s) == ToLower(StringReplaceTo))
				s = ReplaceTo;

		}

	}
	return JoinString(vString, " ");
}

int main()
{
	string S1 = "Welcome to jordan , jordan is a nice country";
	string StringReplaceTo = "Jordan";
	string ReplaceTo = "Usa";

	cout << "Original String Is : \n";
	cout << S1 << endl;
	
	cout << "\n\nReplace With Match Case  : \n";
	cout << ReplaceWordInStringUsingSplit(S1, StringReplaceTo, ReplaceTo);

	cout << "\n\nReplace With Don't Match Case  : \n";
	cout << ReplaceWordInStringUsingSplit(S1, StringReplaceTo, ReplaceTo , false);

	system("pause>0");
}