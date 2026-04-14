#include <iostream>
using namespace std;

class Employee {
public:
    int emp_id, emp_age, emp_salary, emp_experience;
    string emp_name, emp_role, emp_city, emp_company_name;

    void display() {
        cout << "\nID: " << emp_id;
        cout << "\nName: " << emp_name;
        cout << "\nAge: " << emp_age;
        cout << "\nRole: " << emp_role;
        cout << "\nSalary: " << emp_salary;
        cout << "\nCity: " << emp_city;
        cout << "\nExperience: " << emp_experience;
        cout << "\nCompany: " << emp_company_name << endl;
    }
};

int main() {

    Employee e1 = {1, 20, 50000, 2, "Renish", "Developer", "Ahmedabad", "TCS"};
    Employee e2 = {2, 23, 45000, 3, "Aryan", "Designer", "Surat", "Infosys"};
    Employee e3 = {3, 19, 70000, 5, "Amit", "Manager", "Rajkot", "Wipro"};
    Employee e4 = {4, 21, 40000, 2, "Harshit", "Tester", "Vadodara", "HCL"};
    Employee e5 = {5, 25, 90000, 7, "Karan", "Team Lead", "Ahmedabad", "Accenture"};

    e1.display();
    e2.display();
    e3.display();
    e4.display();
    e5.display();

    return 0;
}