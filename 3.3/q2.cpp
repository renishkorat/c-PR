#include <iostream>
using namespace std;

class FastFoodCafe {
    int cafe_id, cafe_establish_year, cafe_staff_quantity;
    string cafe_name, cafe_type, cafe_rating, cafe_location;

public:
    FastFoodCafe() {}

    FastFoodCafe(int id, string name, string type, string rating,
                 string location, int establish_year, int staff_quantity) {
        cafe_id = id;
        cafe_name = name;
        cafe_type = type;
        cafe_rating = rating;
        cafe_location = location;
        cafe_establish_year = establish_year;
        cafe_staff_quantity = staff_quantity;
    }

    void display() {
        cout << "Cafe ID: " << cafe_id << endl;
        cout << "Cafe Name: " << cafe_name << endl;
        cout << "Cafe Type: " << cafe_type << endl;
        cout << "Cafe Rating: " << cafe_rating << endl;
        cout << "Cafe Location: " << cafe_location << endl;
        cout << "Cafe Establish Year: " << cafe_establish_year << endl;
        cout << "Cafe Staff Quantity: " << cafe_staff_quantity << endl;
        cout << "\n";
    }
};

int main() {
    int n;
    cout << "Enter number of Fast Food Cafe: ";
    cin >> n;

    FastFoodCafe cafe[n];

    for (int i = 0; i < n; i++) {
        int id, establish_year, staff_quantity;
        string name, type, rating, location;

        cout << "\nEnter details for Cafe " << i + 1 << endl;

        cout << "Enter Cafe ID: ";
        cin >> id;

        cout << "Enter Cafe Name: ";
        cin >> name;

        cout << "Enter Cafe Type: ";
        cin >> type;

        cout << "Enter Cafe Rating: ";
        cin >> rating;

        cout << "Enter Cafe Location: ";
        cin >> location;

        cout << "Enter Establish Year: ";
        cin >> establish_year;

        cout << "Enter Staff Quantity: ";
        cin >> staff_quantity;

        cafe[i] = FastFoodCafe(id, name, type, rating, location, establish_year, staff_quantity);
    }

    cout << "\n--- Fast Food Cafe ---\n";

    for (int i = 0; i < n; i++) {
        cafe[i].display();
    }

    return 0;
}