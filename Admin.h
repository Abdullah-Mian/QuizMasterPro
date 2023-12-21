#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Forward declaration of SubAdmin class to avoid circular dependency
class SubAdmin;
class Admin;
extern vector<Admin*> adminVector;

// Abstract Class 
class Admin
{
protected:
    string username;
    string password;
    vector<SubAdmin> SubAdminsVector;

public:
    // Constructor for Admin
    Admin(string username, string password);

    // Virtual destructor for proper destruction of derived classes
    virtual ~Admin();

    // Pure virtual functions to be implemented by derived classes
    virtual void addSubAdmin() = 0;
    virtual void deleteSubAdmin() = 0;
    virtual void viewSubAdmins() const = 0;

    // Virtual function for setting credentials
    virtual void setCredentials(string newUsername, string newPassword);

    // Method to get username
    string getUsername() const;

    // Method to get password
    string getPassword() const;

    // Method to enroll a student
    void enrollStudent();
};

#endif // ADMIN_H