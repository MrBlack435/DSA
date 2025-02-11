// C++ Program to Count Number of Digits in a Number
#include <iostream>
using namespace std;

int main()
{
    int num, count = 0;

    // User input
    cout << "Enter a number: ";
    cin >> num;

    // Counting total number of digits
    while (num > 0)
    {
        num = num / 10;
        count++;
    }

    cout << "Total no. of digits: " << count << endl;
        return 0;
}