#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

// Each book is stored as:
// bookID|title|author|totalCopies|availableCopies

bool bookExists(string id)
{
    ifstream file("books.txt");
    string line;

    while (getline(file, line))
    {
        stringstream ss(line);
        string storedID;
        getline(ss, storedID, '|');

        if (storedID == id)
        {
            return true;
        }
    }
    return false;
}

void addBook()
{
    string id, title, author;
    int copies;

    cout << "Enter book ID: ";
    getline(cin, id);

    if (id.empty() || bookExists(id))
    {
        cout << "Book ID is empty or already exists.\n";
        return;
    }

    cout << "Enter book title: ";
    getline(cin, title);
    cout << "Enter author name: ";
    getline(cin, author);
    cout << "Enter number of copies: ";

    if (!(cin >> copies) || copies <= 0)
    {
        cout << "Please enter a valid positive number of copies.\n";
        cin.clear();
        cin.ignore(10000, '\n');
        return;
    }
    cin.ignore(10000, '\n');

    ofstream file("books.txt", ios::app);
    file << id << "|" << title << "|" << author << "|"
         << copies << "|" << copies << "\n";

    cout << "Book added successfully.\n";
}

void displayBooks()
{
    ifstream file("books.txt");
    string line;
    bool found = false;

    cout << "\n--------------- BOOK LIST ---------------\n";
    cout << "ID\tTitle\t\tAuthor\t\tTotal\tAvailable\n";

    while (getline(file, line))
    {
        stringstream ss(line);
        string id, title, author, total, available;

        getline(ss, id, '|');
        getline(ss, title, '|');
        getline(ss, author, '|');
        getline(ss, total, '|');
        getline(ss, available, '|');

        cout << id << "\t" << title << "\t\t" << author
             << "\t\t" << total << "\t" << available << "\n";
        found = true;
    }

    if (!found)
    {
        cout << "No books found. Add some books first.\n";
    }
}