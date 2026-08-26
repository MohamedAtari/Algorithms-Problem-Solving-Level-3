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

void PrintEachWordInString(string S1) {

	string delim = " ";
	short pos = 0;
	string Sword;

	while ((pos = S1.find(delim)) != std::string::npos) {

		Sword = S1.substr(0, pos);

		if (Sword != " ") {

			cout << Sword << endl;

		}

		S1.erase(0, pos + delim.length());

	}

	if (S1 != " ") {

		cout << S1 << endl;

	}

}

int main()
{

	PrintEachWordInString(ReadString());

	system("pause>0");
}