#include<iostream>
#include <string>
#include<fstream>
#include<cctype>
#include<vector>
#include<iomanip>
#include <limits>
using namespace std;

/*===============================================================
              1. GLOBAL CONSTANTS & DATA STRUCTURES
  ===============================================================*/

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

 /*==================================================
                 2. STRING UTLITIS        
   ==================================================*/

vector<string> SplitString(string Line, string Delim) {

	vector<string> vString;
	size_t Pos = 0;

	while ((Pos = Line.find(Delim)) != string::npos) {

		vString.push_back(Line.substr(0, Pos));
		Line.erase(0, Pos + Delim.length());

	}

		vString.push_back(Line);

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

string ConvertRecordToLine(const sClient& Client, string Delim = "#//#") {

	string Line = "";

	Line = Client.AccountNumber + Delim;
	Line += Client.PinCode + Delim;
	Line += Client.Name + Delim;
	Line += Client.Phone + Delim;
	Line += to_string(Client.AccountBalance);

	return Line;
}

/*====================================================
				3. File I/O Operations
  ====================================================*/

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

void AddClientToFile(const sClient& Client) {

	fstream MyFile;

	MyFile.open(ClientsFileName, ios::out | ios::app);

	if (MyFile.is_open()) {

		MyFile << ConvertRecordToLine(Client) << endl;

		MyFile.close();
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

/* ============================================================================
                 4. UI & PRESENTATION , Headers & Tables
   ============================================================================*/

void ShowMainMenuTable() {

	system("cls");
	cout << "=============================================\n";
	cout << "\t\tMain Menu Screen\n";
	cout << "=============================================\n";
	cout << "\t[1] Show Client List.\n";
	cout << "\t[2] Add New Client.\n";
	cout << "\t[3] Delete Client.\n";
	cout << "\t[4] Update Client Info.\n";
	cout << "\t[5] Find Client.\n";
	cout << "\t[6] Exit.\n";
	cout << "=============================================\n";

}

void ShowAddNewClientsScreen() {

	cout << "-------------------------------------\n"; 
	cout << "\tAdd New Client Screen";
	cout << "\n-------------------------------------\n";

}

void ShowDeleteClientScreen() {

	cout << "-------------------------------------\n";
	cout << "\tDelete Client Screen";
	cout << "\n-------------------------------------\n";

}

void ShowUpdateClientInfoScreen() {

	cout << "-------------------------------------\n";
	cout << "\tUpdate Client Info Screen";
	cout << "\n-------------------------------------\n";

}

void ShowFindClientScreen() {

	cout << "-------------------------------------\n";
	cout << "\tFind Client Screen";
	cout << "\n-------------------------------------\n";

}

void ShowExitScreen() {

	cout << "------------------------------------ - \n";
	cout << "\tProgram Ends :-)";
	cout << "\n-------------------------------------\n";

}

void PrintRecord(sClient const& Client) {

	cout << "|" << left << setw(16) << Client.AccountNumber;
	cout << "|" << left << setw(12) << Client.PinCode;
	cout << "|" << left << setw(20) << Client.Name;
	cout << "|" << left << setw(17) << Client.Phone;
	cout << "|" << left << setw(16) << Client.AccountBalance;
	cout << endl;

}

void PrintClientsTable(vector<sClient> const& vClients) {

	cout << "\n\t\t\t\tClients List (" << vClients.size() << ") Client(s).\n\n";
	cout << "--------------------------------------------------------------------------------------\n\n";
	cout << "|" << left << setw(16) << "Account Number";
	cout << "|" << left << setw(12) << "PinCode";
	cout << "|" << left << setw(20) << "Client Name";
	cout << "|" << left << setw(17) << "Phone Number";
	cout << "|" << left << setw(16) << "Account Balance";
	cout << "\n\n--------------------------------------------------------------------------------------\n";

	for (const sClient& Client : vClients) {

		PrintRecord(Client);

	}

	cout << "\n--------------------------------------------------------------------------------------\n\n";

}

void PrintClientDetails(const sClient& Client) {
	cout << "\nThe Following Are The Client Details : ";
	cout << "\n-------------------------------";
	cout << "\nAccount Number  : " << Client.AccountNumber;
	cout << "\nPin Code        : " << Client.PinCode;
	cout << "\nName            : " << Client.Name;
	cout << "\nPhone Number    : " << Client.Phone;
	cout << "\nAccount Balance : " << Client.AccountBalance;
	cout << "\n-------------------------------\n\n";
}

/* ============================================================================
                       5.INPUT & VALIDATION FUNCTIONS
   ============================================================================*/

double ReadAccountBalance() {

	double AccountBalance = 0;

	while (true) {

		cout << "Enter Account Balance ? ";
		cin >> AccountBalance;

		if (!cin.fail() && AccountBalance >= 0) {
			break;
		}

		cout << "\nInvalid Input Please Enter A Number. \n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

	}
	return AccountBalance;
}

short ReadChoice(short From, short To) {

	short Choice = From - 1;

	while (true) {

		cout << "Enter what do you want to do? [" << From << "-" << To << "]? ";
		cin >> Choice;

		if (!cin.fail() && (Choice <= To && Choice >= From)) {
			break;
		}

		cout << "\nInvalid Input Please Enter A Number. \n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

	}
	return Choice;
}

string ReadAccountNumber() {

	string AccountNumber = "";

	cout << "Enter Account Number ? ";
	getline(cin >> ws, AccountNumber);

	return AccountNumber;
}

/* ============================================================================
                      6. CORE BANK LOGIC 
   ============================================================================*/

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

	Client.AccountBalance = ReadAccountBalance();

	return Client;
}

void AddNewClient(vector<sClient> &vClients) {

	sClient Client = ReadNewClient(vClients);
	vClients.push_back(Client);
	AddClientToFile(Client);

}

void AddNewClients(vector<sClient>& vClients) {

	char Confirm = 'n';

	do {

		AddNewClient(vClients);
		cout << "\nDo You Want To Add More Client (y/n) : ";
		cin >> Confirm;

	} while (toupper(Confirm) == 'Y');
	
}

void MarkClientToDeleteByAccountNumber(string AccountNumber,vector<sClient>& vClients) {

	for (sClient& Client : vClients) {

		if (Client.AccountNumber == AccountNumber) {
			Client.MarkToDelete = true;
			break;
		}

	}

}


bool DeleteClientsByAccountNumber(string AccountNumber,vector<sClient>&vClients) {

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

	Client.AccountBalance = ReadAccountBalance();

	return Client;
}

bool UpdateClientByAccountNumber(const string &AccountNumber,vector<sClient>&vClients) {

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

void FindClientByAccountNumberScreen(string AccountNumber,vector<sClient>const&vClints) {

	sClient Client;

	if (FindClientByAccountNumber(AccountNumber, vClints, Client)) {

		PrintClientDetails(Client);
		
	}
	else {

		cout << "\nClient With Account Number (" << AccountNumber << ") Is Not Found! \n";
		
	}

}

/*============================================================================
                        7.CONTROLLERS & ENGINE 
  ============================================================================*/

void GoBackToMainMenu() {

	cout << "\nPress Any Key To Go Back To Main Menu...";
	system("pause>Null");

}

void PerformMainMenuOptions(enMainMenuOptions Option, vector<sClient>& vClients) {

	switch (Option) {

	case enMainMenuOptions::eListClients:

		system("cls");
		PrintClientsTable(vClients);
		GoBackToMainMenu();
		break;

	case enMainMenuOptions::eAddNewClient:

		system("cls");
		ShowAddNewClientsScreen();
		AddNewClients(vClients);
		GoBackToMainMenu();
		break;

	case enMainMenuOptions::eDeleteClient: {
	
		system("cls");
		ShowDeleteClientScreen();
		string AccountNumber = ReadAccountNumber();
		DeleteClientsByAccountNumber(AccountNumber, vClients);
		GoBackToMainMenu();
		break;

	}

	case enMainMenuOptions::eUpdateClient: {

		system("cls");
		ShowUpdateClientInfoScreen();
		string AccountNumber = ReadAccountNumber();
		UpdateClientByAccountNumber(AccountNumber, vClients);
		GoBackToMainMenu();
		break;

	}

	case enMainMenuOptions::eFindClient: {

		system("cls");
		ShowFindClientScreen();
		string AccountNumber = ReadAccountNumber();
		FindClientByAccountNumberScreen(AccountNumber, vClients);
		GoBackToMainMenu();
		break;

	}

	case enMainMenuOptions::eExit:

		system("cls");
		ShowExitScreen();
		break;

	}

}

void StartBankingSystem() {

	vector<sClient>vClients = LoadClientsFromFile();
	short Choice = 0;

	do {

		ShowMainMenuTable();
		Choice = ReadChoice(1,6);
		PerformMainMenuOptions((enMainMenuOptions)Choice, vClients);

	} while (Choice != enMainMenuOptions::eExit);

}

/* ============================================================================
                        8. Main Entry Point
   ============================================================================*/

int main()
{

	StartBankingSystem();

	system("pause>0");
	return 0;
}