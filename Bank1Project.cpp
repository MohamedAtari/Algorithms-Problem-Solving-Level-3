#include<iostream>
#include <string>
#include<fstream>
#include<cctype>
#include<vector>
#include<iomanip>
using namespace std;

const string ClientsFileName = "Client.txt";

struct sClient {

	string AccountNumber = "";
	string PinCode = "";
	string Name = "";
	string Phone = "";
	double AccountBalance = 0;

};

vector<string>SplitString(string Line,string Delim) {

	vector<string>vString;
	string sWord = "";
	size_t Pos = 0;

	while ((Pos == Line.find(Delim)) != std::string::npos) {

		sWord = Line.substr(0, Pos);

		if (sWord != "") {
			vString.push_back(sWord);
		}

		Line.erase(0, Pos + Delim.length());
	}

	if (Line != "") {
		vString.push_back(Line);
	}

	return vString;
}

sClient ConvertLineToRecord(string Line,string Delim = "#//#") {

	sClient Client;

	vector<string>vClientData = SplitString(Line,Delim);

	if (vClientData.size()>=5) {

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
	sClient Client;
	string Line = "";

	MyFile.open(ClientsFileName, ios::in);

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

void PrintRecord(sClient Client) {

	cout << "|" << left << setw(15) << Client.AccountNumber;
	cout << "|" << left << setw(10) << Client.PinCode;
	cout << "|" << left << setw(40) << Client.Name;
	cout << "|" << left << setw(15) << Client.Phone;
	cout << "|" << left << setw(12) << Client.AccountBalance;
	cout << endl;

}

void PrintClientsTable(vector<sClient> const& vClients) {

	cout << "\n\t\t\t\tClients List (" << vClients.size() << ") Client(s).\n\n";
	cout << "---------------------------------------------------------------------------------------------\n\n";
	cout << "|" << left << setw(15) << " Account Number ";
	cout << "|" << left << setw(10) << " PinCode";
	cout << "|" << left << setw(40) << " Client Name";
	cout << "|" << left << setw(15) << " Phone Number";
	cout << "|" << left << setw(12) << " Account Balance";
	cout << "\n\n---------------------------------------------------------------------------------------------\n\n";

	for (const sClient& Client : vClients) {

		PrintRecord(Client);

	}

	cout << "\n\n---------------------------------------------------------------------------------------------\n\n";

}
//Add Clinets

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

sClient ConvertLineToRecord(string Line , string Delim = "#//#") {

	sClient Client;

	vector<string>vClient = SplitString(Line, Delim);

	if (vClient.size() >= 5) {
	
		Client.AccountNumber = vClient[0];
		Client.PinCode = vClient[1];
		Client.Name = vClient[2];
		Client.Phone = vClient[3];
		Client.AccountBalance = stod(vClient[4]);

	}

	return Client;
}

bool FindClientByAccountNumber(string AccountNumber) {

	vector<sClient>vClients = LoadClientsFromFile();

	for (const sClient& C : vClients) {

		if (C.AccountNumber == AccountNumber)
			return true;

	}
	
	return false;
}

sClient ReadNewClient() {

	sClient Client;

	
	cout << "Enter Account Number ? ";
	getline(cin >> ws,Client.AccountNumber);

	while (FindClientByAccountNumber(Client.AccountNumber)) {

		cout << "\nClient With [" << Client.AccountNumber << "] Already Exists, Enter Anthor Account Number : ";
		getline(cin, Client.AccountNumber);

	}

	cout << "Enter PinCode ? ";
	getline(cin, Client.PinCode);

	cout << "Enter Name ? ";
	getline(cin, Client.Name);

	cout << "Enter Phone Number ? ";
	getline(cin, Client.Phone);

	cout << "Enter Account Balance ? ";
	cin >> Client.AccountBalance;

	return Client;
}

string ConvertRecordToLine(sClient &Client,string Delim = "#//#") {

	string Line = "";

	Line = Client.AccountNumber + Delim;
	Line += Client.PinCode + Delim;
	Line += Client.Name + Delim;
	Line += Client.Phone + Delim;
	Line += to_string(Client.AccountBalance) + Delim;

	return Line;
}

void AddClientToFile(sClient Client) {

	fstream MyFile;
	
	MyFile.open(ClientsFileName, ios::out | ios::app);

	if (MyFile.is_open()) {

		MyFile << ConvertRecordToLine(Client) << endl;
		
		MyFile.close();
	}

}

void AddNewClient() {

	sClient Client = ReadNewClient();
	AddClientToFile(Client);

}

void AddNewClients() {

	char Confirm = 'n';

	do {

		AddNewClient();
		cout << "\nDo You Want To Add More Client (y/n) : ";
		cin >> Confirm;

	} while (toupper(Confirm) == 'Y');
	
}

int main()
{

	

	system("pause>0");
	return 0;
}