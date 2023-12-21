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
        {"BSCS", {"Introduction to Computer Science (CS 101)", "Data Structures and Algorithms (CS 201)", "Computer Organization and Architecture (CS 220)", "Database Management Systems (CS 301)", "Operating Systems (CS 330)", "Software Engineering (CS 401)"}},
        {"BSEE", {"Circuit Analysis (Course Code: EE101)", "Digital Electronics (Course Code: EE204)", "Electromagnetic Fields and Waves (Course Code: EE301)", "Power Systems Analysis (Course Code: EE402)", "Control Systems (Course Code: EE501)", "Electronics and VLSI Design (Course Code: EE601)"}},
        {"BSSE", {"Introduction to Software Engineering (Course Code: SE101)", "Object-Oriented Programming (Course Code: SE201)", "Software Requirements and Analysis (Course Code: SE301)", "Software Design and Architecture (Course Code: SE401)", "Software Testing and Quality Assurance (Course Code: SE501)", "Software Project Management (Course Code: SE601)"}},
        {"BSCE", {"Digital Logic Design (ECE 201)", "Embedded Systems (ECE 415)", "Computer Organization and Architecture (ECE 301)", "Digital Signal Processing (ECE 440)", "Electronics (ECE 320)", "Computer Networks (ECE 401)"}},
        {"BSCHE", {"Introduction to Chemical Engineering (CHE 101)", "Chemical Thermodynamics (CHE 201)", "Mass Transfer and Separation Processes (CHE 301)", "Chemical Reaction Engineering (CHE 320)", "Process Control and Instrumentation (CHE 410)", "Design of Chemical Processes (CHE 420)"}}};

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
};

#endif // STUDENT_H
