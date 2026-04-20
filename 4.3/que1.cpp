#include <iostream>
#include <cstring>
using namespace std;

// Base Class
class Employee
{
protected:
    int employee_id;
    char name[50];
    int age;
    float salary;

public:
    // Setter
    void setDetails(int id, char n[], int a, float s)
    {
        employee_id = id;
        strcpy(name, n);
        age = a;
        salary = s;
    }

    // Getter (IMPORTANT FIX)
    int getID()
    {
        return employee_id;
    }

    // Virtual Display
     void display()
    {
        cout << "ID: " << employee_id << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Salary: " << salary << endl;
    }

     ~Employee() {}
};

// Full Time Employee
class FullTimeEmployee : public Employee
{
    float bonus;

public:
    void setFullTime(int id, char n[], int a, float s, float b)
    {
        setDetails(id, n, a, s);
        bonus = b;
    }

    void display()
    {
        cout << "\n[Full Time Employee]"<<endl;
        Employee::display();
        cout << "Bonus: " << bonus << endl;
    }
};

// Part Time Employee
class PartTimeEmployee : public Employee
{
    int hours_worked;

public:
    void setPartTime(int id, char n[], int a, float s, int h)
    {
        setDetails(id, n, a, s);
        hours_worked = h;
    }

    void display()
    {
        cout << "\n[Part Time Employee]"<<endl;
        Employee::display();
        cout << "Hours Worked: " << hours_worked << endl;
    }
};

int main()
{
    Employee* emp[100]; // array of pointers
    int count = 0;
    int choice;

    while (true)
    {
        cout << "\n---- Employee Management System ----"<<endl;
        cout << "1. Add Employee"<<endl;
        cout << "2. Display All Employees"<<endl;
        cout << "3. Delete Employee"<<endl;
        cout << "4. Exit"<<endl;
        cout << "Enter choice: ";
        cin >> choice;
        cout << endl;

        if (choice == 1)
        {
            int type;
            cout << "1. Full Time\n2. Part Time\nChoose type: ";
            cin >> type;

            int id, age;
            float salary;
            char name[50];

            cout << "Enter ID: ";
            cin >> id;

            cout << "Enter Name: ";
            cin >> name;

            cout << "Enter Age: ";
            cin >> age;

            cout << "Enter Salary: ";
            cin >> salary;

            if (type == 1)
            {
                float bonus;
                cout << "Enter Bonus: ";
                cin >> bonus;

                emp[count] = new FullTimeEmployee();
                ((FullTimeEmployee*)emp[count])->setFullTime(id, name, age, salary, bonus);
            }
            else
            {
                int hours;
                cout << "Enter Hours Worked: ";
                cin >> hours;

                emp[count] = new PartTimeEmployee();
                ((PartTimeEmployee*)emp[count])->setPartTime(id, name, age, salary, hours);
            }

            count++;
        }

        else if (choice == 2)
        {
            if (count == 0)
            {
                cout << "No employees available."<<endl;
            }
            else
            {
                for (int i = 0; i < count; i++)
                {
                    emp[i]->display();
                }
            }
        }

        else if (choice == 3)
        {
            int id;
            cout << "Enter Employee ID to delete: ";
            cin >> id;

            bool found = false;

            for (int i = 0; i < count; i++)
            {
                if (emp[i] != NULL && emp[i]->getID() == id)
                {
                    delete emp[i];
                    emp[i] = emp[count - 1]; // replace with last
                    count--;
                    found = true;
                    cout << "Employee deleted successfully."<<endl;
                    break;
                }
            }

            if (!found)
            {
                cout << "Employee not found."<<endl;
            }
        }

        else if (choice == 4)
        {
            // Free all memory
            for (int i = 0; i < count; i++)
            {
                delete emp[i];
            }
            cout << "Exiting..."<<endl;
            return 0;
        }

        else
        {
            cout << "Invalid choice!"<<endl;
        }
    }
}