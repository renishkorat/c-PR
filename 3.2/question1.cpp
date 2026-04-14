#include <iostream>
using namespace std;

class Hotel {
    int hotel_id,hotel_establish_year,hotel_staff_quantity,hotel_room_quantity;

    string hotel_name,hotel_type,hotel_rating,hotel_location;

public:
    void setData() {
        cout << "\nEnter Hotel ID: ";
        cin >> hotel_id;

        cout << "Enter Hotel Name: ";
        cin >> hotel_name;

        cout << "Enter Hotel Type (luxury): ";
        cin >> hotel_type;

        cout << "Enter Hotel Rating (1 Star to 7 Star): ";
        cin >> hotel_rating;

        cout << "Enter Hotel Location (city): ";
        cin >> hotel_location;

        cout << "Enter Establish Year: ";
        cin >> hotel_establish_year;

        cout << "Enter Staff Quantity: ";
        cin >> hotel_staff_quantity;

        cout << "Enter Room Quantity: ";
        cin >> hotel_room_quantity;
    }

    void getData() {
        cout << "\n--- Hotel Details ---"<<endl;
        cout << "Hotel ID: " << hotel_id << endl;
        cout << "Hotel Name: " << hotel_name << endl;
        cout << "Hotel Type: " << hotel_type << endl;
        cout << "Hotel Rating: " << hotel_rating << endl;
        cout << "Location: " << hotel_location << endl;
        cout << "Establish Year: " << hotel_establish_year << endl;
        cout << "Staff Quantity: " << hotel_staff_quantity << endl;
        cout << "Room Quantity: " << hotel_room_quantity << endl;
        cout<<"\n";
    }
};

int main() {
    int n;

    cout << "Enter number of hotels: ";
    cin >> n;

    Hotel h[n];  

    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for Hotel " << i + 1 << endl;
        h[i].setData();
    }

    for (int i = 0; i < n; i++) {
        h[i].getData();
    }

    return 0;
}