#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void clearFile(const string& filename) {
    ofstream clearAllFiles(filename, ios::trunc);
    clearAllFiles.close();
}

int main() {
    ofstream writePass("passwords.txt", ios::app);
    writePass << "<<<<< PASSWORD SAVER >>>>>" << endl;
    writePass.close();
    ifstream readPass("passwords.txt");
    int choose;
    string newPass;
    string userName;
    string platform;
    string line;
    string searchKeyword;
    bool found = false;
    
    cout << "<<<<<<<<< WELCOME >>>>>>>>" << endl;
    cout << "<<<<<< PASSWORDS SAVER >>>>>>\n\n" << endl;

    do {
        cout << "<<< Please select an action to perform >>>" << endl;
        cout << "<<< 1.) List All Passwords" << endl;
        cout << "<<< 2.) Add a New Passwords" << endl;
        cout << "<<< 3.) Search Passwords" << endl;
        cout << "<<< 4.) Clear ALL Contents" << endl;
        cout << "<<< 5.) Log out" << endl;
        cout << "<<<: ";
        cin >> choose;
        
        switch(choose) {
            case 1:
                cout << " <<< All Saved Passwords >>> " << endl;
                readPass.clear();
                readPass.seekg(0, ios::beg);
                while (getline(readPass, line)) {
                    if(line.find("<<<<< PASSWORD SAVER >>>>>") == string::npos) { 
                        cout << line << endl;
                    }
                }
                break;
            case 2:
                cout << "Add a New Passwords Column" << endl;
                writePass.open("passwords.txt", ios::app);
                cout << "<<< PLATFORM: ";
                cin.ignore();
                getline(cin, platform);
                cout << "<<< USERNAME: ";
                getline(cin, userName);
                cout << "<<< PASSWORD: ";
                getline(cin, newPass);
                writePass << platform << " " << userName << " " << newPass << endl;
                cout << "The new password line has been successfully added.\n" << endl;
                writePass.close();
                break;
            case 3:
                cout << "Search Password" << endl;
                cout << "Enter platform or username to search for: ";
                cin.ignore();
                getline(cin, searchKeyword);
                readPass.clear();
                readPass.seekg(0, ios::beg);
                found = false;
                while (getline(readPass, line)) {
                    if (line.find(searchKeyword) != string::npos && line != "<<<<< PASSWORD SAVER >>>>>") {
                        cout << "Matching line found: " << line << endl;
                        found = true; 
                    }
                }
                if (!found) {
                    cout << "No matching password/platform found." << endl;
                }
                break;
            case 4:
                clearFile("passwords.txt");
                cout << "The content of passwords.txt has been cleared." << endl;
                break;
            case 5:
                cout << "Exiting..." << endl;
                readPass.close();
                writePass.close();
                break;
            default:
                cout << "Please enter a valid value." << endl; 
                break;
        }
    } while (choose != 5);
    return 0;
}