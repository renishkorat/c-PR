#include<iostream>
using namespace std;

class Time {
public:
    int hour;
    int minute;
    int second;

    void inputtime1(int sec) {
        hour = sec / 3600;
        minute = (sec % 3600) / 60;
        second = sec % 60;

        cout << hour << ":" << minute << ":" << second << endl;
    }

    void inputtime2(int hr, int min, int sec) {
        int totalSeconds = hr * 3600 + min * 60 + sec;
        cout << totalSeconds << endl;
    }
};

int main() {
    Time t1;
    int number;

    cout << "Press 1: Seconds → HH:MM:SS" << endl;
    cout << "Press 2: HH:MM:SS → Seconds" << endl;

    cin >> number;

    int sec, hr, min;

    if (number == 1) {
        cout << "Enter seconds:" << endl;
        cin >> sec;
        t1.inputtime1(sec);
    }
    else if (number == 2) {
        cout << "Enter hours:" << endl;
        cin >> hr;
        cout << "Enter minutes:" << endl;
        cin >> min;
        cout << "Enter seconds:" << endl;
        cin >> sec;

        t1.inputtime2(hr, min, sec);
    }
    else {
        cout << "Invalid input" << endl;
    }
}