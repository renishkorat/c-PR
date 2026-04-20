#include <iostream>
using namespace std;
int main()
{
    int length, width, perimeter;
    cout << "Enter valueof length :";
    cin >> length;
    cout << "Enter value width :";
    cin >> width;

    perimeter = 2 * (length + width);

    cout << "perimeter =" << perimeter;

    return 0;
}