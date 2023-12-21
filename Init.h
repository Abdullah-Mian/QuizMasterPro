#ifndef INIT_H
#define INIT_H

#include <string>
#include "Admin.h"
#include <string>

// Function to load admins from file
extern void loadAdmins();

// Function to save admins to file
extern void saveAdmins();

// Function to Save Students from file
extern void saveStudents();

// Function to load Students from file
extern void loadStudents();

// Function to convert string to lowercase
extern string toLowerCase(string str);

// Function to check if a username exists in a vector of students
// and return its index, or -1 if not found
extern int usernameExists(string registration);

// Function to check if a username exists in a vector of Admins
extern int usernameExistsAdmin(string username);


#endif // INIT_H