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

sClient ConvertLineToRecord(string Line, string Delim = "#//#") {

	sClient Client;

	vector<string>vLine = SplitString(Line, Delim);

	if (vLine.size() >= 5) {


		Client.AccountNumber = vLine[0];
		Client.PinCode = vLine[1];
		Client.Name = vLine[2];
		Client.Phone = vLine[3];
		Client.AccountBalance = stod(vLine[4]);

	}
	return Client;
}

vector<sClient>LoadCLientsDataFromFile() {

	fstream MyFile;
	vector<sClient>vClients;
	sClient Client;
	string Line = "";

	MyFile.open(FileName, ios::in);

	if (MyFile.is_open()) {

		while (getline(MyFile, Line)) {

			if (Line != "") {

				Client = ConvertLineToRecord(Line);
				vClients.push_back(Client);

			}

		}
		MyFile.close();
	}
	return vClients;
}

void PrintRecord(const sClient& Client) {

	cout << "\nThe Folowing Are The Client Details : \n\n";
	cout << "Account Number  : " << Client.AccountNumber << endl;
	cout << "Pin Code        : " << Client.PinCode << endl;
	cout << "Name            : " << Client.Name << endl;
	cout << "Phone Number    : " << Client.Phone << endl;
	cout << "Account Balance : " << Client.AccountBalance << endl;

}

bool FindClientByAccountNumber(string AccountNumber, vector<sClient>& vClients, sClient& Client) {

	for ( sClient& C : vClients) {

		if (C.AccountNumber == AccountNumber) {

			Client = C;			
			return true;

		}

	}
	return false;
}

sClient ChangeClientRecord(string AccountNumber) {

	sClient Client;

	Client.AccountNumber = AccountNumber;

	cout << "\n\nEnter PinCode? ";
	getline(cin >> ws, Client.PinCode);

	cout << "\nEnter Name? ";
	getline(cin, Client.Name);

	cout << "\nEnter Phone? ";
	getline(cin, Client.Phone);

	cout << "\nEnter Account Balance? ";
	cin >> Client.AccountBalance;

	return Client;
}

string ConvertRecortoLine(sClient& Client, string Delim = "#//#") {

	string Line = "";

	Line = Client.AccountNumber + Delim;
	Line += Client.PinCode + Delim;
	Line += Client.Name + Delim;
	Line += Client.Phone + Delim;
	Line += to_string(Client.AccountBalance);

	return Line;
}

void SaveClientsToFile(vector<sClient>&vClients) {

	fstream MyFile;

	MyFile.open(FileName, ios::out);

	if (MyFile.is_open()) {

		for (sClient &Client : vClients) {

			MyFile << ConvertRecortoLine(Client) << endl;

		}

		MyFile.close();
	}

}

bool UpdateClientByAccountNumber(vector<sClient>&vClients,string AccountNumber) {

	sClient Client;
	char Confirm = 'n';

	if (FindClientByAccountNumber(AccountNumber, vClients, Client)) {

		PrintRecord(Client);
		
		cout << "\n\nAre You Sure You Want Update This Client : ";
		cin >> Confirm;

		if (toupper(Confirm) == 'Y') {

			for (sClient& Client : vClients) {

				if (Client.AccountNumber == AccountNumber) {
					Client = ChangeClientRecord(AccountNumber);
					break;
				}

			}

			SaveClientsToFile(vClients);

			cout << "\n\nClinet Updated Successfully";

			return true;
		}
		return false;
	}
	else {

		cout << "\nClient With Account Number (" << AccountNumber << ") Not Found!";
		return false;
	}

}

string ReadAccountNumber() {

	string AccountNumber;

	cout << "Pleasee Enter Account Number : ";
	cin >> AccountNumber;

	return AccountNumber;
}

int main()
{

	vector<sClient>vClients = LoadCLientsDataFromFile();
	string AccountNumber = ReadAccountNumber();

	UpdateClientByAccountNumber(vClients,AccountNumber);

	system("pause>0");
	return 0;
}