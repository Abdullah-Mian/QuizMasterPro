#include "SubAdmin.h"

#include <iostream>

using namespace std;

SubAdmin::SubAdmin(string username, string password) : Admin(username, password)
{
    SubAdminsVector.push_back(*this);
}

void SubAdmin::viewSubAdmins() const
{
    cout << "You are not a super-Admin" << endl;
}

void SubAdmin::addSubAdmin()
{
    cout << "You are not a super-Admin" << endl;
}

void SubAdmin::deleteSubAdmin()
{
    cout << "You are not a super-Admin" << endl;
}
