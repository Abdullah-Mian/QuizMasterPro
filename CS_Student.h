#ifndef CE_STUDENT_H
#define CE_STUDENT_H

#include "Student.h"
#include <list>
using namespace std;

class CS_Student : public Student
{
private:
    // Degree program for Computer Science student
    string degreeprogram = degree_programs[0];

    // List of courses for Computer Science student
    list<string> courses = {
        "Introduction to Computer Science (CS 101)",
        "Data Structures and Algorithms (CS 201)",
        "Computer Organization and Architecture (CS 220)",
        "Database Management Systems (CS 301)",
        "Operating Systems (CS 330)",
        "Software Engineering (CS 401)"};

public:
    // Constructor for CS_Student
    CS_Student(string password, string registration);

    // Method to display courses (overrides from the base class Student)
    void displayCourses() const override;

    // Method to display overall progress (overrides from the base class Student)
    void displayOverallProgress() const override;
};

#endif // CE_STUDENT_H
