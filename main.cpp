/*
  __  __         _            _____                     _______       _____                   _
 |  \/  |       | |          / ____|                   |__   __|     |  __ \                 | |
 | \  / |  __ _ | | __ ___  | (___   _   _  _ __  ___     | |  ___   | |__) | ___   __ _   __| |
 | |\/| | / _` || |/ // _ \  \___ \ | | | || '__|/ _ \    | | / _ \  |  _  / / _ \ / _` | / _` |
 | |  | || (_| ||   <|  __/  ____) || |_| || |  |  __/    | || (_) | | | \ \|  __/| (_| || (_| |
 |_|  |_| \__,_||_|\_\\___| |_____/  \__,_||_|   \___|    |_| \___/  |_|  \_\\___| \__,_| \__,_|
  _____   ______            _____   __  __  ______                    _
 |  __ \ |  ____|    /\    |  __ \ |  \/  ||  ____|                  | |
 | |__) || |__      /  \   | |  | || \  / || |__       _ __ ___    __| |
 |  _  / |  __|    / /\ \  | |  | || |\/| ||  __|     | '_ ` _ \  / _` |
 | | \ \ | |____  / ____ \ | |__| || |  | || |____  _ | | | | | || (_| |
 |_|__\_\|______|/_/    \_\|_____/ |_|  |_||______|(_)|_| |_| |_| \__,_|
 |  ____|
 | |__  ___   _ __
 |  __|/ _ \ | '__|
 | |  | (_) || |
 |_|___\___/ |_|              _
 |  ____|| |                 | |
 | |__   | |  __ _ __      __| |  ___  ___  ___
 |  __|  | | / _` |\ \ /\ / /| | / _ \/ __|/ __|
 | |     | || (_| | \ V  V / | ||  __/\__ \\__ \
 |_|____ |_| \__,_|  \_/\_/  |_| \___||___/|___/
 |  ____|                        | |  (_)
 | |__   __  __ ___   ___  _   _ | |_  _   ___   _ __
 |  __|  \ \/ // _ \ / __|| | | || __|| | / _ \ | '_ \
 | |____  >  <|  __/| (__ | |_| || |_ | || (_) || | | |
 |______|/_/\_\\___| \___| \__,_| \__||_| \___/ |_| |_|

*/

#include <iostream> /*No Need For #include<string>*/
#include <vector>
#include <fstream>
#include <list>

#include "Admin.h"
#include "SubAdmin.h"
#include "SuperAdmin.h"
#include "Student.h"
#include "Sleep.h"       // Include the Sleep header file
#include "ClearScreen.h" // Include the ClearScreen header file
#include "Init.h"        // Include the Init header file

// Forward Declarations
class User;
class SubAdmin;
class Admin;
class SuperAdmin;
class Student;

//   CS  list<string> courses = {"Introduction to Computer Science (CS 101)", "Data Structures and Algorithms (CS 201)", "Computer Organization and Architecture (CS 220)", "Database Management Systems (CS 301)", "Operating Systems (CS 330)", "Software Engineering (CS 401)"};

//   EE  list<string> courses = {"Circuit Analysis (Course Code: EE101)", "Digital Electronics (Course Code: EE204)", "Electromagnetic Fields and Waves (Course Code: EE301)", "Power Systems Analysis (Course Code: EE402)", "Control Systems (Course Code: EE501)", "Electronics and VLSI Design (Course Code: EE601)"};

//   SE  list<string> courses = {"Introduction to Software Engineering (Course Code: SE101)", "Object-Oriented Programming (Course Code: SE201)", "Software Requirements and Analysis (Course Code: SE301)", "Software Design and Architecture (Course Code: SE401)", "Software Testing and Quality Assurance (Course Code: SE501)", "Software Project Management (Course Code: SE601)"};

//   CE  list<string> courses = {"Digital Logic Design (ECE 201)", "Embedded Systems (ECE 415)", "Computer Organization and Architecture (ECE 301)", "Digital Signal Processing (ECE 440)", "Electronics (ECE 320)", "Computer Networks (ECE 401)"};

