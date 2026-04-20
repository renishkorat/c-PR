#include <iostream>
using namespace std;

class P
{
public:
    float temperature;
};

class Q : public P
{
public:
    float fahrenheit;

    void Fahrenheit()
    {
        cout << "Enter temperature in Celsius: ";
        cin >> temperature;
        fahrenheit = (temperature * 9 / 5) + 32;
        cout << "Fahrenheit = " << fahrenheit << endl;
    }
};

class R : public Q
{
public:
    float kelvin;
    void Kelvin()
    {
        kelvin = fahrenheit + 273.15;
        cout << "Kelvin = " << kelvin << endl;
    }
};

int main()
{
    R obj;
    obj.Fahrenheit();
    obj.Kelvin();
    return 0;
}