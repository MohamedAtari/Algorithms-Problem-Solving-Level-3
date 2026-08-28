#include<iostream>
#include <string>
#include<fstream>
#include<cctype>
#include<vector>
#include<iomanip>
using namespace std;

const string ClientsFileName = "Client.txt";

enum enMainMenuOptions {

	eListClients = 1,
	eAddNewClient = 2,
	eDeleteClient = 3,
	eUpdateClient = 4,
	eFindClient = 5,
	eExit = 6

};

struct sClient {

	string AccountNumber = "";
	string PinCode = "";
	string Name = "";
	string Phone = "";
	double AccountBalance = 0;
	bool MarkToDelete = false;

};

string ReadAccountNumber() {

	string AccountNumber = "";

	cout << "Enter Account Number ? ";
	getline(cin >> ws, AccountNumber);

	return AccountNumber;
}

vector<string>SplitString(string Line,string Delim) {

	vector<string>vString;
	string sWord = "";
	size_t Pos = 0;

	while ((Pos = Line.find(Delim)) != std::string::npos) {

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

void ShowAddNewClientsScreen() {

	cout << "\n-------------------------------------\n"; 
	cout << "\tAdd New Client Screen";
	cout << "\n-------------------------------------\n";

}

void ShowDeleteClientScreen() {

	cout << "\n-------------------------------------\n";
	cout << "\tDelete Client Screen";
	cout << "\n-------------------------------------\n";

}

void ShowUpdateClientInfoScreen() {

	cout << "\n-------------------------------------\n";
	cout << "\tUpdate Client Info Screen";
	cout << "\n-------------------------------------\n";

}

void ShowFindClientScreen() {

	cout << "\n-------------------------------------\n";
	cout << "\tFind Client Screen";
	cout << "\n-------------------------------------\n";

}

void ShowExitScreen() {

	cout << "\n-------------------------------------\n";
	cout << "\tProgram Ends :-)";
	cout << "\n-------------------------------------\n";

}

void PrintRecord(sClient const &Client) {

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

bool FindClientByAccountNumber(string AccountNumber,vector<sClient>const &vClients ,sClient &Client) {

	for (const sClient& C : vClients) {

		if (C.AccountNumber == AccountNumber) {
			Client = C;
			return true;
		}

	}
	
	return false;
}

sClient ReadNewClient(vector<sClient>const& vClients) {

	sClient Client;
	sClient TempClient;

	Client.AccountNumber = ReadAccountNumber();

	while (FindClientByAccountNumber(Client.AccountNumber,vClients,TempClient)) {

		cout << "\nClient With [" << Client.AccountNumber << "] Already Exists, Enter Anthor Account Number : ";
		getline(cin>>ws, Client.AccountNumber);

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
	Line += to_string(Client.AccountBalance);

	return Line;
}

void AddClientToFile(sClient &Client) {

	fstream MyFile;
	
	MyFile.open(ClientsFileName, ios::out | ios::app);

	if (MyFile.is_open()) {

		MyFile << ConvertRecordToLine(Client) << endl;
		
		MyFile.close();
	}

}

void AddNewClient(vector<sClient> &vClients) {

	sClient Client = ReadNewClient(vClients);
	vClients.push_back(Client);
	AddClientToFile(Client);

}

void AddNewClients(vector<sClient>& vClients) {

	ShowAddNewClientsScreen();

	char Confirm = 'n';

	do {

		AddNewClient(vClients);
		cout << "\nDo You Want To Add More Client (y/n) : ";
		cin >> Confirm;

	} while (toupper(Confirm) == 'Y');
	
}

//Delete Clients

void PrintClientDetails(const sClient &Client) {

	cout << "\nThe Folowing Are The Clients Details : ";
	cout << "\n-------------------------------";
	cout << "\nAccount Number  : " << Client.AccountNumber;
	cout << "\nPin Code        : " << Client.PinCode;
	cout << "\nName            : " << Client.Name;
	cout << "\nPhone Number    : " << Client.Phone;
	cout << "\nAccount Balance : " << Client.AccountBalance;
	cout << "\n-------------------------------\n\n";

}

void MarkClientToDeleteByAccountNumber(string AccountNumber,vector<sClient>& vClients) {

	for (sClient& Client : vClients) {

		if (Client.AccountNumber == AccountNumber) {
			Client.MarkToDelete = true;
			break;
		}

	}

}

void SaveClientsToFile(vector<sClient>& vClients) {

	fstream MyFile;

	MyFile.open(ClientsFileName, ios::out);

	if (MyFile.is_open()) {

		for (sClient& Client : vClients) {

			if (!Client.MarkToDelete) {
				MyFile << ConvertRecordToLine(Client) << endl;
			}

		}
		MyFile.close();
	}

}

bool DeleteClientsByAccountNumber(string AccountNumber,vector<sClient>&vClients) {

	ShowDeleteClientScreen();

	sClient Client;
	char Confirm = 'n';

	if (FindClientByAccountNumber(AccountNumber, vClients, Client)) {

		PrintClientDetails(Client);

		cout << "\nAre You Sure You Want To Delete This Client (y/n) : ";
		cin >> Confirm;

		if (toupper(Confirm) == 'Y') {

			MarkClientToDeleteByAccountNumber(AccountNumber, vClients);
			SaveClientsToFile(vClients);

			vClients = LoadClientsFromFile();

			cout << "\n\nClient Deleted Successfully. \n\n";

			return true;
		}
		return false;
	}
	else {

		cout << "\nClient With Account Number (" << AccountNumber << ") Is Not Found! \n";
		return false;

	}

}

sClient ChangeClientRecord(string AccountNumber) {

	sClient Client;

	Client.AccountNumber = AccountNumber;

	cout << "\n\nEnter PinCode ? ";
	getline(cin >> ws, Client.PinCode);

	cout << "Enter Name ? ";
	getline(cin, Client.Name);

	cout << "Enter Phone Numebr ? ";
	getline(cin, Client.Phone);

	cout << "Enter Account Balance ? ";
	cin >> Client.AccountBalance;

	return Client;
}

bool UpdateClientByAccountNumber(const string &AccountNumber,vector<sClient>&vClients) {

	ShowUpdateClientInfoScreen();

	sClient Client;
	char Confirm = 'y';

	if (FindClientByAccountNumber(AccountNumber, vClients, Client)) {

		PrintClientDetails(Client);

		cout << "Are You Sure You Want To Update This Client ? (y/n) : ";
		cin >> Confirm;

		if (toupper(Confirm) == 'Y') {

			for (sClient& C : vClients) {

				if (C.AccountNumber == AccountNumber) {

					C = ChangeClientRecord(AccountNumber);
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

		cout << "\nClient With Account Number (" << AccountNumber << ") Is Not Found! \n";
		return false;

	}

}

void FindClientByAccountNumberScreen(vector<sClient>const&vClints) {

	ShowFindClientScreen();

	sClient Client;
	string AccountNumber = ReadAccountNumber();

	if (FindClientByAccountNumber(AccountNumber, vClints, Client)) {

		PrintClientDetails(Client);
		
	}
	else {

		cout << "\nClient With Account Number (" << AccountNumber << ") Is Not Found! \n";
		
	}

}

void ShowMainMenu() {

	cout << "=====================================\n";
	cout << "\t\tMain Menu Screen\n";
	cout << "=====================================\n";
	cout << "\t[1] Show Client List.\n";
	cout << "\t[2] Add New Client List.\n";
	cout << "\t[3] Delete Client.\n";
	cout << "\t[4] Update Client Info.\n";
	cout << "\t[5] Find Client.\n";
	cout << "\t[6] Exit.\n";
	cout << "=====================================\n";

}

int main()
{

	system("pause>0");
	return 0;
}