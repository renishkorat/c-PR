#include <iostream>
using namespace std;

const int MAX_ITEMS = 100;

// ================= ABSTRACT BASE CLASS =================
class LibraryItem
{
private:
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

    // Getters
    string getTitle()
    {
        return title;
    }

    string getAuthor()
    {
        return author;
    }

    string getDueDate()
    {
        return dueDate;
    }

    // Setters
    void setTitle(string t)
    {
        title = t;
    }

    void setAuthor(string a)
    {
        author = a;
    }

    void setDueDate(string d)
    {
        dueDate = d;
    }

    // Pure Virtual Functions
    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() = 0;

    virtual ~LibraryItem() {}
};

// ================= BOOK CLASS =================
class Book : public LibraryItem
{
private:
    string isbn;

public:
    Book(string t, string a, string d, string i)
        : LibraryItem(t, a, d)
    {
        if (i.length() != 13)
            throw i;

        isbn = i;
    }

    void checkOut() override
    {
        cout << "Book Checked Out Successfully\n";
    }

    void returnItem() override
    {
        cout << "Book Returned Successfully\n";
    }

    void displayDetails() override
    {
        cout << "\n----- Book -----\n";
        cout << "Title    : " << getTitle() << endl;
        cout << "Author   : " << getAuthor() << endl;
        cout << "Due Date : " << getDueDate() << endl;
        cout << "ISBN     : " << isbn << endl;
    }
};

// ================= DVD CLASS =================
class DVD : public LibraryItem
{
private:
    int duration;

public:
    DVD(string t, string a, string d, int dur)
        : LibraryItem(t, a, d)
    {
        if (dur < 0)
            throw dur;

        duration = dur;
    }

    void checkOut() override
    {
        cout << "DVD Checked Out Successfully\n";
    }

    void returnItem() override
    {
        cout << "DVD Returned Successfully\n";
    }

    void displayDetails() override
    {
        cout << "\n----- DVD -----\n";
        cout << "Title    : " << getTitle() << endl;
        cout << "Author   : " << getAuthor() << endl;
        cout << "Due Date : " << getDueDate() << endl;
        cout << "Duration : " << duration << " min\n";
    }
};

// ================= MAGAZINE CLASS =================
class Magazine : public LibraryItem
{
private:
    int issueNumber;

public:
    Magazine(string t, string a, string d, int issue)
        : LibraryItem(t, a, d)
    {
        if (issue < 0)
            throw issue;

        issueNumber = issue;
    }

    void checkOut() override
    {
        cout << "Magazine Checked Out Successfully\n";
    }

    void returnItem() override
    {
        cout << "Magazine Returned Successfully\n";
    }

    void displayDetails() override
    {
        cout << "\n----- Magazine -----\n";
        cout << "Title        : " << getTitle() << endl;
        cout << "Author       : " << getAuthor() << endl;
        cout << "Due Date     : " << getDueDate() << endl;
        cout << "Issue Number : " << issueNumber << endl;
    }
};

// ================= MAIN FUNCTION =================
int main()
{
    LibraryItem* libraryItems[MAX_ITEMS];
    int count = 0;
    int choice;

    do
    {
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Book\n";
        cout << "2. Add DVD\n";
        cout << "3. Add Magazine\n";
        cout << "4. Display All Items\n";
        cout << "5. Check Out Item\n";
        cout << "6. Return Item\n";
        cout << "7. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        try
        {
            if (choice == 1)
            {
                string title, author, dueDate, isbn;

                cin.ignore();
                cout << "Enter Title: ";
                getline(cin, title);

                cout << "Enter Author: ";
                getline(cin, author);

                cout << "Enter Due Date: ";
                getline(cin, dueDate);

                cout << "Enter ISBN (13 digits): ";
                getline(cin, isbn);

                libraryItems[count++] = new Book(title, author, dueDate, isbn);
            }

            else if (choice == 2)
            {
                string title, author, dueDate;
                int duration;

                cin.ignore();
                cout << "Enter Title: ";
                getline(cin, title);

                cout << "Enter Author: ";
                getline(cin, author);

                cout << "Enter Due Date: ";
                getline(cin, dueDate);

                cout << "Enter Duration: ";
                cin >> duration;

                libraryItems[count++] = new DVD(title, author, dueDate, duration);
            }

            else if (choice == 3)
            {
                string title, author, dueDate;
                int issue;

                cin.ignore();
                cout << "Enter Title: ";
                getline(cin, title);

                cout << "Enter Author: ";
                getline(cin, author);

                cout << "Enter Due Date: ";
                getline(cin, dueDate);

                cout << "Enter Issue Number: ";
                cin >> issue;

                libraryItems[count++] = new Magazine(title, author, dueDate, issue);
            }

            else if (choice == 4)
            {
                for (int i = 0; i < count; i++)
                {
                    libraryItems[i]->displayDetails();
                }
            }

            else if (choice == 5)
            {
                int index;
                cout << "Enter Item Number: ";
                cin >> index;

                if (index >= 1 && index <= count)
                    libraryItems[index - 1]->checkOut();
                else
                    cout << "Invalid Item Number\n";
            }

            else if (choice == 6)
            {
                int index;
                cout << "Enter Item Number: ";
                cin >> index;

                if (index >= 1 && index <= count)
                    libraryItems[index - 1]->returnItem();
                else
                    cout << "Invalid Item Number\n";
            }
        }

        catch (string s)
        {
            cout << "Invalid ISBN! Must be 13 digits.\n";
        }

        catch (int n)
        {
            cout << "Negative value not allowed.\n";
        }

        catch (...)
        {
            cout << "Something went wrong!\n";
        }

    } while (choice != 7);

    // Memory Release
    for (int i = 0; i < count; i++)
    {
        delete libraryItems[i];
    }

    cout << "Program Ended.\n";

    return 0;
}