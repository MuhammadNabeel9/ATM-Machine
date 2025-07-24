#include <iostream>
using namespace std;

class BankAccount {
protected:
    float balance;

public:
    BankAccount(float initial_balance = 50000.00) 
	{
        balance = initial_balance;
    }

    virtual void balanceInquiry() {
        cout << "Your Balance is Rs " << balance << endl;
    }

    virtual void withdraw(float amount)
	{
        if (amount <= 0) {
            cout << "Amount cannot be zero or negative." << endl;
        } else if (amount > balance) {
            cout << "You do not have enough funds to withdraw this amount." << endl;
        } else {
            balance -= amount;
            cout << "Withdrawal successful! Your new balance is Rs " << balance << endl;
        }
    }

    virtual void transfer(float amount, int account_number) {
        if (amount <= 0) {
            cout << "Amount cannot be zero or negative." << endl;
        } else if (amount > balance) {
            cout << "You do not have enough funds to transfer this amount." << endl;
        } else {
            balance -= amount;
            cout << "Rs " << amount << " transferred successfully to account no: " << account_number << endl;
            cout << "Your new balance is Rs " << balance << endl;
        }
    }
};

class ATM : public BankAccount {
private:
    int pin;
    int account_type;

public:
    ATM(float initial_balance, int initial_pin) : BankAccount(initial_balance) {
        pin = initial_pin;
    }

    void pinVerification() {
        int entered_pin;
        cout << "Please Enter Your PIN = ";
        cin >> entered_pin;

        if (entered_pin != pin) {
            cout << "Incorrect PIN. Access Denied!" << endl;
            exit(0); // Exiting the program if PIN is incorrect.
        }
    }

    void accountSelection() {
        cout << "SELECT YOUR ACCOUNT TYPE" << endl;
        cout << "1) Current" << endl;
        cout << "2) Saving" << endl;
        cout << "3) Default" << endl;
        cout << "Please select account type (1, 2, or 3): ";
        cin >> account_type;
    }

    void transactionMenu() {
        int option;
        char m;
        do {
            cout << "1) Cash Withdraw" << endl;
            cout << "2) Balance Inquiry" << endl;
            cout << "3) Amount Transfer" << endl;
            cout << "4) Main Menu (Start Over)" << endl;
            cout << "5) Quit" << endl;
            cout << "Select an option (1, 2, 3, 4, or 5): ";
            cin >> option;

            switch (option) {
                case 1: {
                    float amount;
                    cout << "Please enter amount to withdraw: ";
                    cin >> amount;
                    withdraw(amount);
                    break;
                }
                case 2:
                    balanceInquiry();
                    break;
                case 3: {
                    int account_number;
                    float amount;
                    cout << "Enter Account Number: ";
                    cin >> account_number;
                    cout << "Enter amount: ";
                    cin >> amount;
                    transfer(amount, account_number);
                    break;
                }
                case 4:
                    return;  // Go back to the account selection menu
                case 5:
                    cout << "Thank you for using our ATM!" << endl;
                    exit(0);  // Exit the program
                default:
                    cout << "Invalid option. Please try again." << endl;
            }

            cout << "Do you want another transaction (y/n): ";
            cin >> m;
        } while (m == 'y');
    }
};

int main() {
    ATM atm(50000.00, 12345);  // Initialize ATM with balance 50000 and PIN 12345

	cout <<"                               "<<"****************************************************"<<endl;
  	cout <<"                               "<<"*                   WELCOME TO                     *"<<endl;
  	cout <<"                               "<<"*              ATM WORKING SYSTEM                  *"<<endl;
  	cout <<"                               "<<"****************************************************"<<endl;
  	cout <<"                               "<<"                                                    "<<endl;

    // Insert Card and PIN Verification
    cout << "Please Insert your Card [Press ENTER to insert card]" << endl;
    cin.get();  // Wait for user to press Enter
    atm.pinVerification();

    // Account Selection and Transaction Menu
    atm.accountSelection();
    atm.transactionMenu();

    return 0;
}

