#include <iostream>
using namespace std;
class Timeconveter
{
public:
    int seconds;

    void display()
    {
        int hours = seconds / 3600;
        int minutes = (seconds % 3600) / 60;
        int sec = seconds % 60;

        cout << "HH:MM:SS => " << hours << ":" << minutes << ":" << sec;
    }
};

int main()
{
    Timeconveter t1;
    cout << "Enter the second :";
    cin >> t1.seconds;

    t1.display();
}