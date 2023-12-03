#include<iostream>
using namespace std;

// Class definition for Admin
class Admin {
    private:
        string username;
        string password;
    public:
        // Constructor to initialize the username and password
        Admin(string username, string password) {
            this->username = username;
            this->password = password;
        }

        // Getter method for retrieving the username
        string getUsername() {
            return this->username;
        }

        // Getter method for retrieving the password
        string getPassword() {
            return this->password;
        }

        // Method to update the admin credentials
        void setAdmin(string username, string password) {
            cout << "Enter Old Username: ";
            string oldUsername;
            cin >> oldUsername;

            cout << "Enter Old Password: ";
            string oldPassword;
            cin >> oldPassword;

            // Check if the old username and password match the current ones
            if (oldUsername == this->username && oldPassword == this->password) {
                cout << "Enter New Username: ";
                cin >> username;

                cout << "Enter New Password: ";
                cin >> password;

                // Update the username and password
                this->username = username;
                this->password = password;

                cout << "Username and Password Changed Successfully!" << endl;
            } else {
                cout << "Username and Password Not Changed!" << endl;
            }
        }
};

// Main function
int main() {
    // Create an instance of the Admin class with initial credentials
    Admin SuperAdmin("S", "S");

    // Display the initial credentials
    cout << "Username: " << SuperAdmin.getUsername() << endl;
    cout << "Password: " << SuperAdmin.getPassword() << endl;

    // Call the setAdmin method to update credentials
    SuperAdmin.setAdmin("SuperAdmin", "SuperAdmin");

    // Display the updated credentials
    cout << "Username: " << SuperAdmin.getUsername() << endl;
    cout << "Password: " << SuperAdmin.getPassword() << endl;

    return 0;
}
