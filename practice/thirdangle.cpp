#include <iostream>
using namespace std;
int main()
{
    int first_angle, second_angle, third_angle;
    cout << "Enter thr first angle :";
    cin >> first_angle;
    cout << "Enter the second angle :";
    cin >> second_angle;

    third_angle = 180 - (first_angle + second_angle);

    cout << "third angle =" << third_angle;

    return 0;
}