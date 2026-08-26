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
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;

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

sClient ConvertLineToRecord(string& Line, string Delim = "#//#") {

	vector<string>vString = SplitString(Line, Delim);

	sClient ClientData;

	ClientData.AccountNumber = vString[0];
	ClientData.PinCode = vString[1];
	ClientData.Name = vString[2];
	ClientData.Phone = vString[3];
	ClientData.AccountBalance = stod(vString[4]);

	return ClientData;
}

vector<sClient>LoadClientsFromFile() {

	fstream MyFile;

	MyFile.open(FileName, ios::in);

	vector<sClient>vClients;
	sClient Client;
	string Line = "";

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

void PrintClientRecord(sClient Client)
{
	cout << "| " << setw(15) << left << Client.AccountNumber;
	cout << "| " << setw(10) << left << Client.PinCode;
	cout << "| " << setw(40) << left << Client.Name;
	cout << "| " << setw(12) << left << Client.Phone;
	cout << "| " << setw(12) << left << Client.AccountBalance;
}

void PrintAllClientsData(vector <sClient> vClients)
{
	cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") "<<"Clinets(s)."
		"\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;

	cout << "| " << left << setw(15) << "Accout Number";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "Phone";
	cout << "| " << left << setw(12) << "Balance";
	cout <<
		"\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
	for (sClient Client : vClients)
	{
		PrintClientRecord(Client);
		cout << endl;
	}
	cout <<
		"\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
}

int main()
{

	vector<sClient>vClients = LoadClientsFromFile();

	PrintAllClientsData(vClients);

	system("pause>0");
	return 0;
}