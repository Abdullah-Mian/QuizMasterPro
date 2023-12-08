#include <iostream>
#include <vector>
#include <fstream>
#include <list>

// Check if the operating system is Windows to use the sleep function
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif
/*
//OS-Independent Includes for Full Screen
#ifdef _WIN32
    #include <windows.h>
#elif __linux__
    #include <ncurses.h>
#endif
*/
using namespace std;

/*//Console FullScreen Function
void setConsoleFullScreen() {
#ifdef _WIN32
    HWND console = GetConsoleWindow();
    ShowWindow(console, SW_MAXIMIZE); // Maximize the console window
#elif __linux__
    initscr(); // initialize the library
    raw(); // disable line buffering
    keypad(stdscr, TRUE); // enable special keys

    if (has_colors()) {
        start_color();
        init_pair(1, COLOR_WHITE, COLOR_BLACK);
        attron(COLOR_PAIR(1));
    }

    clear(); // clear the screen
    refresh(); // refresh the screen
#endif
}

void cleanup() {
#ifdef __linux__
    endwin(); // clean up and restore terminal settings
#endif
}*/

// Function to introduce a delay using sleep
void mySleep(int seconds)
{
#ifdef _WIN32
    Sleep(seconds * 1000); // Sleep takes milliseconds on Windows
#else
    sleep(seconds); // Sleep takes seconds on Unix-based systems
#endif
}

// Forward Declarations
class User;
class SubAdmin;
class Admin;
class SuperAdmin;
class Student;

// Abstract Class
class Admin
{
protected:
    string username;
    string password;
    vector<SubAdmin> SubAdminsVector;

public:
    // constructor
    Admin(string username, string password) : username(username), password(password) {}

    // virtual destructor will ensure proper destruction of objects of derived classes
    virtual ~Admin() {}

    // pure virtual methods
    virtual void addSubAdmin() = 0;         // method to add sub-admin
    virtual void deleteSubAdmin() = 0;      // method to delete sub-admin
    virtual void viewSubAdmins() const = 0; // method to view sub-admins

    // method to set credentials
    virtual void setCredentials(string newUsername, string newPassword)
    {
        cout << "Enter Old Username: ";
        string oldUsername;
        cin >> oldUsername;
        cout << "Enter Old Password: ";
        string oldPassword;
        cin >> oldPassword;
        if (oldUsername == this->username && oldPassword == this->password)
        {
            cout << "Enter New Username: ";
            cin >> newUsername;
            cout << "Enter New Password: ";
            cin >> newPassword;
            this->username = newUsername;
            this->password = newPassword;
            cout << "Username and Password Changed Successfully!" << endl;
        }
        else
        {
            cout << "Username and Password Not Changed!" << endl;
        }
    }

    // method to get username
    string getUsername() const
    {
        return this->username;
    }

    // method to get password
    string getPassword() const
    {
        return this->password;
    }
};

// SubAdmin class with authority only over Student
class SubAdmin : public Admin
{
public:
    SubAdmin(string username, string password) : Admin(username, password)
    {
        SubAdminsVector.push_back(*this);
    }

    // method to view sub-admins
    void viewSubAdmins() const override
    {
        cout << "You are not a super-Admin" << endl;
    };

    // method to add sub-admin
    void addSubAdmin() override
    {
        cout << "You are not a super-Admin" << endl;
    }

    // method to delete sub-admin
    void deleteSubAdmin() override
    {
        cout << "You are not a super-Admin" << endl;
    }
};

// SuperAdmin class having authority to add, delete and view sub-admins
class SuperAdmin : public Admin
{
public:
    SuperAdmin(string username, string password) : Admin(username, password) {}

