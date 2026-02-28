#include <iostream>
#include <string>
#include <limits>

using namespace std;

// ======= Book Class ========
class Book {
public:
    int id;
    string title;
    string author;
    bool isBorrowed;
    Book* next;

    Book(int id, string title, string author) {
        this->id = id;
        this->title = title;
        this->author = author;
        this->isBorrowed = false;
        this->next = nullptr;
    }
};

// ========== Library Class ==========
class Library {
private:
    Book* head;

public:
    Library() {
        head = nullptr;
    }

    // Add Book
    void addBook() {
        int id;
        string title, author;

        cout << "Enter Book ID: ";
        cin >> id;

        // Check duplicate ID
        Book* temp = head;
        while (temp != nullptr) {
            if (temp->id == id) {
                cout << "Error: Book ID already exists.\n";
                return;
            }
            temp = temp->next;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter Title: ";
        getline(cin, title);

        cout << "Enter Author: ";
        getline(cin, author);

        Book* newBook = new Book(id, title, author);

        // Insert at end
        if (head == nullptr) {
            head = newBook;
        } else {
            temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newBook;
        }

        cout << "Book added successfully.\n";
    }

    // Remove Book
    void removeBook() {
        if (head == nullptr) {
            cout << "Library is empty.\n";
            return;
        }

        int id;
        cout << "Enter Book ID to remove: ";
        cin >> id;

        Book* temp = head;
        Book* prev = nullptr;

        while (temp != nullptr && temp->id != id) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Book not found.\n";
            return;
        }

        if (prev == nullptr) {
            head = temp->next;
        } else {
            prev->next = temp->next;
        }

        delete temp;
        cout << "Book removed successfully.\n";
    }

    // Search Book
    void searchBook() {
        if (head == nullptr) {
            cout << "Library is empty.\n";
            return;
        }

        int id;
        cout << "Enter Book ID to search: ";
        cin >> id;

        Book* temp = head;

        while (temp != nullptr) {
            if (temp->id == id) {
                cout << "\nBook Found:\n";
                cout << "ID: " << temp->id << endl;
                cout << "Title: " << temp->title << endl;
                cout << "Author: " << temp->author << endl;
                cout << "Status: " << (temp->isBorrowed ? "Borrowed" : "Available") << endl;
                return;
            }
            temp = temp->next;
        }

        cout << "Book not found.\n";
    }

    // Borrow Book
    void borrowBook() {
        if (head == nullptr) {
            cout << "Library is empty.\n";
            return;
        }

        int id;
        cout << "Enter Book ID to borrow: ";
        cin >> id;

        Book* temp = head;

        while (temp != nullptr) {
            if (temp->id == id) {
                if (temp->isBorrowed) {
                    cout << "Book is already borrowed.\n";
                } else {
                    temp->isBorrowed = true;
                    cout << "Book borrowed successfully.\n";
                }
                return;
            }
            temp = temp->next;
        }

        cout << "Book not found.\n";
    }

    // Return Book
    void returnBook() {
        if (head == nullptr) {
            cout << "Library is empty.\n";
            return;
        }

        int id;
        cout << "Enter Book ID to return: ";
        cin >> id;

        Book* temp = head;

        while (temp != nullptr) {
            if (temp->id == id) {
                if (!temp->isBorrowed) {
                    cout << "Book is already returned.\n";
                } else {
                    temp->isBorrowed = false;
                    cout << "Book returned successfully.\n";
                }
                return;
            }
            temp = temp->next;
        }

        cout << "Book not found.\n";
    }

    // Display All Books
    void displayBooks() {
        if (head == nullptr) {
            cout << "Library is empty.\n";
            return;
        }

        Book* temp = head;

        cout << "\n===== Library Books =====\n";
        while (temp != nullptr) {
            cout << "ID: " << temp->id
                 << " | Title: " << temp->title
                 << " | Author: " << temp->author
                 << " | Status: " << (temp->isBorrowed ? "Borrowed" : "Available")
                 << endl;

            temp = temp->next;
        }
    }

    // Destructor (Memory Cleanup)
    ~Library() {
        Book* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    Library library;
    int choice;

    do {
        cout << "\n==== Library Menu ====\n";
        cout << "1. Add Book\n";
        cout << "2. Remove Book\n";
        cout << "3. Search Book\n";
        cout << "4. Borrow Book\n";
        cout << "5. Return Book\n";
        cout << "6. Display All Books\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice) {
            case 1:
                library.addBook();
                break;
            case 2:
                library.removeBook();
                break;
            case 3:
                library.searchBook();
                break;
            case 4:
                library.borrowBook();
                break;
            case 5:
                library.returnBook();
                break;
            case 6:
                library.displayBooks();
                break;
            case 7:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 7);

    return 0;
}
