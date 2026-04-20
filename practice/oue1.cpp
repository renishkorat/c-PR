#include <iostream>
#include <cstring>
using namespace std;

class Train
{
    int trainnumber;
    char trainname[50];
    char source[50];
    char destination[50];
    char traintime[10];

    static int traincount;

public:
    Train() {}

    ~Train()
    {
        traincount--;
    }

    void setTrainNumber(int num)
    {
        trainnumber = num;
    }

    void setTrainName(char name[])
    {
        strcpy(trainname, name);
    }

    void setSource(char src[])
    {
        strcpy(source, src);
    }

    void setDestination(char dest[])
    {
        strcpy(destination, dest);
    }

    void setTrainTime(char time[])
    {
        strcpy(traintime, time);
    }

    int getTrainNumber()
    {
        return trainnumber;
    }

    char *getTrainName()
    {
        return trainname;
    }

    char *getSource()
    {
        return source;
    }

    char *getDestination()
    {
        return destination;
    }

    char *getTrainTime()
    {
        return traintime;
    }

    void inputTrainDetail()
    {
        int num;
        char name[50], src[50], dest[50], time[10];

        cout << "Enter Train Number :";
        cin >> num;
        setTrainNumber(num);

        cout << "Enter Train Name :";
        cin >> name;
        setTrainName(name);

        cout << "Enter Source :";
        cin >> src;
        setSource(src);

        cout << "Enter Destination :";
        cin >> dest;
        setDestination(dest);

        cout << "Enter Train Time :";
        cin >> time;
        setTrainTime(time);
    }
    void displayTrainDetails()
    {

        cout << "Train Number :" << getTrainNumber() << endl;
        cout << "Train Name :" << getTrainName() << endl;
        cout << "Source :" << getSource() << endl;
        cout << "Destination :" << getDestination() << endl;
        cout << "Train Time :" << getTrainTime() << endl;
    }
};

int Train::traincount = 0;

class RailwaySystem
{
private:
    Train train[100];
    int totalTrain;

public:
    RailwaySystem()
    {
        totalTrain = 0;
    }

    void addTrain()
    {
        if (totalTrain < 100)
        {
            train[totalTrain].inputTrainDetail();
            totalTrain++;
        }
        else
        {
            cout << "Train storage full!" << endl;
        }
    }

    void displayAllTrain()
    {
        if (totalTrain == 0)
        {
            cout << "No record avalable." << endl;
            return;
        }
        else
        {
            for (int i = 0; i < totalTrain; i++)
            {
                cout << "\ntrain " << i + 1 << "details:" << endl;
                train[i].displayTrainDetails();
            }
        }
    }

    void searchTrainByNumber(int number)
    {
        for (int i = 0; i < totalTrain; i++)
        {
            if (train[i].getTrainNumber() == number)
            {
                train[i].displayTrainDetails();
                return;
            }
        }
        cout << "Train with number " << number << "Not found" << endl;
    }
};

int main()
{
    RailwaySystem system;
    int choice, number;

    while (true)
    {
        cout << "--- Railway Reservation System Menu ---" << endl;
        cout << "1. Add New Train Record :" << endl;
        cout << "2. Display All Train Records" << endl;
        cout << "3.Search Train by Number" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice :" << endl;
        cin >> choice;
        cout << endl;

        switch (choice)
        {

        case 1:
            system.addTrain();
            break;

        case 2:
            system.displayAllTrain();
            break;

        case 3:
            cout << "Enter the number :";
            cin >> number;
            system.searchTrainByNumber(number);
            break;

        case 4:
            cout << "Exiting the system. Goodbye" << endl;
            return 0;

        default:
            cout << "Invalid choice" << endl;
        }
    }
    return 0;
}