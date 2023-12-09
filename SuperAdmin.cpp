#include "SuperAdmin.h"
#include "SubAdmin.h"
#include "Admin.h"
#include <iostream>

using namespace std;

SuperAdmin::SuperAdmin(string username, string password) : Admin(username, password) {}

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

    SubAdminsVector.push_back(SubAdmin(username, password));
    cout << "Sub-Admin Added Successfully!" << endl;
}

void SuperAdmin::viewSubAdmins() const
{
    cout << "Sub-Admins: " << endl;
    for (int i = 0; i < SubAdminsVector.size(); i++)
    {
        cout << "Username: " << SubAdminsVector[i].getUsername() << endl;
    }
}

void SuperAdmin::deleteSubAdmin()
{
    string username;

    viewSubAdmins();

    cout << "Enter Username: ";
    cin >> username;

    for (int i = 0; i < SubAdminsVector.size(); i++)
    {
        if (SubAdminsVector[i].getUsername() == username)
        {
            cout << "Do you want to delete " << username << " ? (y/n): ";
            char choice;
            cin >> choice;
            if (choice == 'y')
            {
                SubAdminsVector.erase(SubAdminsVector.begin() + i);
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
