#include<iostream>
#include<string>
using namespace std;

int main()
{
    try
    {
        int a, b;

        cout << "Enter First Number: ";
        cin >> a;

        cout << "Enter Second Number: ";
        cin >> b;

        if(b == 0)
        {
            throw 101;
        }

        cout << "Answer = " << a / b << endl;
    }
    catch(int error)
    {
        cout << "Number cannot be divided by zero" << endl;
        cout << "Error Number: " << error << endl;
    }

    cout << endl;

    try
    {
        int age;

        cout << "Enter Age: ";
        cin >> age;

        if(age < 18)
        {
            throw 505;
        }

        cout << "Person can vote" << endl;
    }
    catch(int error)
    {
        cout << "Access denied - You must be at least 18 years old." << endl;
        cout << "Error Number: " << error << endl;
    }

    cout << endl;

    try
    {
        string pass;
        int flag = 0;

        cout << "Enter Password: ";
        cin >> pass;

        for(int i = 0; pass[i] != '\0'; i++)
        {
            if(pass[i] >= 'A' && pass[i] <= 'Z')
            {
                flag = 1;
                break;
            }
        }

        if(flag == 0)
        {
            throw 909;
        }

        cout << "Password is valid" << endl;
    }
    catch(int error)
    {
        cout << "Password must contain uppercase letter" << endl;
        cout << "Error Number: " << error << endl;
    }

    return 0;
}