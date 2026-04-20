#include <iostream>
using namespace std;
int main()
{
    float a, b, c, d, e, total, avarage, percetange;
    cout << "Enter the marks a :";
    cin >> a;
    cout << "Enter the marks b :";
    cin >> b;
    cout << "Enter the marks c :";
    cin >> c;
    cout << "Enter the marks d :";
    cin >> d;
    cout << "Enter the marks e :";
    cin >> e;

    total = a + b + c + d + e;
    avarage = total / 5.0;
    percetange = (total / 500.0) * 100;

    cout << "total marks =" << total << "\n";
    cout << "avarage =" << avarage << "\n";
    cout << "percentage =" << percetange;

    return 0;
}