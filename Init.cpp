#include <fstream>
#include "Init.h"
#include "Admin.h"
#include "SuperAdmin.h"
#include "SubAdmin.h"

using namespace std;

// Function to load admins from file
void loadAdmins() {
    ifstream inFile("Admins.txt");
    string username, password;
    while (getline(inFile, username) && getline(inFile, password)) {
        adminVector.push_back(new SuperAdmin(username, password));
    }
    inFile.close();
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