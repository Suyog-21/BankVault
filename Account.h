#define ACCOUNT_H

#include <iostream>
#include <string>
using namespace std;

class Account {
public:
    string owner;
    double balance;

    Account(string o) : owner(o), balance(0) {}

    void deposit(double amt) {
        balance += amt;
        cout << "Deposited: " << amt << endl;
    }

    void withdraw(double amt) {
        if (amt > balance) {
            cout << "Insufficient balance!\n";
        } else {
            balance -= amt;
            cout << "Withdrawn: " << amt << endl;
        }
    }

    void showBalance() {
        cout << "Balance: " << balance << endl;
    }
};

#endif