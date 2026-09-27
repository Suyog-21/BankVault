#include <bits/stdc++.h>
#include "User.h"
#include "Account.h"
#include "Loan.h"
#include "Auth.h"
using namespace std;

// GLOBAL DATA
vector<User*> users;
vector<string> transactions;

// ---------------- CUSTOMER ----------------
class Customer : public User {
    Account acc;

public:
    Customer(string u, string p) : User(u, p, "User"), acc(u) {}

    bool menu() {
        int choice;
        do {
            cout << "\n1.Deposit 2.Withdraw 3.Balance 4.Loan 5.Logout\n";
            cin >> choice;

            if (choice == 1) {
                double amt; cin >> amt;
                acc.deposit(amt);
                transactions.push_back(username + " deposited " + to_string(amt));
            }
            else if (choice == 2) {
                double amt; cin >> amt;
                acc.withdraw(amt);
                transactions.push_back(username + " withdrew " + to_string(amt));
            }
            else if (choice == 3) {
                acc.showBalance();
            }
            else if (choice == 4) {
                double p, r; int t;
                cout << "Enter P R T: ";
                cin >> p >> r >> t;
                Loan l(p, r, t);
                cout << "Interest: " << l.calculate() << endl;
            }

        } while (choice != 5);

        return false; // logout
    }
};

// ---------------- MANAGER ----------------
class Manager : public User {
public:
    Manager(string u, string p) : User(u, p, "Manager") {}

    bool menu() {
        cout << "\nManager Access Granted\n";
        cout << "Press Enter to logout...\n";
        cin.ignore();
        cin.get();
        return false;
    }
};

// ---------------- ADMIN ----------------
class Admin : public User {
public:
    Admin(string u, string p) : User(u, p, "Admin") {}

    bool menu() {
        int choice;

        do {
            cout << "\n--- Admin Panel ---\n";
            cout << "1. View Users\n";
            cout << "2. Add User\n";
            cout << "3. Remove User\n";
            cout << "4. View Transactions\n";
            cout << "5. Logout\n";
            cin >> choice;

            if (choice == 1) {
                cout << "\n--- Users List ---\n";
                for (auto u : users) {
                    cout << u->getUsername() << " (" << u->getRole() << ")\n";
                }
            }

            else if (choice == 2) {
                string u, p, role;
                cout << "Enter username: ";
                cin >> u;
                cout << "Enter password: ";
                cin >> p;
                cout << "Enter role (Admin/Manager/User): ";
                cin >> role;

                if (role == "Admin")
                    users.push_back(new Admin(u, p));
                else if (role == "Manager")
                    users.push_back(new Manager(u, p));
                else
                    users.push_back(new Customer(u, p));

                cout << "User added successfully\n";
            }

            else if (choice == 3) {
                string name;
                cout << "Enter username to remove: ";
                cin >> name;

                for (auto it = users.begin(); it != users.end(); ++it) {
                    if ((*it)->getUsername() == name) {
                        users.erase(it);
                        cout << "User removed\n";
                        break;
                    }
                }
            }

            else if (choice == 4) {
                cout << "\n--- Transactions ---\n";
                for (auto t : transactions) {
                    cout << t << endl;
                }
            }

        } while (choice != 5);

        return false; // logout
    }
};

// ---------------- MAIN ----------------
int main() {

    // Initial users
    users.push_back(new Admin("admin", "admin123"));
    users.push_back(new Manager("manager", "manager123"));
    users.push_back(new Customer("user", "user123"));

    while (true) {
        cout << "\n--- Login System ---\n";

        User* current = login(users);

        if (current != nullptr) {
            current->menu();  // logout → back here
        }

        cout << "\nDo you want to exit program? (y/n): ";
        char ch;
        cin >> ch;

        if (ch == 'y' || ch == 'Y') break;
    }

    return 0;
}