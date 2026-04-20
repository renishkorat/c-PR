#include <iostream>
using namespace std;

class Number {
private:
    int value;

public:
    
    Number(int v) {
        value = v;
    }

    int operator < (Number obj) {
        if (value < obj.value)
            return true;
        else
            return false;
    }

    void display() {
        cout << value;
    }
};

int main() {
    int n1, n2;

    cout << "Enter first number: ";
    cin >> n1;

    cout << "Enter second number: ";
    cin >> n2;

    Number obj1(n1), obj2(n2);

    if (obj1 < obj2) {
        cout << "Higher value is in second object: ";
        obj2.display();
    } else if (obj2 < obj1) {
        cout << "Higher value is in first object: ";
        obj1.display();
    } else {
        cout << "Both objects contain equal values.";
    }

    return 0;
}