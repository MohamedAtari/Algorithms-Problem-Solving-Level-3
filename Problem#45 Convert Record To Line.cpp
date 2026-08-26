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

stClientData ReadNewClient() {

	stClientData Client;

	cout << "\n\n Enter Account Number : ";
	getline(cin, Client.AccountNumber);
	cout << "Enter PinCode : ";
	getline(cin, Client.PinCode);
	cout << "Enter Name : ";
	getline(cin, Client.Name);
	cout << "Enter Phone : ";
	getline(cin, Client.PhoneNumber);
	cout << "Enter AccountBalance : ";
	cin >> Client.AccountBalance;

	return Client;
}

string ConvertRecordToLine(stClientData Client,string Delim = "/##/") {

	string stClientRecord = "";

	stClientRecord += Client.AccountNumber + Delim;
	stClientRecord += Client.PinCode + Delim;
	stClientRecord += Client.Name + Delim;
	stClientRecord += Client.PhoneNumber + Delim;
	stClientRecord += to_string(Client.AccountBalance);

	return stClientRecord;
}

int main()
{

	cout << "Please enter client data: ";

	stClientData ClientData = ReadNewClient(); 

	cout << "\n\nClient Record For Saving Is: \n";
	cout << ConvertRecordToLine(ClientData);

	system("pause>0");
}