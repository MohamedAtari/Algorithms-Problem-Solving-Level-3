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

vector<string>SplitString(string S1,string Delim) {

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

string ReverseString(string S1) {

	vector<string>vString;
	string S2 = " ";
	
	vString = SplitString(S1, " ");

	vector<string>::iterator iter = vString.end();

	while (iter != vString.begin()) {

		iter--;

		S2 += *iter + " ";

	}
	return S2.substr(0, S2.length() - 1);
}

int main()
{
	
	string S1 = ReadString();

	cout << "\nString After Reverse : \n";
	cout << ReverseString(S1);

	system("pause>0");
}