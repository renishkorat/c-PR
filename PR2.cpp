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

    static int trainCount;

public:
    // Default Constructor
    Train(){}

    // Destructor
    ~Train()
    {
        trainCount--;
    }

    // Set Methods
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

    // Get Methods
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

        cout << "Enter Train Number: ";
        cin >> num;
        setTrainNumber(num);

        cout << "Enter Train Name: ";
        cin >> name;
        setTrainName(name);

        cout << "Enter Source: ";
        cin >> src;
        setSource(src);

        cout << "Enter Destination: ";
        cin >> dest;
        setDestination(dest);

        cout << "Enter Train Time: ";
        cin >> time;
        setTrainTime(time);
    }

    void displayTrainDetails()
    {
        cout << "Train Number: " << getTrainNumber() << endl;
        cout << "Train Name: " << getTrainName() << endl;
        cout << "Source: " << getSource() << endl;
        cout << "Destination: " << getDestination() << endl;
        cout << "Train Time: " << getTrainTime() << endl;
    }
};

int Train::trainCount = 0;

class RailwaySystem
{
private:
    Train trains[100];
    int totalTrains;

public:
    RailwaySystem()
    {
        totalTrains = 0;
    }

    void addTrain()
    {
        if (totalTrains < 100)
        {
            trains[totalTrains].inputTrainDetail();
            totalTrains++;
        }
        else
        {
            cout << "Train storage full!" << endl;
        }
    }

    void displayAllTrains()
    {
        if (totalTrains == 0)
        {
            cout << "No train records available." << endl;
            return;
        }
        else
        {
            for (int i = 0; i < totalTrains; i++)
            {
                cout << "\nTrain " << i + 1 << " details:" << endl;
                trains[i].displayTrainDetails();
            }
        }
    }

    void searchTrainByNumber(int number)
    {
        for (int i = 0; i < totalTrains; i++)
        {
            if (trains[i].getTrainNumber() == number)
            {
                cout << "\nTrain Found:" << endl;
                trains[i].displayTrainDetails();
                return;
            }
        }

        cout << "Train with number " << number << " not found!" << endl;
    }
};

int main()
{
    RailwaySystem system;
    int choice, number;

    while (true)
    {
        cout << "----Railway Reservation System Menu----" << endl;
        cout << "1. Add New Train Record" << endl;
        cout << "2. Display All Train Record" << endl;
        cout << "3. Search Train by Number" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice :";
        cin >> choice;
        cout << endl;

        switch (choice)
        {

        case 1:
            system.addTrain();
            break;

        case 2:
            system.displayAllTrains();
            break;

        case 3:
            cout << "Enter train number :";
            cin >> number;
            system.searchTrainByNumber(number);
            break;

        case 4:
            cout << "Exiting the system. Goodbye!" << endl;
             return 0;

        default:
            cout << "Invalid choice" << endl;
        }
    }
    return 0;
}
