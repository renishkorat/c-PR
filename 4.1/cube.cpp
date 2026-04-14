#include <iostream>
using namespace std;

// Base Class
class X {
public:
    int a, b, c;
};

// Derived Class
class Y : public X {
public:
    void setData() {
        cout << "Enter three numbers: ";
        cin >> a >> b >> c;
    }

    void getData() {
        int sum = (a * a * a) + (b * b * b) + (c * c *c);
        cout << "Sum of cubes = " << sum << endl;
    }
};

int main() {
    Y obj;
    obj.setData();
    obj.getData();
    return 0;
}