#include "CS_Student.h"
#include <iostream>

using namespace std;

// Constructor for CS_Student
CS_Student::CS_Student(string password, string registration) : Student(password, registration)
{
    // Initialize CS_Student Courses
    degreeprogram = degree_programs[0];
    courses = {
        "Introduction to Computer Science (CS 101)",
        "Data Structures and Algorithms (CS 201)",
        "Computer Organization and Architecture (CS 220)",
        "Database Management Systems (CS 301)",
        "Operating Systems (CS 330)",
        "Software Engineering (CS 401)"};
}

// Method to display courses for a CS student
void CS_Student::displayCourses() const
{
    cout << "Courses for " << degreeprogram << " student (" << getRegistration() << "):" << endl;
    for (const auto &course : courses)
    {
        cout << "- " << course << endl;
    }
}

// Method to display overall progress for a CS student
void CS_Student::displayOverallProgress() const
{
    cout << "Overall progress for " << degreeprogram << " student (" << getRegistration() << "):" << endl;
    // Add logic to display overall progress
}

