#include "Admin.h"
#include "SubAdmin.h"
#include "Student.h"
#include <vector>
#include <iostream>

using namespace std;

// Constructor for Admin class
Admin::Admin(string username, string password) : username(username), password(password) {}

// Destructor for Admin class
Admin::~Admin() {}

// Method to set credentials for Admin
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

// Method to get the username of Admin
string Admin::getUsername() const
{
    return this->username;
}

// Method to get the password of Admin
string Admin::getPassword() const
{
    return this->password;
}

// Method to enroll a student
void Admin::enrollStudent()
{
    string registration, password, degreeProgram;
    int degreeProgramIndex;
    cout << "Enter Registration: ";
    cin >> registration;
    cout << "Enter Password: ";
    cin >> password;
    // display degree programs with index
    cout << "Degree Programs: " << endl;
    for (int i = 0; i < degree_programs.size(); i++)
    {
        cout << i + 1 << ". " << degree_programs[i] << endl;
    }
    cout << "Enter Degree Program Index: ";
    cin >> degreeProgramIndex;
    degreeProgram = degree_programs[degreeProgramIndex - 1];
    new Student(password, registration, degreeProgram);
    cout << "Student Enrolled Successfully!" << endl;
}