#include <iostream>
using namespace std;


class LibraryItem
{
protected:
    string title;
    string author;
    string dueDate;

public:
    LibraryItem(string t, string a, string d)
    {
        title = t;
        author = a;
        dueDate = d;
    }

    string getTitle() { return title; }
    string getAuthor() { return author; }
    string getDueDate() { return dueDate; }

    void setTitle(string t) { title = t; }
    void setAuthor(string a) { author = a; }
    void setDueDate(string d) { dueDate = d; }

    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() = 0;

    virtual ~LibraryItem() {}
};

class Book : public LibraryItem
{
public:
    Book(string t, string a, string d) : LibraryItem(t, a, d) {}

    void checkOut() override
    {
        cout << "Book Checked Out: " << title << endl;
    }

    void returnItem() override
    {
        cout << "Book Returned: " << title << endl;
    }

    void displayDetails() override
    {
        cout << "\n[Book]"
             << "\nTitle: " << title
             << "\nAuthor: " << author
             << "\nDue Date: " << dueDate << endl;
    }
};

class DVD : public LibraryItem
{
    int duration;

public:
    DVD(string t, string a, string d, int dur)
        : LibraryItem(t, a, d)
    {
        duration = dur;
    }

    void checkOut() override
    {
        cout << "DVD Checked Out: " << title << endl;
    }

    void returnItem() override
    {
        cout << "DVD Returned: " << title << endl;
    }

    void displayDetails() override
    {
        cout << "\n[DVD]"
             << "\nTitle: " << title
             << "\nAuthor: " << author
             << "\nDue Date: " << dueDate
             << "\nDuration: " << duration << " mins" << endl;
    }
};

class Magazine : public LibraryItem
{
    int issueNumber;

public:
    Magazine(string t, string a, string d, int issue)
        : LibraryItem(t, a, d)
    {
        issueNumber = issue;
    }

    void checkOut() override
    {
        cout << "Magazine Checked Out: " << title << endl;
    }

    void returnItem() override
    {
        cout << "Magazine Returned: " << title << endl;
    }

    void displayDetails() override
    {
        cout << "\n[Magazine]"
             << "\nTitle: " << title
             << "\nAuthor: " << author
             << "\nDue Date: " << dueDate
             << "\nIssue No: " << issueNumber << endl;
    }
};

int main()
{
    const int MAX=10;
LibraryItem* items[MAX];
int count = 0;

    int choice;

    do
    {
        cout << "\n===== Library Menu =====";
        cout << "\n1. Add Book";
        cout << "\n2. Add DVD";
        cout << "\n3. Add Magazine";
        cout << "\n4. Display All";
        cout << "\n5. Checkout Item";
        cout << "\n6. Return Item";
        cout << "\n0. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        try
        {
            if (choice == 1)
            {
                string t, a, d;
                cout << "Enter title: ";
                cin >> t;
                cout << "Enter author: ";
                cin >> a;
                cout << "Enter due date: ";
                cin >> d;

                items[count++] = new Book(t, a, d);
            }
            else if (choice == 2)
            {
                string t, a, d;
                int dur;

                cout << "Enter title: ";
                cin >> t;
                cout << "Enter author: ";
                cin >> a;
                cout << "Enter due date: ";
                cin >> d;
                cout << "Enter duration: ";
                cin >> dur;

                if (dur < 0)
                    throw "Invalid duration!";

                items[count++] = new DVD(t, a, d, dur);
            }
            else if (choice == 3)
            {
                string t, a, d;
                int issue;

                cout << "Enter title: ";
                cin >> t;
                cout << "Enter author: ";
                cin >> a;
                cout << "Enter due date: ";
                cin >> d;
                cout << "Enter issue number: ";
                cin >> issue;

                if (issue < 0)
                    throw "Invalid issue number!";

                items[count++] = new Magazine(t, a, d, issue);
            }
            else if (choice == 4)
            {
                for (int i = 0; i < count; i++)
                    items[i]->displayDetails();
            }
            else if (choice == 5)
            {
                int i;
                cout << "Enter index: ";
                cin >> i;
                items[i]->checkOut();
            }
            else if (choice == 6)
            {
                int i;
                cout << "Enter index: ";
                cin >> i;
                items[i]->returnItem();
            }

        }
        catch (const char* msg)
        {
            cout << "Error: " << msg << endl;
        }

    } while (choice != 0);

    return 0;
}
