#include <iostream>
using namespace std;

class Customer {
private:
    int cust_id,cust_age,cust_simcard_validity;
    string cust_name,cust_city,cust_telecom_brand_name;

public:
    void setData(int id, string name, int age, string city, int validity, string brand) {
        cust_id = id;
        cust_name = name;
        cust_age = age;
        cust_city = city;
        cust_simcard_validity = validity;
        cust_telecom_brand_name = brand;
    }

    void displayData() {
        cout << "Customer ID       : " << cust_id << endl;
        cout << "Customer Name     : " << cust_name << endl;
        cout << "Customer Age      : " << cust_age << endl;
        cout << "Customer City     : " << cust_city << endl;
        cout << "SIM Card Validity : " << cust_simcard_validity << endl;
        cout << "Telecom Brand Name: " << cust_telecom_brand_name << endl;
    }
};

int main() {
    Customer c1, c2, c3, c4, c5;
    c1.setData(101, "Hiral", 18, "Ahmedabad", 3, "Jio");
    c2.setData(102, "Riya", 19, "Surat", 2, "Airtel");
    c3.setData(103, "Nandu", 20, "Puna", 4, "Vi");
    c4.setData(104, "Shruti", 21, "Jaipur", 1, "BSNL");
    c5.setData(105, "Priya", 22, "Rajkot", 5, "Jio");

    cout << "===== Customer 1 =====" << endl;
    c1.displayData();

    cout << "\n===== Customer 2=====" << endl;
    c2.displayData();

    cout << "\n===== Customer 3=====" << endl;
    c3.displayData();

    cout << "\n===== Customer 4=====" << endl;
    c4.displayData();

    cout << "\n===== Customer 5=====" << endl;
    c5.displayData();

    return 0;
}