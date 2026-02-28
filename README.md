# LibraryManagementSystem
Detailed Description

This project is a Library Management System developed using C++. The system allows users to manage a collection of books through a menu-driven interface. Users can add new books, remove existing books, search for a book by ID, borrow books, return books, and display all books in the library.

The project uses a Singly Linked List data structure to store and manage book records dynamically. Each book is represented as a node containing the book ID, title, author, borrowed status, and a pointer to the next book.

The following DSA concepts were applied in this project:

Linked List (Singly Linked List)

Dynamic Memory Allocation

CRUD Operations (Create, Read, Update, Delete)

Object-Oriented Programming (Classes and Objects)

This problem was chosen to demonstrate how Linked Lists can be used in real-world applications where dynamic data storage is required. A library system is a practical example where records need to be added, removed, searched, and updated efficiently
Sample Input & Output
🔹 Sample Run 1 (Normal Flow)
========= Library Menu =========
1. Add Book
2. Remove Book
3. Search Book
4. Borrow Book
5. Return Book
6. Display All Books
7. Exit

Enter your choice: 1
Enter Book ID: 101
Enter Title: C++ Programming
Enter Author: Bjarne Stroustrup
Book added successfully.

Enter your choice: 6

===== Library Books =====
ID: 101 | Title: C++ Programming | Author: Bjarne Stroustrup | Status: Available
Sample Run 2 (Borrow & Return Flow)
Enter your choice: 4
Enter Book ID to borrow: 101
Book borrowed successfully.

Enter your choice: 6

===== Library Books =====
ID: 101 | Title: C++ Programming | Author: Bjarne Stroustrup | Status: Borrowed

Enter your choice: 5
Enter Book ID to return: 101
Book returned successfully.

Test Cases
1️⃣ Valid Input – Add Multiple Books

Add Book ID 101

Add Book ID 102

Display All Books
✔ Both books should appear.

2️⃣ Edge Case – Duplicate ID

Add Book ID 101

Try adding Book ID 101 again
✔ Should display: “Error: Book ID already exists.”

3️⃣ Edge Case – Remove Non-Existent Book

Try removing Book ID 999
✔ Should display: “Book not found.”

4️⃣ Edge Case – Borrow Already Borrowed Book

Borrow Book ID 101

Try borrowing Book ID 101 again
✔ Should display: “Book is already borrowed.”

5️⃣ Edge Case – Empty Library

Start program

Select Display All Books
✔ Should display: “Library is empty.”
