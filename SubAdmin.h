#ifndef SUBADMIN_H
#define SUBADMIN_H

#include "Admin.h"

using namespace std;

class SubAdmin : public Admin
{
public:
    SubAdmin(string username, string password);

    void viewSubAdmins() const override;
    void addSubAdmin() override;
    void deleteSubAdmin() override;
};

#endif // SUBADMIN_H
