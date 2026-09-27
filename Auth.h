#ifndef AUTH_H
#define AUTH_H

#include "User.h"
#include <vector>

User* login(vector<User*>& users) {
    string u, p;
    cout << "Username: ";
    cin >> u;
    cout << "Password: ";
    cin >> p;

    for (auto user : users) {
        if (user->getUsername() == u && user->getPassword() == p) {
            cout << "Login successful as " << user->getRole() << endl;
            return user;
        }
    }

    cout << "Invalid credentials\n";
    return nullptr;
}

#endif