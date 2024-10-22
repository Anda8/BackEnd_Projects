#include <iostream>
#include <string>
using namespace std;

class Publication {
public:
    string title;
    float price;

    void getdata() {
        cout << "Enter title: ";
        getline(cin, title);
        cout << "Enter price: $";
        cin >> price;
        cin.ignore(); // Consume the newline
    }

    void putdata() const {
        cout << "Title: " << title << endl;
        cout << "Price: $" << price << endl;
    }
};

class Sales {
public:
    float sales[3];

    void getdata() {
        for (int i = 0; i < 3; ++i) {
            cout << "Enter sales for month " << i + 1 << ": $";
            cin >> sales[i];
        }
    }

    void putdata() const {
        for (int i = 0; i < 3; ++i) {
            cout << "Sales for month " << i + 1 << ": $" << sales[i] << endl;
        }
    }
};

class Book : public Publication, public Sales {
public:
    int pageCount;

    void getdata() {
        Publication::getdata();
        cout << "Enter page count: ";
        cin >> pageCount;
        Sales::getdata();
    }

    void putdata() const {
        Publication::putdata();
        cout << "Page count: " << pageCount <<endl;
        Sales::putdata();
    }
};

class Tape : public Publication, public Sales {
public:
    float playingTime;

    void getdata() {
        Publication::getdata();
        cout << "Enter playing time in minutes: ";
        cin >> playingTime;
        Sales::getdata();
    }

    void putdata() const {
        Publication::putdata();
        cout << "Playing time: " << playingTime << " minutes" << endl;
        Sales::putdata();
    }
};

enum DiskType { CD, DVD };

class Disk : public Publication, public Sales {
public:
    DiskType diskType;

    void getdata() {
        Publication::getdata();
        char choice;
        cout << "Enter disk type (c for CD, d for DVD): ";
        cin >> choice;

        if (choice == 'c') {
            diskType = CD;
        } else if (choice == 'd') {
            diskType = DVD;
        } else {
            cerr << "Invalid choice. Defaulting to CD." << endl;
            diskType = CD;
        }

        Sales::getdata();
    }

    void putdata() const {
        Publication::putdata();
        cout << "Disk type: " << (diskType == CD ? "CD" : "DVD") << endl;
        Sales::putdata();
    }
};

class Employee {
public:
    double compensation;
    float period;
    string department;
    string firstName;
    string lastName;

    void getdata() {
        cout << "Enter compensation: $";
        cin >> compensation;
        cout << "Enter pay period (hourly, weekly, monthly): ";
        cin >> period;
        cin.ignore(); // Consume the newline character
        cout << "Enter department: ";
        getline(cin, department);
        cout << "Enter first name: ";
        getline(cin, firstName);
        cout << "Enter last name: ";
        getline(cin, lastName);
    }

    void putdata() const {
        cout << "Compensation: $" << compensation << endl;
        cout << "Pay period: " << period << endl;
        cout << "Department: " << department << endl;
        cout << "Name: " << firstName << " " << lastName << endl;
    }
};

class Manager : public Employee {};
class Scientist : public Employee {};
class Laborer : public Employee {};

int main() {
    Book book;
    Tape tape;
    Disk disk;

    cout << "Enter book details:\n";
    book.getdata();

    cout << "\nEnter tape details:\n";
    tape.getdata();

    cout << "\nEnter disk details:\n";
    disk.getdata();

    cout << "\nBook details:\n";
    book.putdata();

    cout << "\nTape details:\n";
    tape.putdata();

    cout << "\nDisk details:\n";
    disk.putdata();

    Manager manager;
    Scientist scientist;
    Laborer laborer;

    cout << "\nEnter manager details:\n";
    manager.getdata();

    cout << "\nEnter scientist details:\n";
    scientist.getdata();

    cout << "\nEnter laborer details:\n";
    laborer.getdata();

    cout << "\nManager details:\n";
    manager.putdata();

    cout << "\nScientist details:\n";
    scientist.putdata();

    cout << "\nLaborer details:\n";
    laborer.putdata();

    return 0;
}
