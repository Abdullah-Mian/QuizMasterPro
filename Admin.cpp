#include "Admin.h"
#include "SubAdmin.h"

#include <iostream>

using namespace std;

Admin::Admin(string username, string password) : username(username), password(password) {}

Admin::~Admin() {}

void Admin::setCredentials(string newUsername, string newPassword)
{
    cout << "Enter Old Username: ";
    string oldUsername;
    cin >> oldUsername;
    cout << "Enter Old Password: ";
    string oldPassword;
    cin >> oldPassword;
    if (oldUsername == this->username && oldPassword == this->password)
    {
        cout << "Enter New Username: ";
        cin >> newUsername;
        cout << "Enter New Password: ";
        cin >> newPassword;
        this->username = newUsername;
        this->password = newPassword;
        cout << "Username and Password Changed Successfully!" << endl;
    }
    else
    {
        cout << "Username and Password Not Changed!" << endl;
    }
}

string Admin::getUsername() const
{
    return this->username;
}

string Admin::getPassword() const
{
    return this->password;
}
