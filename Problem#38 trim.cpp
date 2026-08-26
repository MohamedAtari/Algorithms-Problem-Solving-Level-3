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

string TrimLeft(string S1) {

	for (int i = 0; i < S1.length(); i++) {

		if (S1[i] != ' ')
			return S1.substr(i, S1.length() - i);
		
	}
	return "";
}

string TrimRight(string S1) {

	for (int i = S1.length() - 1; i >= 0; i--) 
	{
		if (S1[i] != ' ')
			return  S1.substr(0, i + 1);

	}
	return "";
}
 
string TrimAll(string S1) {

	return TrimLeft(TrimRight(S1));

} 

int main()
{

	string S1 = ReadString();

	cout << "String : " << S1 << endl;
	cout << "Term Left : " << TrimLeft(S1) << endl;
	cout << "Term Right : " << TrimRight(S1) << endl;
	cout << "Term All : " << TrimAll(S1) << endl;

	system("pause>0");
}