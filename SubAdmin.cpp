#include "SubAdmin.h"

#include <iostream>

using namespace std;

// Constructor for SubAdmin
SubAdmin::SubAdmin(string username, string password) : Admin(username, password)
{
    // Add the current SubAdmin to the vector
    SubAdminsVector.push_back(*this);
}

// Method to view sub-admins (overrides from the base class Admin)
void SubAdmin::viewSubAdmins() const
{
    cout << "You are not a super-Admin" << endl;
}

// Method to add sub-admin (overrides from the base class Admin)
void SubAdmin::addSubAdmin()
{
    cout << "You are not a super-Admin" << endl;
}

// Method to delete sub-admin (overrides from the base class Admin)
void SubAdmin::deleteSubAdmin()
{
    cout << "You are not a super-Admin" << endl;
}
