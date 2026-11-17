#include <iostream>
#include <string>
using namespace std;

class BankAccount {

    private:
        string accountHolder;
        int accountNumber;
        float balance;

    public:
        string accountType;

        void inputDetails() {
            cout << "Enter Account Holder Name: ";
            getline(cin >> ws, accountHolder);

            cout << "Enter Account Number: ";
            cin >> accountNumber;

            cout << "Enter Account Type: ";
            getline(cin >> ws, accountType);

            cout << "Enter Initial Balance: ";
            cin >> balance;
        }

        void deposit();

        void withdraw();

        void displayDetails();
};

void BankAccount::deposit() {

    float amount;

    cout << "Enter Amount to Deposit: ";
    cin >> amount;

    if (amount > 0) {
        balance = balance + amount;
        cout << "Amount Deposited Successfully!" << endl;
    }
    else {
        cout << "Invalid Deposit Amount!" << endl;
    }
}

void BankAccount::withdraw() {

    float amount;

    cout << "Enter Amount to Withdraw: ";
    cin >> amount;

    if (amount > 0 && amount <= balance) {
        balance = balance - amount;
        cout << "Amount Withdrawn Successfully!" << endl;
    }
    else {
        cout << "Insufficient Balance or Invalid Amount!" << endl;
    }
}

void BankAccount::displayDetails() {

    cout << "\n----- Account Details -----" << endl;
    cout << "Account Holder: " << accountHolder << endl;
    cout << "Account Number: " << accountNumber << endl;
    cout << "Account Type: " << accountType << endl;
    cout << "Current Balance: " << balance << endl;
}

int main() {

    BankAccount b1, b2;

    cout << "Enter First Account Details" << endl;
    b1.inputDetails();

    cout << "\nEnter Second Account Details" << endl;
    b2.inputDetails();

    cout << "\n----- First Account Deposit -----" << endl;
    b1.deposit();

    cout << "\n----- Second Account Deposit -----" << endl;
    b2.deposit();

    cout << "\n----- First Account Withdrawal -----" << endl;
    b1.withdraw();

    cout << "\n----- Second Account Withdrawal -----" << endl;
    b2.withdraw();

    cout << "\n\nUpdated First Account Details";
    b1.displayDetails();

    cout << "\n\nUpdated Second Account Details";
    b2.displayDetails();

    return 0;
}