//  CHE   list<string> courses = {"Introduction to Chemical Engineering (CHE 101)", "Chemical Thermodynamics (CHE 201)", "Mass Transfer and Separation Processes (CHE 301)", "Chemical Reaction Engineering (CHE 320)", "Process Control and Instrumentation (CHE 410)", "Design of Chemical Processes (CHE 420)"};

// Redeclaration of Globals
vector<Admin *> adminVector;
vector<Student *> studentVector;
void loadAdmins();
void saveAdmins();
void saveStudents();
void loadStudents();
string toLowerCase(string str);
int usernameExists(string username);
int usernameExistsAdmin(string username);

int main()
{
    loadAdmins();
    loadStudents();

    clearScreen();

    cout << "Program is starting..." << endl;
    for (int i = 0; i < 5; i++)
    {
        // mySleep(1);

        cout << "=";
        cout.flush();
    }
    clearScreen();
    cout << "================================================================\n";
    cout << R"(
____ _  _ _ ___  _  _ ____ ____ ___ ____ ____ ___  ____ ____ 
|  | |  | |   /  |\/| |__| [__   |  |___ |__/ |__] |__/ |  | 
|_\| |__| |  /__ |  | |  | ___]  |  |___ |  \ |    |  \ |__| 
                                                             
)" << endl;
    cout << "================================================================\n";

    // mySleep(1);

    clearScreen();

    int person;
    int choice;
    int index;
    string username;
    string password;
    string StudentReg;

    Admin *admin = new SuperAdmin("admin", "admin");
    adminVector.push_back(admin);
    // cout << toLowerCase("ABDULLAH") << endl;

    do
    {
        cout << "================================================================\n";
        cout << "                        Welcome\n";
        cout << "================================================================\n\n";
        cout << "Choose Any option:\n";
        cout << "\n1. Admin\n";
        cout << "\n2. Student\n";
        cout << "\n3. Exit\n";
        cout << "\nYour Selection:";
        saveAdmins();

        cin >> person;
        clearScreen();

        switch (person)
        {
        case 1:
            cout << "================================================================\n";
            cout << "                        Admin Panel\n";
            cout << "================================================================\n\n";
            cout << "Enter Username: ";
            cin >> username;
            index = usernameExistsAdmin(username);
            if (index != -1)
            {
                cout << "Enter password: ";
                cin >> password;
            }
            else
            {
                cout << "Username does not exist." << endl;
            }
            // to traverse the vector of admins and check if the username and password match

            if (adminVector[index]->getPassword() == password)
            {
                cout << "1. Change Username & Password" << endl;
                cout << "2. Add Sub-Admin" << endl;
                cout << "3. View Sub-Admins" << endl;
                cout << "4. Delete Sub-Admin" << endl;
                cout << "5. Enroll Student" << endl;
                cout << "6. Exit" << endl;
                cout << "Enter Choice: ";
                cin >> choice;
                char stroke;
                switch (choice)
                {
                case 1:
                    clearScreen();
                    cout << "================================================================\n";
                    cout << "                        Set Credentials\n";
                    cout << "================================================================\n\n";
                    adminVector[index]->setCredentials(username, password);
                    cout << "Enter Any Character to continue...";
                    cin >> stroke;
                    clearScreen();
                    break;
                case 2:
                    clearScreen();
                    cout << "================================================================\n";
                    cout << "                        Add SubAdmin\n";
                    cout << "================================================================\n\n";
                    ((SuperAdmin *)admin)->addSubAdmin();
                    cout << "Enter Any Character to continue...";
                    cin >> stroke;
                    clearScreen();
                    break;
                case 3:
                    clearScreen();
                    cout << "================================================================\n";
                    cout << "                        View SubAdmins\n";
                    cout << "================================================================\n\n";
                    ((SuperAdmin *)admin)->viewSubAdmins();

                    cout << "Enter Any Character to continue...";
                    cin >> stroke;
                    clearScreen();
                    break;
                case 4:
                    clearScreen();
                    cout << "================================================================\n";
                    cout << "                        Delete SubAdmin\n";
                    cout << "================================================================\n\n";
                    ((SuperAdmin *)admin)->deleteSubAdmin();
                    cout << "Enter Any Character to continue...";
                    cin >> stroke;
                    clearScreen();
                    break;
                case 5:
                    clearScreen();
                    cout << "================================================================\n";
                    cout << "                        Enroll Student\n";
                    cout << "================================================================\n\n";
                    admin->enrollStudent();
                    cout << "Enter Any Character to continue...";
                    cin >> stroke;
                    clearScreen();
                    break;
                case 6:
                    clearScreen();
                    cout << "Exiting Program";
                    for (int i = 0; i < 3; i++)
                    {
                        mySleep(1);

                        cout << ".";
                        cout.flush();
                    }
                    cout << endl;
                    return 0;

                default:
                    break;
                }
            }
            else
            {
                clearScreen();
                cout << "Invalid Password!" << endl;
                cout << "1. try again" << endl;
                cout << "2. Exit" << endl;
                cout << "Enter Choice: ";
                cin >> choice;
                if (choice == 1)
                {

                    break;
                }
                else
                {
                    return 0;
                }
            }
        case 2:

        {
            cout << "================================================================\n";
            cout << "                        Student Panel\n";
            cout << "================================================================\n\n";
            cout << "Enter Student Registration number: ";
            cin >> StudentReg;
            index = usernameExists(StudentReg);
            if (index != -1)
            {
                cout << "Enter password: ";
                cin >> password;
            }
            else
            {
                cout << "Student does not exist." << endl;
            }
            clearScreen();

            if (studentVector[index]->getPassword() == password)
            {
                cout << "================================================================\n";
                cout << "                        Student Panel\n";
                cout << "                   Authentication Successful!" << endl;
                cout << "================================================================\n\n";
                cout << "\n1-Go To Dashboard"
                     << "\n2-Overall Progress"
                     << "\n3-Change Password"
                     << "\n4-Exit";

                cout << "\nEnter Choice:";
                cin >> choice;

                switch (choice)
                {
                case 1:
                    clearScreen();
                    studentVector[index]->displayCourses();
                    cout << "Select Course:";
                    cin >> choice;
                    clearScreen();
                    if (choice > studentVector[index]->getCourses().size())
                    {
                        cout << "Invalid Choice!" << endl;
                        break;
                    }
                    cout << studentVector[index]->getCourses()[choice - 1] << endl;
                    break;
                case 2:
                    // 2 methods
                    // displayoverallprogress();
                    // displaycourses();
                    break;
                case 3:
                    clearScreen();
                    cout << "================================================================\n";
                    cout << "                        Set Credentials\n";
                    cout << "================================================================\n\n";
                    studentVector[index]->setCredentials(password);
                    break;

                case 4:
                    clearScreen();
                    saveStudents();
                    cout << "Program exited!" << endl;
                    return 0;
                default:
                    break;
                }
            }
            else
            {
                char stroke;
                clearScreen();
                cout << "Invalid Password!" << endl;
                cout << "1. try again" << endl;
                cout << "2. Exit" << endl;
                cout << "Enter Choice: ";
                cin >> choice;
                if (choice == 1)
                {
                    cin >> stroke;
                    clearScreen();
                    break;
                }
                else
                {
                    return 0;
                }
            }
        }
        break;
        case 3:
        {
            clearScreen();
            cout << "Exiting Program";
            for (int i = 0; i < 3; i++)
            {
                mySleep(1);

                cout << ".";
                cout.flush();
            }
            saveAdmins();
            saveStudents();
            cout << endl;
            return 0;
        }
        }
    } while (true);

    delete admin;
    // delete student;

    return 0;
}