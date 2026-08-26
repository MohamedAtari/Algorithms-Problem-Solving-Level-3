#include<iostream>
#include <string>
#include<fstream>
#include<cctype>
using namespace std;

const string FileName = "Client.txt";

struct stClientData {

	string AccountNumber = "";
	string PinCode = "";
	string Name = "";
	string PhoneNumber = "";
	double AccountBalance = 0;

};

stClientData ReadNewClient(stClientData Client) {

	cout << "Enter Account Number? ";
	getline(cin >> ws, Client.AccountNumber);

	cout << "Enter PinCode? ";
	getline(cin, Client.PinCode);
	
	cout << "Enter Name? ";
	getline(cin, Client.Name);

	cout << "Enter Phone? ";
	getline(cin, Client.PhoneNumber);

	cout << "Enter Account Balance? ";
	cin >> Client.AccountBalance;

	return Client;
}

string ConvertRecordToLine(stClientData Client, string Seperator =
	"#//#")
{
	string stClientRecord = "";
	stClientRecord += Client.AccountNumber + Seperator;
	stClientRecord += Client.PinCode + Seperator;
	stClientRecord += Client.Name + Seperator;
	stClientRecord += Client.PhoneNumber + Seperator;
	stClientRecord += to_string(Client.AccountBalance);
	return stClientRecord;
}

void LoadDataLineToFile(string FileName, string Line) {

	fstream MyFile;

	MyFile.open(FileName, ios::out | ios::app);

	if (MyFile.is_open()) {

		MyFile << Line << endl;

		MyFile.close();
	}

}

void AddNewClient() {

	stClientData Client;
	Client = ReadNewClient(Client);
	LoadDataLineToFile(FileName, ConvertRecordToLine(Client));

}

void AddClients() {

	char AddMore = 'y';

	do {

		system("cls");
		cout << "Adding New Client: \n\n";

		AddNewClient();
		cout << "\nClient Added Successfully, do you want to add more clients? ";
		cin >> AddMore;

	} while (toupper(AddMore) == 'Y');

}

int main()
{
	
	AddClients();

	system("pause>0");
	return 0;
}