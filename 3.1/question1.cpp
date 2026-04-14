// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class Student {
private:
    int stu_id,stu_age;
    string stu_name;
    string stu_course;
    string stu_city;
    string stu_email;
    string stu_college;

public:
    
    void setData(int id, string name, int age, string course, string city, string email, string college) {
        stu_id = id;
        stu_name = name;
        stu_age = age;
        stu_course = course;
        stu_city = city;
        stu_email = email;
        stu_college = college;
    }

    void displayData() {
        cout << "Student ID      : " << stu_id << endl;
        cout << "Student Name    : " << stu_name << endl;
        cout << "Student Age     : " << stu_age << endl;
        cout << "Student Course  : " << stu_course << endl;
        cout << "Student City    : " << stu_city << endl;
        cout << "Student Email   : " << stu_email << endl;
        cout << "Student College : " << stu_college << endl;
    }
};

int main() {
    Student s1, s2, s3, s4, s5;

    s1.setData(101, "Hiral", 18, "BCA", "Ahmedabad", "hiral@gmail.com", "Silver Oak College");
    s2.setData(102, "Riya", 19, "BBA", "Surat", "riya@gmail.com", "GLS College");
    s3.setData(103, "Kavya", 18, "BCom", "Vadodara", "kavya@gmail.com", "MSU College");
    s4.setData(104, "Priya", 20, "BSc IT", "Rajkot", "priya@gmail.com", "RK University");
    s5.setData(105, "Neha", 19, "BCA", "Bhavnagar", "neha@gmail.com", "Shanti Business School");

    cout << "===== Student 1 =====" << endl;
    s1.displayData();

    cout << "\n===== Student 2 =====" << endl;
    s2.displayData();

    cout << "\n===== Student 3 =====" << endl;
    s3.displayData();

    cout << "\n===== Student 4 =====" << endl;
    s4.displayData();

    cout << "\n===== Student 5 =====" << endl;
    s5.displayData();

    return 0;
}