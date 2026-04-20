#include <iostream>
using namespace std;
int main()
{
    float base, height, area;
    cout << "Enter valus of base :";
    cin >> base;
    cout << "Enter value of height :";
    cin >> height;

    area = 2 * (base + height);
    cout << "area of triangle =" << area;

    return 0;
}