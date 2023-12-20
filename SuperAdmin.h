// SUPERADMIN_H
#ifndef SUPERADMIN_H
#define SUPERADMIN_H

#include "Admin.h"  // Include the header file for the base class
#include "SubAdmin.h"   // Include the header file for the sub-admin class
#include <vector>   // Include the vector header file
#include <iostream> // Include the iostream header file


class SuperAdmin : public Admin
{
public:
    // Constructor for SuperAdmin
    SuperAdmin(string username, string password);

    // Overrides from the base class Admin
    void addSubAdmin() override;
    void viewSubAdmins() const override;
    void deleteSubAdmin() override;
};

#endif // SUPERADMIN_H