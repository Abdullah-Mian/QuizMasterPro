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
    string degreeProgram;
    vector<string> degree_programs = {"Computer Science", "Electrical Engineering", "Software Engineering", "Computer Engineering", "Chemical Engineering"};
public:
    // Constructor for Student
    Student(string password, string registration, string degProgram);

    // Method to get registration
    string getRegistration() const;

    // Pure virtual methods to be implemented by derived classes
    void displayCourses() const ;
    void displayOverallProgress() const ;

    // Method to set credentials
    virtual void setCredentials(string newPassword);

    // Method to get password
    string getPassword() const;

    
     // Method to get the degree
     string getDegree() const;
};

#endif // STUDENT_H
