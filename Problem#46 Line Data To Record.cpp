#include<iostream>
#include <string>
#include<cctype>
#include<vector>
using namespace std;

struct stClientData {

	string AccountNumber = "";
	string PinCode = "";
	string Name = "";
	string PhoneNumber = "";
	double AccountBalance = 0;

};

vector<string>SplitString(string S1, string Delim) {

	vector<string>vString;
	string sWord = "";
	short pos = 0;

	while ((pos = S1.find(Delim)) != std::string::npos) {

		sWord = S1.substr(0, pos);

		if (sWord != "")
			vString.push_back(sWord);

		S1.erase(0, pos + Delim.length());

	}

	if (S1 != "")
		vString.push_back(S1);


	return vString;
}

stClientData ConvertLineToRecord(string &Line, string Delim = "#//#") {

	vector<string>vString = SplitString(Line, Delim);

	stClientData ClientData;

	ClientData.AccountNumber = vString[0];
	ClientData.PinCode = vString[1];
	ClientData.Name = vString[2];
	ClientData.PhoneNumber = vString[3];
	ClientData.AccountBalance = stod(vString[4]);

	return ClientData;
}

void PrintClientRecord(stClientData Client)
{
	cout << "\n\nThe following is the extracted client record:\n";
	cout << "\nAccout Number: " << Client.AccountNumber;
	cout << "\nPin Code : " << Client.PinCode;
	cout << "\nName : " << Client.Name;
	cout << "\nPhone : " << Client.PhoneNumber;
	cout << "\nAccount Balance: " << Client.AccountBalance;

}

int main()
{
	string stLine = "A150#//#1234#//#Mohamed Atari#//#079999#//#32700000";
	stClientData Client = ConvertLineToRecord(stLine);

	cout << "\nLine Record is:\n";
	cout << stLine;

	PrintClientRecord(Client);

	system("pause>0");
	return 0;
}