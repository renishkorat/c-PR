#include <iostream>
using namespace std;

// Base Class
class A
{
protected:
    int a;

public:
    A(int x)
    {
        a = x;
    }
};

// Derived Class B from A
class B : public A
{
protected:
    int b;

public:
    B(int x, int y) : A(x)
    {
        b = y;
    }
};

// Derived Class C from A
class C : public A
{
protected:
    int c;

public:
    C(int x, int z) : A(x)
    {
        c = z;
    }
};

// Hybrid Class D (inherits from B and C)
class D : public B, public C
{
    int d;

public:
    D(int w, int x, int y, int z) 
        : B(w, x), C(w, y)
    {
        d = z;
    }

    void displaySum()
    {
        int sum = B::a + b + c + d; // access a from B side
        cout << "Sum of four numbers = " << sum << endl;
    }
};

int main()
{
    D obj(10, 20, 30, 40);
    obj.displaySum();

    return 0;
}