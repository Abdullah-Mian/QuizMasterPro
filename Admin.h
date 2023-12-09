#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class SubAdmin;

class Admin
{
protected:
    string username;
    string password;
    vector<SubAdmin> SubAdminsVector;

public:
    Admin(string username, string password);
    virtual ~Admin();

    virtual void addSubAdmin() = 0;
    virtual void deleteSubAdmin() = 0;
    virtual void viewSubAdmins() const = 0;

    virtual void setCredentials(string newUsername, string newPassword);

    string getUsername() const;
    string getPassword() const;
};

#endif // ADMIN_H
