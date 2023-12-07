#include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace std;

class User;
class SubAdmin;
class Admin;
class SuperAdmin;
class Student;

// Abstract Class
class User
{
protected:
    string username;
    string password;

public:
    // constructor
    User(string username, string password) : username(username), password(password) {}

    // virtual destructor will ensure proper destruction of objects of derived classes
    virtual ~User() {}

    // pure virtual function
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

// Abstract Class
class Admin : public User
{
protected:
    vector<SubAdmin> SubAdminsVector;

public:
    // constructor
    Admin(string username, string password) : User(username, password) {}

    // virtual destructor will ensure proper destruction of objects of derived classes
    virtual ~Admin() {}

    virtual void addSubAdmin() = 0;
    virtual void deleteSubAdmin() = 0;
    virtual void viewSubAdmins() const = 0;
};

// Derived Class from Admin
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

// Derived Class from Admin
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

        // displaing all sub-admins
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

class Student : public User
{

protected:
    string registration;
    vector<string> degree_programs = {"Computer Science", "Electrical Engineering", "Software Engineering",
                                      "Computer Engineering", "Chemical Engineering"};

public:
    Student(string password, string registration)
        : User("", password), registration(registration) {}

    // method to get registration
    string getRegistration() const
    {
        return this->registration;
    }

    virtual void displayCourses() const = 0;
    virtual void displayOverallProgress() const = 0;
};

// inherited CS_student class
class CS_Student : public Student
{
private:
    string degreeprogram = degree_programs[0];
    list<string> courses = {"Introduction to Computer Science (CS 101)", "Data Structures and Algorithms (CS 201)",
                            "Computer Organization and Architecture (CS 220)", "Database Management Systems (CS 301)",
                            "Operating Systems (CS 330)", "Software Engineering (CS 401)"};

public:
    // construcotr
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

// inherited CE_student class
class CE_Student : public Student
{
private:
    string degreeprogram = degree_programs[1];
    list<string> courses = {"Digital Logic Design (ECE 201)", "Embedded Systems (ECE 415)",
                            "Computer Organization and Architecture (ECE 301)", "Digital Signal Processing (ECE 440)",
                            "Electronics (ECE 320)", "Computer Networks (ECE 401)"};

public:
    // construcotr
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

// inherited CHE_student class for chemical Engineering
class CHE_Student : public Student
{
private:
    string degreeprogram = degree_programs[1];
    list<string> courses = {"Introduction to Chemical Engineering (CHE 101)", "Chemical Thermodynamics (CHE 201)",
                            "Mass Transfer and Separation Processes (CHE 301)", "Chemical Reaction Engineering (CHE 320)",
                            "Process Control and Instrumentation (CHE 410)", "Design of Chemical Processes (CHE 420)"};

public:
    // construcotr
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
    int person;
    int choice;
    string username, password, registration;
    Admin *admin = new SuperAdmin("admin", "admin");
    Student *student = new CS_Student("student", "CS123");

    cout << "Enter 1 for Admin & 2 for Student Login: ";
    cin >> person;
    switch (person)
    {
        // case for Admin panel
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
        // case for Student panel
    case 2:
        cout << "Enter Username: ";
        cin >> username;
        cout << "Enter Password: ";
        cin >> password;
        if (username == student->getUsername() && password == student->getPassword())
        {

            cout << "1. Change Username & Password):" << endl;
            cout << "2. Go To Dashboard):" << endl;
            cout << "Enter Choice: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                student->setCredentials(username, password);
                break;
            case 2:
                student->setCredentials(username, password);
                break;
            default:
                break;
            }
        }
        else
        {
            cout << "Invalid Username or Password!" << endl;
        }

        cout << "\n1-Go To Dashboard): \n2-Overall Progress): ";
        cout << "\n3-Change Password):\n";

        cout << "\nEnter Choice: \n";
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

    delete admin;
    delete student;

    return 0;
}
