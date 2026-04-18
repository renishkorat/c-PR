#include <iostream>
using namespace std;

class Admin
{
public:
    string company_name;

protected:
    int manager_salary;
    int employee_salary;

private:
    int total_staff;
    float total_annual_revenue;
    string can_terminate;

public:
    void setData()
    {
        cout << "Enter Company Name: ";
        cin >> company_name;

        cout << "Enter Manager Salary: ";
        cin >> manager_salary;

        cout << "Enter Employee Salary: ";
        cin >> employee_salary;

        cout << "Enter Total Staff: ";
        cin >> total_staff;

        cout << "Enter Total Annual Revenue: ";
        cin >> total_annual_revenue;

        cout << "Can Terminate (Yes/No): ";
        cin >> can_terminate;
    }

    int getManagerSalary()
    {
        return manager_salary;
    }

    int getEmployeeSalary()
    {
        return employee_salary;
    }
};

class Manager : public Admin
{
public:
    void myAccess()
    {
        cout << "\n--- Manager Access ---";
        cout << "\nCompany Name: " << company_name;
        cout << "\nManager Salary: " << manager_salary;
        cout << "\nEmployee Salary: " << employee_salary;
    }
};

class Employee : public Manager
{
public:
    void setSalary(int m, int e)
    {
        manager_salary = m;
        employee_salary = e;
    }

    void myAccess()
    {
        cout << "\n--- Employee Access ---";
        cout << "\nCompany Name: " << company_name;
        cout << "\nManager Salary: " << manager_salary;
        cout << "\nEmployee Salary: " << employee_salary;
    }
};

int main()
{
    Manager m;
    Employee e;

    m.setData();

    e.company_name = m.company_name;
    e.setSalary(m.getManagerSalary(), m.getEmployeeSalary());

    m.myAccess();
    e.myAccess();

    return 0;
}