#include<iostream>
using namespace std;

class Admin {
    private:
        string username;
        string password;
    public:
        Admin(string username, string password) {
            this->username = username;
            this->password = password;
        }
        string getUsername() {
            return this->username;
        }
        string getPassword() {
            return this->password;
        }
        void setAdmin(string username, string password) {
            cout << "Enter Old Username: ";
            string oldUsername;
            cin >> oldUsername;
            cout << "Enter Old Password: ";
            string oldPassword;
            cin >> oldPassword;
            if (oldUsername == this->username && oldPassword == this->password) {
                cout << "Enter New Username: ";
                cin >> username;
                cout << "Enter New Password: ";
                cin >> password;
                this->username = username;
                this->password = password;
                cout << "Username and Password Changed Successfully!" << endl;
            } else {
                cout << "Username and Password Not Changed!" << endl;
            }
        }
};

int main() {
    Admin SuperAdmin("S", "S");
    cout << "Username: " << SuperAdmin.getUsername() << endl;
    cout << "Password: " << SuperAdmin.getPassword() << endl;
    SuperAdmin.setAdmin("SuperAdmin", "SuperAdmin");
    cout << "Username: " << SuperAdmin.getUsername() << endl;
    cout << "Password: " << SuperAdmin.getPassword() << endl;
    return 0;
}
