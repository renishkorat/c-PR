//question
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



#include <iostream>
using namespace std;

class TimeConverter {
public:
    int hours, minutes, seconds;

    void input() {
        cout << "Enter hours: ";
        cin >> hours;

        cout << "Enter minutes: ";
        cin >> minutes;

        cout << "Enter seconds: ";
        cin >> seconds;
    }

    void totalSeconds() {
        int total;

 total = (hours * 3600) + (minutes * 60) + seconds;        

        cout << "\nTotal seconds: " << total;
    }
};

int main() {
    TimeConverter t;

    t.input();
    t.totalSeconds();

    return 0;
}