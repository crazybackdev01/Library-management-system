#include <iostream>
#include <string>
#include <limits>
using namespace std;

// Functions implemented in book.cpp
void addBook();
void displayBooks();
void searchBook();

// Functions implemented in member.cpp
void addMember();
void displayMembers();

// Functions implemented in transaction.cpp
void issueBook();
void returnBook();
void displayIssuedBooks();

int main()
{
    int choice;

    do
    {
        cout << "\n========== LIBRARY MANAGEMENT SYSTEM ==========\n";
        cout << "1. Add Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Search Book\n";
        cout << "4. Register Member\n";
        cout << "5. Display Members\n";
        cout << "6. Issue Book\n";
        cout << "7. Return Book\n";
        cout << "8. Display Issued Books\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice))
        {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice)
        {
        case 1:
            addBook();
            break;
        case 2:
            displayBooks();
            break;
        case 3:
            searchBook();
            break;
        case 4:
            addMember();
            break;
        case 5:
            displayMembers();
            break;
        case 6:
            issueBook();
            break;
        case 7:
            returnBook();
            break;
        case 8:
            displayIssuedBooks();
            break;
        case 0:
            cout << "Thank you for using the Library Management System!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
