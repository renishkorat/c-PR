#include <iostream>
using namespace std;

class Vehicle
{
protected:
    int vehicleID;
    string manufacturer;
    int model;
    int year;

    static int totalVehicle;

public:
    Vehicle() {}

    virtual ~Vehicle()
    {
        totalVehicle--;
    }

    void setID(int id)
    {
        vehicleID = id;
    }
    void setManufacturer(string m)
    {
        manufacturer = m;
    }
    void setModel(int m2)
    {
        model = m2;
    }
    void setYear(int y)
    {
        year = y;
    }

    int getID()
    {
        return vehicleID;
    }

    void inputBasic()
{
    cout << "Enter ID: ";
    cin >> vehicleID;

    cout << "Manufacturer: ";
    cin >> manufacturer;

    cout << "Model: ";
    cin >> model;

    cout << "Year: ";
    cin >> year;
}

    virtual void display()
    {
        cout << "ID: " << vehicleID << endl;
        cout << "Manufacturer: " << manufacturer << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
    }
};

int Vehicle::totalVehicle = 0;

class Car : public Vehicle
{
protected:
    string fuelType;

public:
    void setFuelType(string f)
    {
        fuelType = f;
    }

    void display() 
    {
        Vehicle::display();
        cout << "\nFuel Type: " << fuelType;
    }
};

class ElectricCar : public Car
{
    int batteryCapacity;

public:
    void setbatteryCapacity(int b)
    {
        batteryCapacity = b;
    }

    void display() 
    {
        Car::display();
        cout << "\nBattery Capacity: " << batteryCapacity << " kwh";
    }
};

class Aircraft
{
protected:
    int flightRange;

public:
    void setflightRange(int r)
    {
        flightRange = r;
    }
    void showAircraft()
    {
        cout << "flightRange" << flightRange << "km";
    }
};

class FlyingCar : public Car, public Aircraft
{
    void display()
    {
        cout << "----FlyingCar----" << endl;
        Car::display();
        showAircraft();
    }
};

class SportsCar : public ElectricCar
{
    int topSpeed;

public:
    void setTopSpeed(int s)
    {
        topSpeed = s;
    }

    void display()
    {
        ElectricCar::display();
        cout << "\nTop Speed: " << topSpeed << " km/h";
    }
};

class Sedan : public Car
{
    void display()
    {
        cout << "----sedan----";
        Car::display();
    }
};

class SUV : public Car
{
    void display()
    {
        cout << "----SUV----";
        Car::display();
    }
};

class VehicleRegistry
{
    Vehicle *list[100];
    int count;

public:
    VehicleRegistry()
    {
        count = 0;
    }
    void addVehicle(Vehicle *v)
    {
        list[count++] = v;
    }

    void displayAll()
    {
        for (int i = 0; i < count; i++)
        {
            list[i]->display();
        }
    }

    void search(int id)
    {
        for (int i = 0; i < count; i++)
        {
            if (list[i]->getID() == id)
            {
                cout << "Vehicle found:" << endl;
                list[i]->display();
                return;
            }
        }
        cout << "Vehicle not Found." << endl;
    }
};

int main()
{
    VehicleRegistry r;
    int choice;

    while (true)
    {
        cout << "\n----Vehicle Registry System----" << endl;
        cout << "1. Add a vehicle (of a different type)" << endl;
        cout << "2. View all vehicles" << endl;
        cout << "3. Search by Id" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice:";
        cin >> choice;

        switch (choice)
        {

        case 1:
        {
            int sub;

            cout << "----Select Vehicle----" << endl;
            cout << "1. Car" << endl;
            cout << "2. Electric Car" << endl;
            cout << "3. Aircraft" << endl;
            cout << "4. Flying Car" << endl;
            cout << "5. Sports Car" << endl;
            cout << "6. Sedan" << endl;
            cout << "7. SUV" << endl;
            cout << "Enter your choice:";
            cin >> sub;

            int id, year, battery,model, speed, range;
            string manu, fuel;

            if (sub == 1)
            {
                Car *c = new Car();

                c->inputBasic();

                cout << "Fuel Type: ";
                cin >> fuel;

                c->setID(id);
                c->setManufacturer(manu);
                c->setModel(model);
                c->setYear(year);
                c->setFuelType(fuel);

                r.addVehicle(c);

                cout << "Car Added Successfully!" << endl;
            }

            if (sub == 2)
            {
                ElectricCar *e = new ElectricCar();

                e->inputBasic();

                cout << "Fuel Type: ";
                cin >> fuel;

                cout << "Battery Capacity: ";
                cin >> battery;

                e->setID(id);
                e->setManufacturer(manu);
                e->setModel(model);
                e->setYear(year);
                e->setFuelType(fuel);
                e->setbatteryCapacity(battery);

                r.addVehicle(e);

                cout << "Electric Car Added Successfully!" << endl;
            }

            if (sub == 3)
            {
                Aircraft *a = new Aircraft();

                cout << "Enter Flight Range: ";
                cin >> range;

                a->setflightRange(range);

                cout << "Aircraft Added Successfully!" << endl;
            }

            if (sub == 4)
            {
                FlyingCar *f = new FlyingCar();

                f->inputBasic();

                cout << "Fuel Type: ";
                cin >> fuel;

                cout << "Flight Range: ";
                cin >> range;

                f->setID(id);
                f->setManufacturer(manu);
                f->setModel(model);
                f->setYear(year);
                f->setFuelType(fuel);
                f->setflightRange(range);

                r.addVehicle(f);

                cout << "Flying Car Added Successfully!" << endl;
            }

            if (sub == 5)
            {
                SportsCar *s = new SportsCar();

                s->inputBasic();

                cout << "Fuel Type: ";
                cin >> fuel;

                cout << "Battery Capacity: ";
                cin >> battery;

                cout << "Top Speed: ";
                cin >> speed;

                s->setID(id);
                s->setManufacturer(manu);
                s->setModel(model);
                s->setYear(year);
                s->setFuelType(fuel);
                s->setbatteryCapacity(battery);
                s->setTopSpeed(speed);

                r.addVehicle(s);

                cout << "Sports Car Added Successfully!" << endl;
            }

            if (sub == 6)
            {
                Sedan *s = new Sedan();

                s->inputBasic();

                cout << "Fuel Type: ";
                cin >> fuel;

                s->setID(id);
                s->setManufacturer(manu);
                s->setModel(model);
                s->setYear(year);
                s->setFuelType(fuel);

                r.addVehicle(s);

                cout << "Sedan Added Successfully!" << endl;
            }

            if (sub == 7)
            {
                SUV *s = new SUV();

                s->inputBasic();

                cout << "Fuel Type: ";
                cin >> fuel;

                s->setID(id);
                s->setManufacturer(manu);
                s->setModel(model);
                s->setYear(year);
                s->setFuelType(fuel);

                r.addVehicle(s);

                cout << "SUV Added Successfully!" << endl;
            }

            break;
        }

        case 2:
            r.displayAll();
            break;

        case 3:
        {
            int id;

            cout << "Enter Vehicle ID: ";
            cin >> id;

            r.search(id);
            break;
        }

        case 4:
            cout << "Exiting Goodbye!" << endl;
            return 0;

        default:
            cout << "Invalid Choice!" << endl;
        }
    }
    return 0;
}