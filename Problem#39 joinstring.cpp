#include <iostream>
#include <string>
#include <iomanip>
#include<cctype>
#include<vector>
using namespace std;

string JoinString(vector<string>vString, string delimeter) {

	string S1 = "";

	for (string &s : vString) {

		S1 = S1 + s + delimeter;

	}

	return S1.substr(0,S1.length() - delimeter.length());
}

int main()
{

	vector<string>vString = { "Mohamed","Dania","Ayla","Noah" };

	string S1 = JoinString(vString," , ");

	cout << S1 << endl;

	system("pause>0");
}