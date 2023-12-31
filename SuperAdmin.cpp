#include "SuperAdmin.h"
#include "SubAdmin.h"
#include "Admin.h"
#include <iostream>
#include <vector>
#include "ClearScreen.h"
#include "Init.h"

using namespace std;

// Constructor for SuperAdmin
SuperAdmin::SuperAdmin(string username, string password) : Admin(username, password) {}

// Method to add a sub-admin
void SuperAdmin::addSubAdmin()
{
    string username, password;
    bool exists = false;

    do
    {
        exists = false;

        cout << "Enter Username: ";
        cin >> username;
        cout << "Enter Password: ";
        cin >> password;

        // Check if sub-admin already exists
        for (int i = 0; i < SubAdminsVector.size(); i++)
        {
            if (SubAdminsVector[i].getUsername() == username)
            {
                exists = true;
                cout << "Sub-Admin Already Exists!" << endl;
                return;
            }
        }
    } while (exists);

    // Add the new sub-admin
    new SubAdmin(username, password);
    cout << "Sub-Admin Added Successfully!" << endl;
}

// Method to view all sub-admins
void SuperAdmin::viewSubAdmins() const
{
    cout << "Sub-Admins: " << endl;
    for (int i = 0; i < adminVector.size(); i++)
    {
        cout << "Username: " << adminVector[i]->getUsername() << endl;
    }
}

// Method to delete a sub-admin
void SuperAdmin::deleteSubAdmin()
{
    string username;

    // Display all sub-admins
    viewSubAdmins();

    cout << "Enter Username: ";
    cin >> username;

    // Search for the sub-admin
    for (int i = 0; i < adminVector.size(); i++)
    {
        if (toLowerCase(adminVector[i]->getUsername()) == toLowerCase(username))
        {
            cout << "Do you want to delete " << username << " ? (y/n): ";
            char choice;
            cin >> choice;
            if (choice == 'y')
            {
                // Delete the sub-admin
                adminVector.erase(adminVector.begin() + i);
                cout << "Sub-Admin Deleted Successfully!" << endl;
                return;
            }
            else
            {
                cout << "Sub-Admin Not Deleted!" << endl;
                return;
            }
            return;
        }
        
    }
    cout << "Sub-Admin Not Found!" << endl;
}
