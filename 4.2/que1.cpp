#include <iostream>
using namespace std;

// Base Class
class RBI
{
protected:
    float rate;

public:
    void getROI()
    {
        cout << "Rate of Interest: " << rate << "%" << endl;
    }
};

class SBI : public RBI
{
public:
    SBI()
    {
        rate = 6.5;
    }
};

class BOB : public RBI
{
public:
    BOB()
    {
        rate = 7.0;
    }
};

class ICICI : public RBI
{
public:
    ICICI()
    {
        rate = 7.5;
    }
};

int main()
{
    SBI s;
    BOB b;
    ICICI i;

    cout << "SBI Bank -> ";
    s.getROI();

    cout << "BOB Bank -> ";
    b.getROI();

    cout << "ICICI Bank -> ";
    i.getROI();

    return 0;
}