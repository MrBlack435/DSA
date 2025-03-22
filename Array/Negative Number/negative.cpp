#include <iostream>

using namespace std;

int main() {
    int arr[5];

    // Taking input for the array
    cout << "Enter 5 integers: ";
    for(int i = 0; i < 5; i++) {
        cin >> arr[i];
    }

    // Displaying negative numbers
    cout << "Negative numbers in the array: ";
    for(int i = 0; i < 5; i++) {
        if(arr[i] < 0) {
            cout << arr[i] << " ";
        }
    }

    return 0;
}
