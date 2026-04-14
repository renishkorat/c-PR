#include <iostream>
#include <string>
using namespace std;

class Student {
    private:
    string name;
    int rollNumber;
    float GPA;

public:
    
    Student() {    // Default Constructor
        name = "";
        rollNumber = 0;
        GPA = 0.0;
    }

   
    Student(string n, int r, float g) {   // Parameterized Constructor
        name = n;
        rollNumber = r;
        GPA = g;
    }

    // Copy Constructor
    Student( Student &s) {
        name = s.name;
        rollNumber = s.rollNumber;
        GPA = s.GPA;
    }

    // Getters
    string getName() const { return name; }
    int getRollNumber() const { return rollNumber; }
    float getGPA() const { return GPA; }

    void display() const {
        cout << "Name: " << name
             << ", Roll No: " << rollNumber
             << ", GPA: " << GPA << endl;
    }
};

class StudentRecordManager {
private:
    Student *students;
    int size;
    int capacity;

public:
    StudentRecordManager(int cap = 5) {
        capacity = cap;
        size = 0;
        students = new Student[capacity];
    }

    ~StudentRecordManager() {  //Destructor
        delete[] students;
    }

    void addStudent(const Student &s) {
        if (size == capacity) {
            capacity = capacity * 2;  //double capicity
            Student *temp = new Student[capacity];

            for (int i = 0; i < size; i++) {
                temp[i] = students[i];
            }

            delete[] students;   //Destructor
            students = temp;
        }

        students[size++] = s;  // add student
    }

    void displayAll() const {
        if (size == 0) {
            cout << "No records available!"<<endl;
            return;
        }

        cout << "\n--- Student Records ---"<<endl;
        for (int i = 0; i < size; i++) {
            students[i].display();
        }
    }

    void searchByRoll(int roll) const {
        for (int i = 0; i < size; i++) {
            if (students[i].getRollNumber() == roll) {
                cout << "\nStudent Found:"<<endl;
                students[i].display();
                return;
            }
        }
        cout << "Student not found!"<<endl;
    }
};

int main() {
    StudentRecordManager manager;
    int choice;

    do {
        cout << "\n---- Student Record System ----"<<endl;
        cout << "1. Add Student"<<endl;
        cout << "2. Display All Students"<<endl;
        cout << "3. Search Student by Roll Number"<<endl;
        cout << "4. Exit"<<endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            string name;
            int roll;
            float gpa;

            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);

            cout << "Enter Roll Number: ";
            cin >> roll;

            cout << "Enter GPA: ";
            cin >> gpa;

            Student s(name, roll, gpa);
            manager.addStudent(s);

            cout << "Student added successfully!"<<endl;
        }

        else if (choice == 2) {
            manager.displayAll();
        }

        else if (choice == 3) {
            int roll;
            cout << "Enter Roll Number to search: ";
            cin >> roll;
            manager.searchByRoll(roll);
        }

        else if (choice == 4) {
            cout << "Exiting program..."<<endl;
        }

        else {
            cout << "Invalid choice!"<<endl;
        }

    } while (choice != 4);

    return 0;
}