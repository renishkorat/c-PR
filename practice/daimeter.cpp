#include <iostream>
using namespace std;
int main()
{
    float radius, diameter, circumference, area;
    cout << "Enter the radius :";
    cin >> radius;

    diameter = 2 * radius;
    circumference = 2 * 3.14 * radius;
    area = 3.14 * (radius * radius);

    cout << "Diameter of circle =" << diameter << "\n";
    cout << "Circumference of circle =" << circumference << "\n";
    cout << "area of circle =" << area << "\n";

    return 0;
}