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
#include "Quiz.h"        // Include the Quiz header file
#include "QuizManager.h" // Include the QuizManager header file

using namespace std;

// Forward Declarations
class User;
class SubAdmin;
class Admin;
class SuperAdmin;
class Student;

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
    QuizManager quizManager(quizzes);
    Quiz *quiz;
    Admin *admin = new SuperAdmin("admin", "admin");
    adminVector.push_back(admin);

    loadAdmins();
    loadStudents();

    clearScreen();

    cout << "Program is starting..." << endl;
    for (int i = 0; i < 5; i++)
    {
        mySleep(1);

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

    mySleep(1);

    clearScreen();

    int person;
    int choice;
    int index;
    char login = false;
    string username;
    string password;
    string StudentReg;

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
                break;
            }
            // to traverse the vector of admins and check if the username and password match

            if (adminVector[index]->getPassword() == password)
            {
                login = true;

                do
                {
                    cout << "1. Change Username & Password" << endl;
                    cout << "2. Add Sub-Admin" << endl;
                    cout << "3. View Sub-Admins" << endl;
                    cout << "4. Delete Sub-Admin" << endl;
                    cout << "5. Enroll Student" << endl;
                    cout << "6. Logout" << endl;
                    cout << "Enter Choice: ";
                    cin >> choice;
                    char stroke;
                    switch (choice)
                    {
                        cout << "switch inside admin if";
                        mySleep(1);
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
                        adminVector[index]->addSubAdmin();
                        cout << "Enter Any Character to continue...";
                        cin >> stroke;
                        clearScreen();
                        break;
                    case 3:
                        clearScreen();
                        cout << "================================================================\n";
                        cout << "                        View SubAdmins\n";
                        cout << "================================================================\n\n";
                        adminVector[index]->viewSubAdmins();
                        cout << "Enter Any Character to continue...";
                        cin >> stroke;
                        clearScreen();
                        break;
                    case 4:
                        clearScreen();
                        cout << "================================================================\n";
                        cout << "                        Delete SubAdmin\n";
                        cout << "================================================================\n\n";
                        adminVector[index]->deleteSubAdmin();
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
                        cout << "/logging out " << endl;
                        login = false;
                        break;

                    default:
                        break;
                    }

                } while (login);
            }
            else
            {
                clearScreen();
                cout << "Invalid Password!" << endl;
                login = false;
                break;
            }
            break;
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
                break;
            }

            if (studentVector[index]->getPassword() == password)
            {
                do
                {
                    login = true;

                    cout << "================================================================\n";
                    cout << "                        Student Panel\n";
                    cout << "                   Authentication Successful!" << endl;
                    cout << "================================================================\n\n";
                    cout << "\n1-Go To Dashboard"
                         << "\n2-Overall Progress"
                         << "\n3-Change Password"
                         << "\n4-Log out";

                    cout << "\nEnter Choice:";
                    cin >> choice;

                    switch (choice)
                    {
                    case 1:
                        clearScreen();
                        studentVector[index]->displayCourses();
                        cout << "Select Course (-1 to go back):";
                        cin >> choice;
                        clearScreen();
                        if (choice > studentVector[index]->getCourses().size() && choice != -1)
                        {
                            cout << "Invalid Choice!" << endl;
                            break;
                        }
                        else if (choice < 0)
                        {
                            break;
                        }
                        else
                        {
                            cout << studentVector[index]->getCoursesCodes()[choice - 1] << endl;
                            quiz = quizManager.selectCourse(studentVector[index]->getCoursesCodes()[choice - 1]);
                            quizManager.startQuiz(quiz);
                        }
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
                        cout << "Logging out" << endl;
                        login = false;
                        break;

                    default:
                        break;
                    }
                } while (login);
            }
            else
            {
                char stroke;
                clearScreen();
                cout << "Invalid Password!" << endl;
                login = false;
                break;
            }
            break;
        }
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