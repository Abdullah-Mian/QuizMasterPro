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


#include <iostream>
#include <vector>
#include <fstream>
#include <list>

#include "Admin.h"
#include "SubAdmin.h"
#include "SuperAdmin.h"
#include "Student.h"
#include "Sleep.h"  // Include the Sleep header file
#include "ClearScreen.h" // Include the ClearScreen header file

// Forward Declarations
class User;
class SubAdmin;
class Admin;
class SuperAdmin;
class Student;

//     list<string> courses = {"Introduction to Computer Science (CS 101)", "Data Structures and Algorithms (CS 201)", "Computer Organization and Architecture (CS 220)", "Database Management Systems (CS 301)", "Operating Systems (CS 330)", "Software Engineering (CS 401)"};

//     list<string> courses = {"Circuit Analysis (Course Code: EE101)", "Digital Electronics (Course Code: EE204)", "Electromagnetic Fields and Waves (Course Code: EE301)", "Power Systems Analysis (Course Code: EE402)", "Control Systems (Course Code: EE501)", "Electronics and VLSI Design (Course Code: EE601)"};

//     list<string> courses = {"Introduction to Software Engineering (Course Code: SE101)", "Object-Oriented Programming (Course Code: SE201)", "Software Requirements and Analysis (Course Code: SE301)", "Software Design and Architecture (Course Code: SE401)", "Software Testing and Quality Assurance (Course Code: SE501)", "Software Project Management (Course Code: SE601)"};

//     list<string> courses = {"Digital Logic Design (ECE 201)", "Embedded Systems (ECE 415)", "Computer Organization and Architecture (ECE 301)", "Digital Signal Processing (ECE 440)", "Electronics (ECE 320)", "Computer Networks (ECE 401)"};

//     list<string> courses = {"Introduction to Chemical Engineering (CHE 101)", "Chemical Thermodynamics (CHE 201)", "Mass Transfer and Separation Processes (CHE 301)", "Chemical Reaction Engineering (CHE 320)", "Process Control and Instrumentation (CHE 410)", "Design of Chemical Processes (CHE 420)"};


int main()
{
    clearScreen();

    cout << "Program is starting..." << endl;
    for (int i = 0; i < 5; i++)
    {
        mySleep(1);

        cout << "=";
        cout.flush();
    }
    clearScreen();

    cout << R"(
____ _  _ _ ___  _  _ ____ ____ ___ ____ ____ ___  ____ ____ 
|  | |  | |   /  |\/| |__| [__   |  |___ |__/ |__] |__/ |  | 
|_\| |__| |  /__ |  | |  | ___]  |  |___ |  \ |    |  \ |__| 
                                                             
)" << endl;

    mySleep(1);

    clearScreen();

    int person;
    int choice;
    string username, password, registration;
    Admin *admin = new SuperAdmin("admin", "admin");
    Student *student = new Student("student", "CS123", "CS");

    do
    {
        cout << "Enter 1 for Admin & 2 for Student Login: ";
        cin >> person;
    clearScreen();

        switch (person)
        {
        case 1:
            cout << "Enter Username: ";
            cin >> username;
            cout << "Enter Password: ";
            cin >> password;
            if (username == admin->getUsername() && password == admin->getPassword())
            {
                cout << "1. Change Username & Password" << endl;
                cout << "2. Add Sub-Admin" << endl;
                cout << "3. View Sub-Admins" << endl;
                cout << "4. Delete Sub-Admin" << endl;
                cout << "5. Exit" << endl;
                cout << "Enter Choice: ";
                cin >> choice;
                switch (choice)
                {
                case 1:
                    admin->setCredentials(username, password);
                    break;
                case 2:
                    ((SuperAdmin *)admin)->addSubAdmin();
                    break;
                case 3:
                    ((SuperAdmin *)admin)->viewSubAdmins();
                    break;
                case 4:
                    ((SuperAdmin *)admin)->deleteSubAdmin();
                    break;
                case 5:
                    clearScreen();
                    cout << "Program exited!" << endl;
                    return 0;

                default:
                    break;
                }
            }
            else
            {
                cout << "Invalid Username or Password!" << endl;
            }
            break;
        case 2:

            cout << "\n1-Go To Dashboard"
                 << "\n2-Overall Progress"
                 << "\n3-Change Password";

            cout << "\nEnter Choice:";
            cin >> choice;

            switch (choice)
            {
            case 1:
                // student.displaycourses();
                break;
            case 2:
                // 2 methods
                // displayoverallprogress();
                // displaycourses();
                break;
            case 3:
                break;
            default:
                break;
            }

            break;

        default:
            break;
        }
    } while (true);

    delete admin;
    delete student;

    return 0;
}