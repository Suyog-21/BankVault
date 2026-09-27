#ifndef USER_H
#define USER_H

#include <iostream>
using namespace std;

class User {
protected:
    string username;
    string password;
    string role;

public:
    User(string u, string p, string r) : username(u), password(p), role(r) {}

    virtual bool menu() = 0; // ✅ FIXED (was void)

    string getUsername() { return username; }
    string getPassword() { return password; }
    string getRole() { return role; }
};

#endif