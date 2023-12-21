#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <vector>
#include <list>
#include <map>

using namespace std;

// Forward declaration of Admin class to avoid circular dependency
class Admin;
class Student;
extern vector<Student *> studentVector;
extern vector<string> degree_programs;

class Student
{
protected:
    string registration;
    string password;
    string degreeProgram;
    vector<string> courses; // Vector to store courses

    // Map to store degree programs and corresponding courses
    map<string, vector<string>> degreeCourses = {
        {"BSCS", {"Introduction to Computer Science (CS 101)", "Data Structures and Algorithms (CS 201)"}},
        {"BSEE", {"Circuit Analysis (Course Code: EE101)", "Digital Electronics (Course Code: EE204)"}},
        {"BSSE", {"Introduction to Software Engineering (Course Code: SE101)", "Object-Oriented Programming (Course Code: SE201)"}},
        {"BSCE", {"Digital Logic Design (ECE 201)", "Embedded Systems (ECE 415)"}},
        {"BSCHE", {"Introduction to Chemical Engineering (CHE 101)", "Chemical Thermodynamics (CHE 201)"}}};

public:
    // Constructor for Student
    Student(string password, string registration, string degProgram);

    // Method to get registration
    string getRegistration() const;

    // Pure virtual methods to be implemented by derived classes
    void displayCourses() const;
    void displayOverallProgress() const;

    // Method to set credentials
    virtual void setCredentials(string newPassword);

    // Method to get password
    string getPassword() const;

    // Method to get the degree
    string getDegree() const;
     
    // Method to get the courses
    vector<string> getCourses() const;
};

#endif // STUDENT_H
