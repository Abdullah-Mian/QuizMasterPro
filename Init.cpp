#include <fstream>
#include "Init.h"
#include "Admin.h"
#include "SuperAdmin.h"
#include "SubAdmin.h"
#include "Student.h"

using namespace std;


vector<Student*> studentVector;

// Function to load admins from file
void loadAdmins() {
    ifstream inFile("Admins.txt");
    string username, password;
    while (getline(inFile, username) && getline(inFile, password)) {
        adminVector.push_back(new SuperAdmin(username, password));
    }
    inFile.close();
}


void loadStudents(){
    ifstream inFile("Students.txt");
    string username, password, registration, degProgram;

    while (getline(inFile, username) && getline(inFile, password) && getline(inFile, registration) && getline(inFile, degProgram)) {
        studentVector.push_back(new Student(password, registration, degProgram));
    }

    inFile.close();
}


void saveStudents() {
    ofstream outFile("Students.txt");

    if (!outFile.is_open()) {
        cerr << "Error creating/opening Students.txt file\n";
        return;
    }

    for (int i = 0; i < studentVector.size(); i++) {
        outFile << studentVector[i]->getRegistration() << endl;
        outFile << studentVector[i]->getPassword() << endl;
        outFile << studentVector[i]->getDegree() << endl;
        // outFile << studentVector[i]->getDegree() << endl;
        // outFile << studentVector[i]->getOtherMemberFunction() << endl;
    }

    outFile.close();
}


// Function to save admins to file
void saveAdmins() {
    ofstream outFile("Admins.txt");

    // Check if the file is open
    if (!outFile.is_open()) {
        cerr << "Error creating/opening Admins.txt file\n";
        return;
    }

    // Save the vector data to the file
    for (Admin* admin : adminVector) {
        outFile << admin->getUsername() << "\n" << admin->getPassword() << "\n";
    }

    // Close the file
    outFile.close();
}