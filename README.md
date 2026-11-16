# Library Management System (C++)

A console-based Library Management System developed in C++ for the MCA group assignment.

## Features
- Add and display books
- Search books by ID
- Register and display members
- Issue books to registered members
- Return issued books
- Display currently issued books
- Save records using text files

## Technologies
- C++
- STL (`string`, `fstream`, `sstream`)
- File handling

## Project structure
- `main.cpp` - menu and program execution
- `book.cpp` - book operations
- `member.cpp` - member operations
- `transaction.cpp` - issue and return operations

## Compile and run (Windows PowerShell)
Run these commands from the project directory:

```powershell
g++ main.cpp book.cpp member.cpp transaction.cpp -o Library.exe
.\Library.exe
```

The program creates and updates `books.txt`, `members.txt`, and `issued.txt` in the current working directory.

## Data format
- `books.txt`: book ID, title, author, total copies, available copies
- `members.txt`: member ID, name, phone
- `issued.txt`: member ID, book ID

Fields are separated by the `|` character. Do not enter `|` inside names or titles.
