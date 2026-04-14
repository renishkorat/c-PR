#include <iostream>
using namespace std;

class Car {
public:
  int car_id, car_release_year;
  string car_model, car_color, car_company_name;

    void display() {
        cout << "\nID: " << car_id;
        cout << "\nCompany Name: " << car_company_name;
        cout << "\nCar color: " << car_color;
        cout << "\nModel: " << car_model;
        cout << "\nRelease year: " << car_release_year<<endl;
    }
};

int main() {

    Car c1 = {1, 2020, "Creta", "White", "Hyundai"};
    Car c2 = {2, 2019, "Swift", "Red", "Maruti"};
    Car c3 = {3, 2022, "XUV700", "Black", "Mahindra"};
    Car c4 = {4, 2021, "City", "Silver", "Honda"};
    Car c5 = {5, 2023, "Fortuner", "White", "Toyota"};


    c1.display();
    c2.display();
    c3.display();
    c4.display();
    c5.display();

    return 0;
}