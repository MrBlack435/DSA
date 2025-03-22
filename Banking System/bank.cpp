#include <iostream>
#include <map>

using namespace std;

// Minimum balance required for withdrawals
#define MIN_BALANCE 500

// Custom exception for insufficient funds
class InsufficientFunds { };

// Account class to manage bank accounts
class Account {
private:
    long accountNumber;
    string firstName;
    string lastName;
    float balance;
    static long nextAccountNumber;

public:
    Account() { }
    Account(string fname, string lname, float balance);

    long getAccountNumber() { return accountNumber; }
    string getFirstName() { return firstName; }
    string getLastName() { return lastName; }
    float getBalance() { return balance; }

    void deposit(float amount);
    void withdraw(float amount);
    
    static void setLastAccountNumber(long accountNumber);
    static long getLastAccountNumber();

    friend ostream& operator<<(ostream& os, Account& acc);
};

// Initialize static variable
long Account::nextAccountNumber = 1000;

// Bank class to manage multiple accounts
class Bank {
private:
    map<long, Account> accounts;

public:
    Account openAccount(string fname, string lname, float balance);
    Account balanceEnquiry(long accountNumber);
    void deposit(long accountNumber, float amount);
    void withdraw(long accountNumber, float amount);
    void closeAccount(long accountNumber);
    void showAllAccounts();
};

// Constructor to initialize an account
Account::Account(string fname, string lname, float balance) {
    nextAccountNumber++;
    accountNumber = nextAccountNumber;
    firstName = fname;
    lastName = lname;
    this->balance = balance;
}

// Deposit money into the account
void Account::deposit(float amount) {
    balance += amount;
}

// Withdraw money with a check for minimum balance
void Account::withdraw(float amount) {
    if (balance - amount < MIN_BALANCE) {
        throw InsufficientFunds();
    }
    balance -= amount;
}

// Getters for account number management
void Account::setLastAccountNumber(long accountNumber) {
    nextAccountNumber = accountNumber;
}
long Account::getLastAccountNumber() {
    return nextAccountNumber;
}

// Overloading << operator for easy display of account details
ostream& operator<<(ostream& os, Account& acc) {
    os << "Account Number: " << acc.getAccountNumber() << endl;
    os << "Name: " << acc.getFirstName() << " " << acc.getLastName() << endl;
    os << "Balance: $" << acc.getBalance() << endl;
    return os;
}

// Open a new account
Account Bank::openAccount(string fname, string lname, float balance) {
    Account acc(fname, lname, balance);
    accounts[acc.getAccountNumber()] = acc;
    cout << "Account Created Successfully!\n" << acc << endl;
    return acc;
}

// Check account balance
Account Bank::balanceEnquiry(long accountNumber) {
    if (accounts.find(accountNumber) == accounts.end()) {
        cout << "Account not found!" << endl;
        return Account();
    }
    return accounts[accountNumber];
}

// Deposit money into a specific account
void Bank::deposit(long accountNumber, float amount) {
    if (accounts.find(accountNumber) == accounts.end()) {
        cout << "Account not found!" << endl;
        return;
    }
    accounts[accountNumber].deposit(amount);
    cout << "Amount Deposited Successfully!" << endl;
    cout << accounts[accountNumber] << endl;
}

// Withdraw money from an account
void Bank::withdraw(long accountNumber, float amount) {
    if (accounts.find(accountNumber) == accounts.end()) {
        cout << "Account not found!" << endl;
        return;
    }
    try {
        accounts[accountNumber].withdraw(amount);
        cout << "Amount Withdrawn Successfully!" << endl;
        cout << accounts[accountNumber] << endl;
    } catch (InsufficientFunds) {
        cout << "Error: Insufficient Funds! Minimum balance of $" << MIN_BALANCE << " required." << endl;
    }
}

// Close an account
void Bank::closeAccount(long accountNumber) {
    if (accounts.find(accountNumber) == accounts.end()) {
        cout << "Account not found!" << endl;
        return;
    }
    accounts.erase(accountNumber);
    cout << "Account Closed Successfully!" << endl;
}

// Show all accounts
void Bank::showAllAccounts() {
    if (accounts.empty()) {
        cout << "No accounts found!" << endl;
        return;
    }
    for (auto& acc : accounts) {
        cout << acc.second << endl;
    }
}

// Main function for user interaction
int main() {
    Bank bank;
    int choice;
    string fname, lname;
    long accountNumber;
    float balance, amount;

    cout << "*** Welcome to Simple Bank System ***\n";

    do {
        cout << "\nChoose an option:\n";
        cout << "1. Open an Account\n";
        cout << "2. Balance Enquiry\n";
        cout << "3. Deposit Money\n";
        cout << "4. Withdraw Money\n";
        cout << "5. Close an Account\n";
        cout << "6. Show All Accounts\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter First Name: ";
                cin >> fname;
                cout << "Enter Last Name: ";
                cin >> lname;
                cout << "Enter Initial Balance: ";
                cin >> balance;
                bank.openAccount(fname, lname, balance);
                break;

            case 2:
                cout << "Enter Account Number: ";
                cin >> accountNumber;
                cout << bank.balanceEnquiry(accountNumber) << endl;
                break;

            case 3:
                cout << "Enter Account Number: ";
                cin >> accountNumber;
                cout << "Enter Amount: ";
                cin >> amount;
                bank.deposit(accountNumber, amount);
                break;

            case 4:
                cout << "Enter Account Number: ";
                cin >> accountNumber;
                cout << "Enter Amount: ";
                cin >> amount;
                bank.withdraw(accountNumber, amount);
                break;

            case 5:
                cout << "Enter Account Number: ";
                cin >> accountNumber;
                bank.closeAccount(accountNumber);
                break;

            case 6:
                bank.showAllAccounts();
                break;

            case 7:
                cout << "Thank you for using Simple Bank System. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice! Please enter a valid option.\n";
        }
    } while (choice != 7);

    return 0;
}