    // method to add sub-admin
    void addSubAdmin() override
    {
        string username, password;
        bool exists = false;

        do
        {
            exists = false; // flag to check if sub-admin already exists

            // asking for username and password
            cout << "Enter Username: ";
            cin >> username;
            cout << "Enter Password: ";
            cin >> password;

            // checking if sub-admin already exists
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

        // adding sub-admin
        SubAdminsVector.push_back(SubAdmin(username, password));
        cout << "Sub-Admin Added Successfully!" << endl;
    }

    // method to view sub-admins
    void viewSubAdmins() const override
    {
        cout << "Sub-Admins: " << endl;
        for (int i = 0; i < SubAdminsVector.size(); i++)
        {
            cout << "Username: " << SubAdminsVector[i].getUsername() << endl;
        }
    };

    // method to delete sub-admin
    void deleteSubAdmin() override
    {
        string username;

        // displaying all sub-admins
        viewSubAdmins();

        // asking for username to delete
        cout << "Enter Username: ";
        cin >> username;

        // searching for sub-admin
        for (int i = 0; i < SubAdminsVector.size(); i++)
        {
            if (SubAdminsVector[i].getUsername() == username)
            {
                // asking for confirmation
                cout << "Do you want to delete " << username << " ? (y/n): ";
                char choice;
                cin >> choice;
                if (choice == 'y')
                {
                    // deleting sub-admin
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
};

// Abstract Student class
class Student
{

protected:
    string registration;
    string password;
    vector<string> degree_programs = {"Computer Science", "Electrical Engineering", "Software Engineering", "Computer Engineering", "Chemical Engineering"};

public:
    Student(string password, string registration) : password(password), registration(registration) {}

    // method to get registration
    string getRegistration() const
    {
        return this->registration;
    }

    // pure virtual methods
    virtual void displayCourses() const = 0;         // method to display courses
    virtual void displayOverallProgress() const = 0; // method to display overall progress

    // method to set credentials
    virtual void setCredentials(string newPassword)
    {
        cout << "Enter Old Password: ";
        string oldPassword;
        cin >> oldPassword;
        if (oldPassword == this->password)
        {
            cout << "Enter New Password: ";
            cin >> newPassword;
            this->password = newPassword;
            cout << "Password Changed Successfully!" << endl;
        }
        else
        {
            cout << "Password Not Changed!" << endl;
        }
    }

    // method to get password
    string getPassword() const
    {
        return this->password;
    }
};

// CS_student class
class CS_Student : public Student
{
private:
    string degreeprogram = degree_programs[0];
    list<string> courses = {"Introduction to Computer Science (CS 101)", "Data Structures and Algorithms (CS 201)", "Computer Organization and Architecture (CS 220)", "Database Management Systems (CS 301)", "Operating Systems (CS 330)", "Software Engineering (CS 401)"};

public:
    CS_Student(string password, string registration)
        : Student(password, registration) {}

    // method to display courses
    void displayCourses() const override
    {
        // Display list of courses
    }

    void displayOverallProgress() const override
    {
        // Display overall progress
    }
};

// EE_student class
class EE_Student : public Student
{
private:
    string degreeprogram = degree_programs[1];
    list<string> courses = {"Circuit Analysis (Course Code: EE101)", "Digital Electronics (Course Code: EE204)", "Electromagnetic Fields and Waves (Course Code: EE301)", "Power Systems Analysis (Course Code: EE402)", "Control Systems (Course Code: EE501)", "Electronics and VLSI Design (Course Code: EE601)"};

public:
    EE_Student(string password, string registration)
        : Student(password, registration) {}

    // method to display courses
    void displayCourses() const override
    {
        // Display list of courses
    }

    void displayOverallProgress() const override
    {
        // Display overall progress
    }
};

// SE_student class
class SE_Student : public Student
{
private:
    string degreeprogram = degree_programs[1];
    list<string> courses = {"Introduction to Software Engineering (Course Code: SE101)", "Object-Oriented Programming (Course Code: SE201)", "Software Requirements and Analysis (Course Code: SE301)", "Software Design and Architecture (Course Code: SE401)", "Software Testing and Quality Assurance (Course Code: SE501)", "Software Project Management (Course Code: SE601)"};

public:
    SE_Student(string password, string registration)
        : Student(password, registration) {}

    // method to display courses
    void displayCourses() const override
    {
        // Display list of courses
    }

    void displayOverallProgress() const override
    {
        // Display overall progress
    }
};

// CE_student class
class CE_Student : public Student
{
private:
    string degreeprogram = degree_programs[1];
    list<string> courses = {"Digital Logic Design (ECE 201)", "Embedded Systems (ECE 415)", "Computer Organization and Architecture (ECE 301)", "Digital Signal Processing (ECE 440)", "Electronics (ECE 320)", "Computer Networks (ECE 401)"};

public:
    // Constructor
    CE_Student(string password, string registration)
        : Student(password, registration) {}

    // method to display courses
    void displayCourses() const override
    {
        // Display list of courses
    }

    void displayOverallProgress() const override
    {
        // Display overall progress
    }
};

// CHE_student class
class CHE_Student : public Student
{
private:
    string degreeprogram = degree_programs[1];
    list<string> courses = {"Introduction to Chemical Engineering (CHE 101)", "Chemical Thermodynamics (CHE 201)", "Mass Transfer and Separation Processes (CHE 301)", "Chemical Reaction Engineering (CHE 320)", "Process Control and Instrumentation (CHE 410)", "Design of Chemical Processes (CHE 420)"};

public:
    // constructor
    CHE_Student(string password, string registration)
        : Student(password, registration) {}

    // method to display courses
    void displayCourses() const override
    {
        // Display list of courses
    }

    void displayOverallProgress() const override
    {
        // Display overall progress
    }
};

int main()
{
    // setConsoleFullScreen();
    // Clear screen and print message
#ifdef _WIN32
    system("cls");
#elif defined(__linux__)
    system("clear");
#endif

    cout << "Program is starting..." << endl;
    for (int i = 0; i < 5; i++)
    {
        mySleep(1);

        cout << "=";
        cout.flush();
    }
    // Clear screen and print message
#ifdef _WIN32
    system("cls");
#elif defined(__linux__)
    system("clear");
#endif

    cout << R"(
____ _  _ _ ___  _  _ ____ ____ ___ ____ ____ ___  ____ ____ 
|  | |  | |   /  |\/| |__| [__   |  |___ |__/ |__] |__/ |  | 
|_\| |__| |  /__ |  | |  | ___]  |  |___ |  \ |    |  \ |__| 
                                                             
)" << endl;

    mySleep(1);

// Clear screen and print message
#ifdef _WIN32
    system("cls");
#elif defined(__linux__)
    system("clear");
#endif

    int person;
    int choice;
    string username, password, registration;
    Admin *admin = new SuperAdmin("admin", "admin");
    Student *student = new CS_Student("student", "CS123");

    do
    {
        cout << "Enter 1 for Admin & 2 for Student Login: ";
        cin >> person;
// Clear screen and print message
#ifdef _WIN32
        system("cls");
#elif defined(__linux__)
        system("clear");
#endif

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
                    // Clear screen and print message
#ifdef _WIN32
                    system("cls");
#elif defined(__linux__)
                    system("clear");
#endif
                    cout << "Program exited!" << endl;
                    // cleanup();//To restore console to normal state
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

    // cleanup();//To restore console to normal state

    return 0;
}