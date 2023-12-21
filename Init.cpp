#include <fstream>
#include "Init.h"
#include "Admin.h"
#include "SuperAdmin.h"
#include "SubAdmin.h"
#include "Student.h"
#include <algorithm>
#include <cctype>
#include <vector>
#include <string>

using namespace std;

// Function to convert a string to lowercase
string toLowerCase(string str)
{
    // Convert the string to lowercase
    transform(str.begin(), str.end(), str.begin(), [](unsigned char c)
              { return tolower(c); });

    // Return the lowercase string
    return str;
}

// Function to load admins from file
void loadAdmins()
{
    ifstream inFile("Admins.txt");
    string username, password;
    while (getline(inFile, username) && getline(inFile, password))
    {
        adminVector.push_back(new SuperAdmin(username, password));
    }
    inFile.close();
}

void loadStudents()
{
    ifstream inFile("Students.txt");
    string username, password, registration, degProgram;

    while (getline(inFile, username) && getline(inFile, password) && getline(inFile, registration) && getline(inFile, degProgram))
    {
        studentVector.push_back(new Student(password, registration, degProgram));
    }

    inFile.close();
}

void saveStudents()
{
    ofstream outFile("Students.txt");

    if (!outFile.is_open())
    {
        cerr << "Error creating/opening Students.txt file\n";
        return;
    }

    for (int i = 0; i < studentVector.size(); i++)
    {
        outFile << studentVector[i]->getRegistration() << endl;
        outFile << studentVector[i]->getPassword() << endl;
        outFile << studentVector[i]->getDegree() << endl;
    }
    outFile.close();
}

// Function to save admins to file
void saveAdmins()
{
    ofstream outFile("Admins.txt");

    // Check if the file is open
    if (!outFile.is_open())
    {
        cerr << "Error creating/opening Admins.txt file\n";
        return;
    }

    // Save the vector data to the file
    for (Admin *admin : adminVector)
    {
        outFile << admin->getUsername() << "\n"
                << admin->getPassword() << "\n";
    }

    // Close the file
    outFile.close();
}

// Function to check if a username exists in a vector of students
// and return its index, or -1 if not found
int usernameExists(string registration)
{

    // Loop through the vector
    for (int i = 0; i < studentVector.size(); i++)
    {
        // Check if the registration matches
        if (toLowerCase(studentVector[i]->getRegistration()) == toLowerCase(registration))
        {
            // Return the index
            return i;
        }
    }

    // Return -1 if not found
    return -1;
}

// Function to check if a username exists in a vector of Admins
int usernameExistsAdmin(string username)
{
    // Loop through the vector
    for (int i = 0; i < adminVector.size(); i++)
    {
        // Check if the username matches
        if (toLowerCase(adminVector[i]->getUsername()) == toLowerCase(username))
        {
            // Return the index
            return i;
        }
    }

    // Return -1 if not found
    return -1;
}
