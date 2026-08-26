#include<iostream>
#include <string>
#include<fstream>
#include<cctype>
#include<vector>
#include<iomanip>
using namespace std;

const string FileName = "Client.txt";

struct sClient
{
	string AccountNumber = "";
	string PinCode = "";
	string Name = "";
	string Phone = "";
	double AccountBalance = 0;

};

vector<string>SplitString(string S1, string Delim) {

	vector<string>vString;
	string sWord = "";
	size_t pos = 0;

	while ((pos = S1.find(Delim)) != std::string::npos) {

		sWord = S1.substr(0, pos);
		vString.push_back(sWord);
		S1.erase(0, pos + Delim.length());

	}

	if (S1 != "")
		vString.push_back(S1);


	return vString;
}

sClient ConvertLineToRecord(const string &Line, string Delim = "#//#") {

	sClient Client;

	vector<string>vClientData = SplitString(Line, Delim);

	if (vClientData.size() >= 5) {

		Client.AccountNumber = vClientData[0];
		Client.PinCode = vClientData[1];
		Client.Name = vClientData[2];
		Client.Phone = vClientData[3];
		Client.AccountBalance = stod(vClientData[4]);

	}

	return Client;
}

vector<sClient>LoadClientsFromFile() {

	fstream MyFile;
	vector<sClient>vClients;

	string Line = "";

	MyFile.open(FileName, ios::in);

	if (MyFile.is_open()) {

		while (getline(MyFile, Line)) {

			if (Line != "") {

				sClient Client = ConvertLineToRecord(Line);
				vClients.push_back(Client);

			}

		}
		MyFile.close();
	}
	return vClients;
}

void PrintRecord(const sClient &Client) {

	cout << "Account Number  : " << Client.AccountNumber << endl;
	cout << "Pin Code        : " << Client.PinCode << endl;
	cout << "Name            : " << Client.Name << endl;
	cout << "Phone Number    : " << Client.Phone << endl;
	cout << "Account Balance : " << Client.AccountBalance << endl;

}

bool FindClientByAccountNumber(string &AccountNumber,sClient &Client) {

	vector<sClient>vClients = LoadClientsFromFile();

	for (const sClient &C : vClients) {

		if (C.AccountNumber == AccountNumber) {
			Client = C;
			return true;
		}

	}
	return false;
}

string ReadClientNumber() {

	string AccountNumber = "";

	cout << "Please Enter Client Number : ";
	cin >> AccountNumber;

	return AccountNumber;
}

int main()
{

	string AccountNumber = ReadClientNumber();
	sClient Client;

	if (FindClientByAccountNumber(AccountNumber,Client)) {

		cout << "\nThe Folowing Are The Client Details : \n\n";
		PrintRecord(Client);

	}
	else {

		cout << "\nClient With Account Number (" << AccountNumber << ") Is Not Found! \n";

	}

	system("pause>0");
	return 0;
}