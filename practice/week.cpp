 #include <iostream>
using namespace std;
int main()
{
    int days, week, year;
    cout << "Enter the days :";
    cin >> days;

    week = (days / 7);
    year = (days / 365);

    cout << "days to week =" << week << "\n";
    cout << "days to year =" << year;

    return 0;
}