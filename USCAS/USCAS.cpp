//Scientific Software Solutions Capital Account System Server
//Copyright 2022, Scientific Software Solutions, Inc.

#include <iostream>;
#include <vector>;
#include <regex>;
#include <string>;
using namespace std;

const string sourcePassword = "0";

class account {
	public:
		unsigned long long int accountNumber;
		unsigned long long int balance;
		string password;
};
vector<account> accounts;

unsigned long long int createAccount(string password) {
	account standardAccount{};
	standardAccount.balance = 0;
	standardAccount.password = password;
	standardAccount.accountNumber = accounts.size();
	accounts.push_back(standardAccount);
	return accounts.size()-1;
}

bool transact(unsigned long long int account1, unsigned long long int amount, unsigned long long int account2, string password) {
	if (accounts[account1].balance >= amount && amount <= 1000000000000000 && accounts[account2].balance <= 18000000000000000000 && accounts[account1].password == password) {
		accounts[account1].balance -= amount;
		accounts[account2].balance += amount;
		return true;
	}
	else {
		return false;
	}
}

unsigned long long int balance(unsigned long long int account, string password) {
	if (accounts[account].password == password) {
		return accounts[account].balance;
	}
	else {
		return 0;
	}
}

int main() {
	bool createAccountBool = false;
	unsigned long long int balanceAccount = 0;
	string balancePassword;
	bool balanceBool = false;
	unsigned long long int transactionAccount1 = 0;
	unsigned long long int transactionAmount = 0;
	unsigned long long int transactionAccount2 = 0;
	string transactPassword;;
	bool transactBool = false;
	unsigned long long int balanceOutput = 0;
	unsigned long long int createAccountOutput = 0;
	bool transactOutput = false;
	string newAccountPassword = "";
	string createAccountBoolStr = "";
	string balanceAccountStr = "";
	string balanceBoolStr = "";
	string transactionAccount1Str = "";
	string transactionAmountStr = "";
	string transactionAccount2Str = "";
	string transactBoolStr = "";
    cout << "Scientific Software Solutions Capital Account System\n";
	cout << "Copyright 2022, Scientific Software Solutions, Inc.\n";
	account sourceAccount{};
	sourceAccount.accountNumber = 0;
	sourceAccount.balance = 18420000000000000000;
	sourceAccount.password = sourcePassword;
	accounts.push_back(sourceAccount);
	while (true) {
		accounts[0].balance = 18420000000000000000;
		cout << "New Account password:";
		cin >> newAccountPassword;
		cout << "Create account? (0/1):";
		cin >> createAccountBoolStr;
		cout << "Account to check balance:";
		cin >> balanceAccountStr;
		cout << "Password for account to check balance:";
		cin >> balancePassword;
		cout << "Check balance? (0/1):";
		cin >> balanceBoolStr;
		cout << "Account to transfer from:";
		cin >> transactionAccount1Str;
		cout << "Amount to transfer:";
		cin >> transactionAmountStr;
		cout << "Account to transfer to:";
		cin >> transactionAccount2Str;
		cout << "Password for account to transact:";
		cin >> transactPassword;
		cout << "Transact? (0/1):";
		cin >> transactBoolStr;
		string createAccountBoolStrx = regex_replace(createAccountBoolStr, regex(R"([\D])"), "0");
		createAccountBool = stoull(createAccountBoolStrx);
		string balanceAccountStrx = regex_replace(balanceAccountStr, regex(R"([\D])"), "0");
		balanceAccount = stoull(balanceAccountStrx);
		string balanceBoolStrx = regex_replace(balanceBoolStr, regex(R"([\D])"), "0");
		balanceBool = stoull(balanceBoolStrx);
		string transactionAccount1Strx = regex_replace(transactionAccount1Str, regex(R"([\D])"), "0");
		transactionAccount1 = stoull(transactionAccount1Strx);
		string transactionAmountStrx = regex_replace(transactionAmountStr, regex(R"([\D])"), "0");
		transactionAmount = stoull(transactionAmountStrx);
		string transactionAccount2Strx = regex_replace(transactionAccount2Str, regex(R"([\D])"), "0");
		transactionAccount2 = stoull(transactionAccount2Strx);
		string transactBoolStrx = regex_replace(transactBoolStr, regex(R"([\D])"), "0");
		transactBool = stoull(transactBoolStrx);
		if (createAccountBool == true) {
			createAccountOutput = createAccount(newAccountPassword);
		}
		if (balanceBool == true) {
			balanceOutput = balance(balanceAccount, balancePassword);
		}
		if (transactBool == true) {
			transactOutput = transact(transactionAccount1, transactionAmount, transactionAccount2, transactPassword);
		}
		cout << "Account created:" << createAccountOutput << endl;
		cout << "Account balance:" << balanceOutput << endl;
		cout << "Transaction status (0/1):" << transactOutput << endl;
		createAccountOutput = 0;
		balanceOutput = 0;
		transactOutput = 0;
		cout << "-" << endl;
	}
}