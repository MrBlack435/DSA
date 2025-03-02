#include <iostream>
using namespace std;

int main()
{
    int n = 5; // Number of rows

    for (int i = 0; i < n; i++)
    {
        // Print leading spaces
        for (int j = 0; j < i; j++)
        {
            cout << "  "; // Two spaces for alignment
        }
        // Print alternating 1s and 0s
        for (int j = 0; j < n - i; j++)
        {
            cout << (j % 2) << " ";
        }
        cout << endl;
    }

        return 0;
}