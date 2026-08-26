#include <iostream>
#include <string>
#include <iomanip>
#include<cctype>
#include<vector>
using namespace std;

string ReadString() {

	string S1;
	cout << "Please Enter A String : \n";
	getline(cin, S1);
	return S1;

}

vector<string> SplitString(string S1,string delim) {

	vector<string>Words;
	short pos = 0;
	string Sword;

	while ((pos = S1.find(delim)) != std::string::npos) {

		Sword = S1.substr(0, pos);
		if (Sword != " ") {

			Words.push_back(Sword);

		}

		S1.erase(0, pos + delim.length());

	}

	if (S1 != "") {

		Words.push_back(S1);

	}

	return Words;
}

int main()
{

	vector<string>vString;
	string S1 = ReadString();

	vString = SplitString(S1, " ");

	cout << "Tokens = " << vString.size() << endl;

	for (string& s : vString) {

		cout << s << endl;

	}

	system("pause>0");
}