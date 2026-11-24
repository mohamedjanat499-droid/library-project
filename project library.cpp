#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    int id;
    string title;
    string author;
    bool availability;

public:
    Book() {
        id = 0;
        title = "";
        author = "";
        availability = true;
    }

    Book(int id, string title, string author) {
        this->id = id;
        this->title = title;
        this->author = author;
        availability = true;
    }

    int getId() {
        return id;
    }

    bool getAvailability() {
        return availability;
    }

    void setTitle(string title) {
        this->title = title;
    }

    void setAuthor(string author) {
        this->author = author;
    }

    void setAvailability(bool availability) {
        this->availability = availability;
    }

    void display() {
        cout << "ID: " << id << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Availability: "
            << (availability ? "Available" : "Borrowed") << endl;
    }
};

class Library {
protected:
    int count = 0;
    Book books[400];

public:
    virtual void addBook() = 0;
    virtual void searchBook() = 0;
    virtual void updateBook() = 0;
    virtual void removeBook() = 0;
    virtual void borrowBook() = 0;
    virtual void returnBook() = 0;
    virtual void displayBooks() = 0;

    virtual ~Library() {}
};

class LibrarySystem : public Library {
public:

    LibrarySystem() : Library() {}

    void addBook() override {
        int id;
        string title, author;

        if (count >= 400) {
            cout << "Library Is Full\n";
            return;
        }

        cout << "Enter Book ID: ";
        cin >> id;

        cout << "Enter Book Title: ";
        cin >> title;

        cout << "Enter Book Author: ";
        cin >> author;

        books[count] = Book(id, title, author);
        count++;

        cout << "Book Added Successfully\n";
    }

    void searchBook() override {
        int id;

        cout << "Enter Book ID: ";
        cin >> id;

        for (int i = 0; i < count; i++) {
            if (books[i].getId() == id) {
                cout << "Book Found\n";
                books[i].display();
                return;
            }
        }

        cout << "Book Not Found\n";
    }

    void updateBook() override {
        int id;
        string title, author;

        cout << "Enter Book ID: ";
        cin >> id;

        for (int i = 0; i < count; i++) {
            if (books[i].getId() == id) {

                cout << "Enter New Title: ";
                cin >> title;

                cout << "Enter New Author: ";
                cin >> author;

                books[i].setTitle(title);
                books[i].setAuthor(author);

                cout << "Book Updated Successfully\n";
                return;
            }
        }

        cout << "Book Not Found\n";
    }

    void removeBook() override {
        int id;

        cout << "Enter Book ID: ";
        cin >> id;

        for (int i = 0; i < count; i++) {
            if (books[i].getId() == id) {

                for (int j = i; j < count - 1; j++) {
                    books[j] = books[j + 1];
                }

                count--;

                cout << "Book Removed Successfully\n";
                return;
            }
        }

        cout << "Book Not Found\n";
    }

    void borrowBook() override {
        int id;

        cout << "Enter Book ID: ";
        cin >> id;

        for (int i = 0; i < count; i++) {
            if (books[i].getId() == id) {

                if (books[i].getAvailability()) {
                    books[i].setAvailability(false);
                    cout << "Book Borrowed Successfully\n";
                }
                else {
                    cout << "Book Is Already Borrowed\n";
                }

                return;
            }
        }

        cout << "Book Not Found\n";
    }

    void returnBook() override {
        int id;

        cout << "Enter Book ID: ";
        cin >> id;

        for (int i = 0; i < count; i++) {
            if (books[i].getId() == id) {

                if (!books[i].getAvailability()) {
                    books[i].setAvailability(true);
                    cout << "Book Returned Successfully\n";
                }
                else {
                    cout << "Book Is Already Available\n";
                }

                return;
            }
        }

        cout << "Book Not Found\n";
    }

    void displayBooks() override {
        if (count == 0) {
            cout << "Library Is Empty\n";
            return;
        }

        for (int i = 0; i < count; i++) {
            books[i].display();
            cout << "------------------\n";
        }
    }
};

int main() {
    LibrarySystem lib;

    lib.addBook();
    lib.displayBooks();

    return 0;
}
\*name: eng janat mohamed*\
