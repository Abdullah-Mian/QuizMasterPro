#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <vector>

using namespace std;

class Student
{
protected:
    string registration;
    string password;
    vector<string> degree_programs;

public:
    // Constructor for Student
    Student(string password, string registration);

    // Method to get registration
    string getRegistration() const;

    // Pure virtual methods to be implemented by derived classes
    virtual void displayCourses() const = 0;
    virtual void displayOverallProgress() const = 0;

    // Method to set credentials
    virtual void setCredentials(string newPassword);

    // Method to get password
    string getPassword() const;
};

#endif // STUDENT_H
