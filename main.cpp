#include <iostream>
#include <vector>
#include <fstream>
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
class Admin: public User
{
protected:
    vector<SubAdmin> SubAdminsVector;
public:
    // constructor
    Admin(string username, string password) : User(username, password) {}

    // virtal destructor will ensure proper destruction of objects of derived classes
    virtual ~Admin() {}

    virtual void addSubAdmin()  = 0;
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
    void addSubAdmin()  override
    {
        cout << "You are not a super-Admin" << endl;
    }

    // method to delete sub-admin
    void deleteSubAdmin()  override
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
    void addSubAdmin()  override
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

class Student
{

protected:
    string username;
    string password;
    vector<string> degree_programs = {"Computer Science", "Electrical Engineering", "Mechanical Engineering", "Civil Engineering", "Chemical Engineering"};

public:
    Student(string username, string password)
    {
        this->username = username;
        this->password = password;
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

class CS_Student : public Student
{
public:
    CS_Student(string username, string password) : Student(username, password)
    {
    }
};


class EE_Student;
class ME_Student;

int main()
{
    int person;
    string username, password;
    Admin *admin = new SuperAdmin("admin", "admin");
    // Student *student = new Student("student", "student");

    cout << "Enter 1 for Admin & 2 for Student Login: ";
    cin >> person;
    switch (person)
    {
    case 1:
        cout << "Enter Username: ";
        cin >> username;
        cout << "Enter Password: ";
        cin >> password;
        if (username == admin->getUsername() && password == admin->getPassword())
        {
            int choice;
            cout << "1. Change Username & Password" << endl;
            cout << "2. Add Sub-Admin" << endl;
            cout << "3. View Sub-Admins" << endl;
            cout << "4. Delete Sub-Admin" << endl;
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
        //     cout << "Enter Username: ";
        //     cin >> username;
        //     cout << "Enter Password: ";
        //     cin >> password;
        //     if (username == student->getUsername() && password == student->getPassword())
        //     {
        //         int choice;
        //         cout << "1. Change Username & Password" << endl;
        //         cout << "Enter Choice: ";
        //         cin >> choice;
        //         switch (choice)
        //         {
        //         case 1:
        //             student->setStudent(username, password);
        //             break;
        //         default:
        //             break;
        //         }
        //     }
        //     else
        //     {
        //         cout << "Invalid Username or Password!" << endl;
        //     }

        break;

    default:
        break;
    }

    delete admin;

    return 0;
}