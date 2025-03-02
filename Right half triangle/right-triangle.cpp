#include <iostream>

int main()
{
    int n = 5; // Number of rows

    // Outer loop for rows
    for (int i = n; i >= 1; i--)
    {
        // Inner loop for columns
        for (int j = i; j <= n; j++)
        {
            std::cout << j << " ";
        }
        std::cout << std::endl; // Move to the next line
    }

        return 0;
}