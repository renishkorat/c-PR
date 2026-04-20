#include <iostream>
using namespace std;

int main() {
    int start, end;
    int arr[100];
    int j = 0;

    cout << "Enter the first number: ";
    cin >> start;

    cout << "Enter the second number: ";
    cin >> end;

    for(int i = start; i <= end; i++) {
        if(i % 4 == 0) {
            arr[j] = i;
            j++;
        }
    }

    cout << "The leep year is: ";
    for(int i = 0; i < j; i++) {
        cout << arr[i]<<",";
    }

    return 0;
}