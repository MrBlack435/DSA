#include <iostream>

using namespace std;

int main()
{
    int rows = 4; // Number of rows in the triangle
    int num = 11; // Starting number

    for (int i = 1; i <= rows; i++)
    { // Loop for rows
        for (int j = 1; j <= i; j++)
        { // Loop for columns
            cout << num << " ";
            num++; // Increment number
        }
        cout << endl; // Move to the next line
    }

    return 0;
}
