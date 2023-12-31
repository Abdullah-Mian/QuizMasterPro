#include "Student.h"
#include "Init.h"

vector<string> degree_programs = {"BSCS", "BSEE", "BSSE", "BSCE", "BSCHE"};
// vector<string> CScourses = {"(CS 101)", "(CS 201)"};
// vector<string> EEcourses = {"(EE 101)", "(EE 204)"};
// vector<string> SEcourses = {"(SE 101)", "(SE 201)"};
// vector<string> CEcourses = {"(ECE 201)", "(ECE 415)"};
// vector<string> CHEcourses = {"(CHE 101)", "(CHE 201)"};
// Constructor for Student
Student::Student(string password, string registration, string degProgram) : password(password), registration(registration), degreeProgram(degProgram)
{
    studentVector.push_back(this);
    courses = degreeCourses[degreeProgram];
    coursesCodes = degreeCoursesCodes[degreeProgram];
}

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
        saveStudents();
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

// Method to get degree
string Student::getDegree() const
{
    return this->degreeProgram;
}

// Method to display courses
void Student::displayCourses() const
{
    cout << "Registered Courses: " << endl;
    for (int i = 0; i < courses.size(); i++)
    {
        cout << i+1 << ". " << courses[i] << endl;
    }
}

// Method to get courses
vector<string> Student::getCourses() const
{
    return this->courses;
}

// Method to get courses codes
vector<string> Student::getCoursesCodes() const
{
    return this->coursesCodes;
}