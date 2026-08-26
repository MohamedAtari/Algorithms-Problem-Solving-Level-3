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
	bool MarkForDelete = false;

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

vector<sClient>LoadClientsDataFromFile() {

	fstream MyFile;

	vector<sClient>Clients;
	sClient Client;
	string Line = "";

	MyFile.open(FileName, ios::in);

	if (MyFile.is_open()) {

		while (getline(MyFile, Line)) {

			if (Line != "") {
				Client = ConvertLineToRecord(Line);
				Clients.push_back(Client);
			}
		}
		MyFile.close();
	}
	return Clients;
}

bool FindClientByAccountNumber(string AccountNumber,const vector<sClient>&vClients,sClient &Client) {
		
	for (const sClient &C : vClients) {

		if (C.AccountNumber == AccountNumber) {
			Client = C;
			return true;
		}

	}
	return false;
}

void PrintRecord(const sClient& Client) {

	cout << "\nThe Folowing Are The Client Details : \n\n";
	cout << "Account Number  : " << Client.AccountNumber << endl;
	cout << "Pin Code        : " << Client.PinCode << endl;
	cout << "Name            : " << Client.Name << endl;
	cout << "Phone Number    : " << Client.Phone << endl;
	cout << "Account Balance : " << Client.AccountBalance << endl;

}

string ConvertRecortoLine(sClient& Client,string Delim = "#//#") {

	string Line = "";

	Line = Client.AccountNumber + Delim;
	Line += Client.PinCode + Delim;
	Line += Client.Name + Delim;
	Line += Client.Phone + Delim;
	Line += to_string(Client.AccountBalance);

	return Line;
}

void SaveCLientsDataToFile(vector<sClient>& vClients) {

	fstream MyFile;

	MyFile.open(FileName, ios::out);

	if (MyFile.is_open()) {

		for (sClient &Client : vClients) {

			if (!Client.MarkForDelete)
				MyFile << ConvertRecortoLine(Client) << endl;

		}
		MyFile.close();
	}

}

bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector<sClient>& vClients) {

	for (sClient& Client : vClients) {

		if (Client.AccountNumber == AccountNumber) {

			Client.MarkForDelete = true;
			return true;

		}
	}
	return false;

}

bool DeleteClientByAccountNumber(string AccountNumber,vector<sClient>&vClients) {

	sClient Client;
	char Confirm = 'y';

	if (FindClientByAccountNumber(AccountNumber,vClients,Client)) {

		PrintRecord(Client);

		cout << "\nAre You Sure You Want To Delete This Client : y/n \n";
		cin >> Confirm;

		if (toupper(Confirm) == 'Y') {

			MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
			SaveCLientsDataToFile(vClients);

			vClients = LoadClientsDataFromFile();

			cout << "\nClient Deleted Successfuly.\n";
			return true;
		}
		return false;
	}
	else {

		cout << "\nClient With Account Number (" << AccountNumber << ") Is Not Found! \n";
		return false;
	}

}

string ReadClientAccountNumber() {

	string AccountNumber = "";

	cout << "\nPlease Enter Account Number : ";
	cin >> AccountNumber;

	return AccountNumber;
}

int main()
{

	vector<sClient>vClients = LoadClientsDataFromFile();
	string AccountNumber = ReadClientAccountNumber();
	
	DeleteClientByAccountNumber(AccountNumber,vClients);

	system("pause>0");
	return 0;
}