#include <iostream>
using namespace std;

int main()
{
    int n = 5; // Number of rows

    for (int i = 1; i <= n; i++)
    {
        // Printing spaces
        for (int j = 0; j < (n - i) * 3; j++)
        {
            cout << " ";
        }

        // Printing increasing numbers
        for (int j = n - i + 1; j <= n; j++)
        {
            cout << j << " ";
        }

        // Printing decreasing numbers
        for (int j = n - 1; j >= n - i + 1; j--)
        {
            cout << j << " ";
        }

        cout << endl;
    }

    return 0;
}
