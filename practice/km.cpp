#include <iostream>
using namespace std;
int main()
{
    float cm, m, km;
    cout << "Enter the cm :";
    cin >> cm;

    m = cm / 100.0;
    km = cm / 100000.0;

    cout << "cm to meter =" << m << "\n";
    cout << "cm to kilo meter =" << km << "\n";

    return 0;
}