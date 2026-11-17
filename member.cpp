#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

// Each member is stored as:
// memberID|memberName|phoneNumber

bool memberExists(string id) {
    ifstream file("members.txt");
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string storedID;
        getline(ss, storedID, '|');

        if (storedID == id) {
            return true;
        }
    }
    return false;
}

void addMember() {
    string id, name, phone;

    cout << "Enter member ID: ";
    getline(cin, id);

    if (id.empty() || memberExists(id)) {
        cout << "Member ID is empty or already exists.\n";
        return;
    }

    cout << "Enter member name: ";
    getline(cin, name);
    cout << "Enter phone number: ";
    getline(cin, phone);

    ofstream file("members.txt", ios::app);
    file << id << "|" << name << "|" << phone << "\n";

    cout << "Member registered successfully.\n";
}

void displayMembers() {
    ifstream file("members.txt");
    string line;
    bool found = false;

    cout << "\n--------------- MEMBER LIST ---------------\n";
    cout << "ID\tName\t\tPhone\n";

    while (getline(file, line)) {
        stringstream ss(line);
        string id, name, phone;

        getline(ss, id, '|');
        getline(ss, name, '|');
        getline(ss, phone, '|');

        cout << id << "\t" << name << "\t\t" << phone << "\n";
        found = true;
    }

    if (!found) {
        cout << "No members registered yet.\n";
    }
}

