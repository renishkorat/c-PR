#include <iostream>
using namespace std;

class Cricket
{
public:
    virtual void getTotalOvers()
    {
        cout << "cricket match has variable over" << endl;
    }
};

class T20match : public Cricket
{
    void getTotalOvers()
    {
        cout << "T20 match: Total over =20" << endl;
    }
};

class Testmatch : public Cricket
{
    void getTotalOvers()
    {
        cout << "No fix over" << endl;
    }
};

int main()
{
    Cricket *cricketptr;

    T20match t20matchobj;
    Testmatch testobj;

    // Call T20 Match
    cricketptr = &t20matchobj;
    cricketptr->getTotalOvers();

    // Call Test Match
    cricketptr = &testobj;
    cricketptr->getTotalOvers();

    return 0;
}