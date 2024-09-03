#include <bits/stdc++.h>

using namespace std;

void Login();

void Register(){
    string username, password, stored_username, stored_password;
    bool usernameExists = false;
    char choice;

    cout << "Enter username: ";
    cin >> username;

    ifstream file("data.txt");
    if(file.is_open()){
        while(file >> stored_username >> stored_password){
            if(stored_username == username){
                usernameExists = true;
                break;
            }
        }
        file.close();
    }
    if(usernameExists){
        cout << "Username already exists. Do you want to login? (y/n): ";
        while(cin >> choice){
            if(choice == 'y' || choice == 'Y'){
                Login();
                break;
            }
            else if(choice == 'n' || choice == 'N'){
                cout << "Registration canceled." << endl;
                return;
            }
            else cout << "Invalid option! Please choose y or n." << endl;
        }
    }
    else{
        cout << "Create a password: ";
        cin >> password;
        ofstream file("data.txt", ios::app);
        file << username << " " << password << endl;
        file.close();
        cout << "Registration successful." << endl;
        return;
    }
}

void Login(){
    string username, password, stored_username, stored_password;
    bool usernameExists = false;
    char choice;

    cout << "Enter username: ";
    cin >> username;
    ifstream file("data.txt");
    while(file >> stored_username >> stored_password){
        if(stored_username == username){
            usernameExists = true;
            cout << "Enter password: ";
            cin >> password;
            if(stored_password == password){
                cout << "Login successful!" << endl;
                file.close();
                return;
            }
            else{
                cout << "Incorrect password. Please try again." << endl;
                return;
            }
        }
    }
    if(!usernameExists){
        cout << "Username does not exist. Do you want to register? (y/n): ";
        cin >> choice;
        if(choice == 'y' || choice == 'Y'){
            Register();
        }
        else{
            cout << "Login canceled." << endl;
            return;
        }
    }
}

int main()
{
    char option;
    cout << "1. Register\n2. Login\nWelcome! Please choose an option (1/2): ";
    while(cin >> option){
        if(option == '1'){
            Register();
            break;
        }
        else if(option == '2'){
            Login();
            break;
        }
        else cout << "Invalid selection! Please choose 1 or 2." << endl;
    }
    return 0;
}

