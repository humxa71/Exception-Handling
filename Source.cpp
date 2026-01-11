#include <iostream>
#include <string>
using namespace std;
class BankAccount {
private:
	string name;
	double balance;
public:
	BankAccount(string n, double b):name(n),balance(b) {
		cout << "Constructor called!" << endl;
			if (b < 0) {
				throw "Initial balance cannot be negative!";
			}
		
	}
	void withdraw(double amount) {
		if (amount > balance) {
			throw "Not enough balance";
		}
		balance = balance - amount;
		cout << "Remaining balance: " << balance << endl;
	}
	~BankAccount() {
		cout << "Destructor called for " << name << endl;
	}
};
int main() {
	BankAccount* account = nullptr;
	try {
		account = new BankAccount("Hamza", 4500);
		account->withdraw(1500);
		delete account;
	}
	catch (const char* msg) {
		cout << "Error: " << msg << endl;
		delete account;
	}
	cout << "Program ended safely!" << endl;
	return 0;
}