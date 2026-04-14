#include <iostream>
using namespace std;
int main()
{
    float celsius, fahrenheit;
    cout << "Enter the celsius :";
    cin >> celsius;

    fahrenheit = (celsius * 9 / 5) + 32;

    cout << "celsius to fahrenheit =" << fahrenheit;

    return 0;
}