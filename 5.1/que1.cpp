#include <iostream>
using namespace std;

class base
{
};

class Calculate : public base
{
public:
    void calculate(int a, int b)
    {
        cout << "division = " << a / b << endl;
    }

    void calculate(int a, int b, int c)
    {
        cout << "subtraction = " << a - b - c << endl;
    }

    void calculate(int a, int b, int c, int d)
    {
        cout << "multiplication = " << a * b * c * d << endl;
    }

    void calculate(int a, int b, int c, int d, int e)
    {
        cout << "addition = " << a + b + c + d + e << endl;
    }
};

int main()
{
    Calculate obj;

    obj.calculate(10, 5);
    obj.calculate(30, 10, 5);
    obj.calculate(1, 2, 3, 4);
    obj.calculate(1, 2, 3, 4,5);

    return 0;
}