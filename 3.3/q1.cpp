#include <iostream>
using namespace std;

class DiamondCompany {
int comp_id, comp_export_diamonds, comp_staff_quantity, comp_import_raw_diamonds,comp_revenue;   
    string comp_name,comp_ceo;
    

public:
   DiamondCompany() {}
    DiamondCompany(int id, string name, int staff, int revenue,
                   int import_raw, int export_dia, string ceo) {
        comp_id = id;
        comp_name = name;
        comp_staff_quantity = staff;
        comp_revenue = revenue;
        comp_import_raw_diamonds = import_raw;
        comp_export_diamonds = export_dia;
        comp_ceo = ceo;
    }

    void display() {
        cout << "Company ID: " << comp_id<<endl;
        cout << "Company Name: " << comp_name<<endl;
        cout << "Staff Quantity: " << comp_staff_quantity<<endl;
        cout << "Annual Revenue: " << comp_revenue<<endl;
        cout << "Imported Raw Diamonds: " << comp_import_raw_diamonds<<endl;
        cout << "Exported Diamonds: " << comp_export_diamonds<<endl;
        cout << "CEO: " << comp_ceo << endl;
        cout<<"\n";
    }
};

int main() {
    int n;

    cout << "Enter number of Diamond Companies: ";
    cin >> n;

    DiamondCompany comp[n];

    for (int i = 0; i < n; i++) {
        int id, staff, import_raw, export_dia,revenue;
        string name, ceo;

        cout << "\nEnter details for Company " << i + 1 << endl;

        cout << "Enter Company ID: ";
        cin >> id;

        cout << "Enter Company Name: ";
        cin >> name;

        cout << "Enter Staff Quantity: ";
        cin >> staff;

        cout << "Enter Annual Revenue: ";
        cin >> revenue;

        cout << "Enter Imported Raw Diamonds: ";
        cin >> import_raw;

        cout << "Enter Exported Diamonds: ";
        cin >> export_dia;

        cout << "Enter CEO Name: ";
        cin >> ceo;

        comp[i] = DiamondCompany(id, name, staff, revenue, import_raw, export_dia, ceo);
    }

    cout << "\n\n--- Diamond Companies Information ---\n";

    for (int i = 0; i < n; i++) {
        comp[i].display();
    }

    return 0;
}