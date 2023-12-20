#ifndef SUBADMIN_H
#define SUBADMIN_H

#include "Admin.h"  // Include the header file for the base class

using namespace std;

class SubAdmin : public Admin
{
public:
    // Constructor for SubAdmin
    SubAdmin(string username, string password);

    // Overrides from the base class Admin
    void viewSubAdmins() const override;
    void addSubAdmin() override;
    void deleteSubAdmin() override;
};

#endif // SUBADMIN_H