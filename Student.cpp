#include "Student.h"

// Constructor for Student
Student::Student(string password, string registration, string degProgram) : password(password), registration(registration), degreeProgram(degProgram) {}

// Method to get registration
string Student::getRegistration() const
{
    return this->registration;
}

// Method to set credentials
void Student::setCredentials(string newPassword)
{
    // Prompt for old password
    cout << "Enter Old Password: ";
    string oldPassword;
    cin >> oldPassword;

    // Check if the old password matches
    if (oldPassword == this->password)
    {
        // Prompt for and update new password
        cout << "Enter New Password: ";
        cin >> newPassword;
        this->password = newPassword;
        cout << "Password Changed Successfully!" << endl;
    }
    else
    {
        cout << "Password Not Changed!" << endl;
    }
}

// Method to get password
string Student::getPassword() const
{
    return this->password;
}