#include <iostream>
using namespace std;

class Shape
{
public:
    virtual void calculate() = 0;
};

class Circle : public Shape
{
    float r, area;

public:
    void getData()
    {
        cout << "Enter radius of circle :" << endl;
        cin >> r;
    }

    void calculate()
    {
        area = 3.14 * r * r;
        cout << "Area of circle :" << area << endl;
    }
};

class Triangle : public Shape
{
    float b, h, area;

public:
    void getData()
    {
        cout << "Enter base of triangle :" << endl;
        cin >> b;
        cout << "Enter height of triangle :" << endl;
        cin >> h;
    }

    void calculate()
    {
        area = 0.5 * b * h;
        cout << "area of triangle =" << area << endl;
    }
};

class Rectangle : public Shape
{
    float l, w, area;

public:
    void getData()
    {
        cout << "Enter length of rectangle :" << endl;
        cin >> l;
        cout << "Enter width of rectangle :" << endl;
        cin >> w;
    }

    void calculate()
    {

        area = l * w;
        cout << "area of rectangle =" << area << endl;
    }
};

int main()
{
    Circle c;
    Triangle t;
    Rectangle r;

    c.getData();
    c.calculate();

    t.getData();
    t.calculate();

    r.getData();
    r.calculate();

    return 0;
}
