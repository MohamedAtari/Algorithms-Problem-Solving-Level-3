#include <iostream>
#include <string>
#include <iomanip>
#include<cctype>
#include<vector>
using namespace std;

string JoinString(vector<string> vString, string Delim) {

	string S1 = "";

	for (string& s : vString) {

		S1 += s + Delim;

	}

	return S1.substr(0, S1.length() - Delim.length());
}

string JoinString(string arr[], short length, string Delim) {

	string S1 = "";

	for (short i = 0; i < length; i++) {
		S1 += arr[i] + Delim;
	}
	return S1.substr(0, S1.length() - Delim.length());
}

int main()
{
	vector<string> vString = {"Mohamed","Dania", "Ayla","Noah" };
	string arr[] = { "Mohamed","Dania", "Ayla","Noah" };
	
	cout << "vector after join : \n";
	cout << JoinString(vString," ") << endl;

	cout << "\nstring after join : \n";
	cout << JoinString(arr, 4, " ") << endl;;

	system("pause>0");
}