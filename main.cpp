#include <iostream>
#include <vector>
using namespace std;

// Class representing a bank account
class Account {
public:
    int accountNumber;  // Unique account number
    string name;        // Account holder's name
    double balance;     // Current account balance

    // Constructor to initialize an account
    Account(int accNo, string accName, double accBalance) {
        accountNumber = accNo;
        name = accName;
        balance = accBalance;
    }

    // Function to deposit money into the account
    void deposit(double amount) {
        balance += amount;
        cout << "Deposit successful. New balance: " << balance << endl;
    }

    // Function to withdraw money from the account
    bool withdraw(double amount) {
        if (amount > balance) { // Check if the balance is sufficient
            cout << "Insufficient balance!" << endl;
            return false;
        }
        balance -= amount;
        cout << "Withdrawal successful. New balance: " << balance << endl;
        return true;
    }

    // Function to display account details
    void display() {
        cout << "Account Number: " << accountNumber << "\nName: " << name << "\nBalance: " << balance << "\n";
    }
};

// Class representing a bank with multiple accounts
class Bank {
private:
    vector<Account> accounts; // List of accounts
public:
    // Function to create a new account
    void createAccount(int accNo, string name, double balance) {
        accounts.push_back(Account(accNo, name, balance));
        cout << "Account created successfully!\n";
    }

    // Function to retrieve an account by its account number
    Account* getAccount(int accNo) {
        for (auto &acc : accounts) {
            if (acc.accountNumber == accNo) return &acc;
        }
        cout << "Account not found!" << endl;
        return nullptr;
    }
};

int main() {
    Bank bank;
    int choice, accNo;
    string name;
    double amount;

    while (true) {
        // Display menu options
        cout << "\nBank Management System";
        cout << "\n1. Create Account";
        cout << "\n2. Deposit Money";
        cout << "\n3. Withdraw Money";
        cout << "\n4. View Account Details";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            // Creating a new account
            cout << "Enter Account Number: "; cin >> accNo;
            cout << "Enter Name: "; cin.ignore(); getline(cin, name);
            cout << "Enter Initial Balance: "; cin >> amount;
            bank.createAccount(accNo, name, amount);
            break;
        case 2:
            // Depositing money into an account
            cout << "Enter Account Number: "; cin >> accNo;
            if (Account* acc = bank.getAccount(accNo)) {
                cout << "Enter Amount to Deposit: "; cin >> amount;
                acc->deposit(amount);
            }
            break;
        case 3:
            // Withdrawing money from an account
            cout << "Enter Account Number: "; cin >> accNo;
            if (Account* acc = bank.getAccount(accNo)) {
                cout << "Enter Amount to Withdraw: "; cin >> amount;
                acc->withdraw(amount);
            }
            break;
        case 4:
            // Viewing account details
            cout << "Enter Account Number: "; cin >> accNo;
            if (Account* acc = bank.getAccount(accNo)) {
                acc->display();
            }
            break;
        case 5:
            // Exiting the program
            cout << "Exiting...";
            return 0;
        default:
            // Handling invalid choices
            cout << "Invalid choice! Try again.";
        }
    }
}
