#include <iostream>
using namespace std;
int main()
{
    float celsius, fahrenheit;
    cout << "Enter the fahrenheit :";
    cin >> fahrenheit;

    celsius = (fahrenheit - 32) * 9 / 5;

    cout << "fahrenheit to celsius =" << celsius;

    return 0;
}