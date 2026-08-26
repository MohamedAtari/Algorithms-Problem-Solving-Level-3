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

short CountWords(string S1) {


	string delim = " ",Sword;
	short pos = 0, count = 0;

	while ((pos = S1.find(delim)) != std::string::npos) {

		Sword = S1.substr(0, pos);

		if (Sword != " ") {
			count++;
		}

		S1.erase(0, pos + delim.length());

	}

	if (S1 != "") {
		count++;
	}

	return count;
}

int main()
{

	string S1 = ReadString();

	cout << "\n\nThe Number Of Each Word In String Is : " << CountWords(S1) << endl;

	system("pause>0");
}