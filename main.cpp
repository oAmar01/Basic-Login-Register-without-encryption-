#include <iostream>
#include <stdlib.h>
#include <string>
#include <windows.h>
#include <fstream>

using namespace std;

ifstream userOut;
ofstream userIn;

void loginFunction() {

    bool userFound = false, passFound = false, loggedIn = false;
    string skipLine, loginUser, loginPass, userCheck, passCheck;
    do {
        cout << "Please Login: " << endl << "Username: ";
        cin >> loginUser;
        if (loginUser == "cancel" || loginUser == "Cancel") {
            exit(1);
        }
        cout << "Password: ";
        cin >> loginPass;
        userOut.open("DB.txt");
        if (!userOut.is_open()) {
            cout << "Error opening file";
            exit(1);
        }
        while (!userOut.eof()) {
            userOut >> userCheck;
            userOut >> passCheck;
            userOut >> skipLine;
            if (loginUser == userCheck && loginPass == passCheck) {
                cout << "Successfully logged in" << endl;
                loggedIn = true;
                Sleep(3000);
            }
            system("CLS");
        }
        if (loggedIn != true) {
            cout << "Incorrect user or password, please try again or enter cancel to exit." << endl;
            Sleep(1000);
            loggedIn = false;
        }

        userOut.close();
    } while (loggedIn == false);

}

void registerFunction() {

    bool alreadyRegistered = false, registered = false, invalidUser = false;
    string registerUser, registerPassword;
    cout << "Please register" << endl << "Please enter new username: ";
    do {
        cin >> registerUser;
        if (registerUser == "cancel" || registerUser == "Cancel") {
            invalidUser = true;
            cout << "Invalid username, please try again:";
        } else {
            invalidUser = false;
        }
    } while (invalidUser == true);
    cout << "Please enter new password: ";
    cin >> registerPassword;

    userIn.open("DB.txt", ios::app);

    if (!userIn.is_open()) {
        cout << "Error opening file" << endl;
        exit(1);
    }
    cout << "Successfully registered." << endl;
    userIn << registerUser << endl << registerPassword << endl << "------------------" << endl;
    Sleep(1000);
    userIn.close();

}

int main() {
    int choice = 0;
    do {
        system("CLS");
        cout << "Welcome, please enter 1 to login or 2 to register or 3 to exit." << endl;
        cin >> choice;
        while (cin.fail()) {
            cin.clear(); // clear input buffer to restore cin to a usable state
            cin.ignore(5, '\n'); // ignore last input
            cout << "Incorrect input, please try again" << endl;
            Sleep(1000);
            system("CLS");
            cout << "Welcome, please enter 1 to login or 2 to register or 3 to exit." << endl;
            cin >> choice;
        }
        switch (choice) {

        case 1:

            loginFunction();

            break;
        case 2:

            registerFunction();

            break;
        case 3:
            cout << "Goodbye!" << endl;
            Sleep(1000);
            return 0;
            break;
        default:

            cout << "Incorrect input, please try again" << endl;
            Sleep(1000);

            break;

        }
    } while (choice != 3);
}
