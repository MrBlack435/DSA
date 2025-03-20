#include <iostream>

using namespace std;

void printMatrix(int arr[][10], int rows, int cols)
{
    cout << "Matrix:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

int sumOfRow(int arr[][10], int row, int cols)
{
    int sum = 0;
    for (int j = 0; j < cols; j++)
    {
        sum += arr[row][j];
    }
    return sum;
}

int sumOfColumn(int arr[][10], int col, int rows)
{
    int sum = 0;
    for (int i = 0; i < rows; i++)
    {
        sum += arr[i][col];
    }
    return sum;
}

int main()
{
    int rows, cols, rowChoice, colChoice;
    int arr[10][10]; // Maximum size of 10x10

    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> arr[i][j];
        }
    }

    printMatrix(arr, rows, cols);

    cout << "Enter row number to find sum (0-based index): ";
    cin >> rowChoice;
    if (rowChoice >= 0 && rowChoice < rows)
    {
        cout << "Sum of row " << rowChoice << " = " << sumOfRow(arr, rowChoice, cols) << endl;
    }
    else
    {
        cout << "Invalid row index!\n";
    }

    cout << "Enter column number to find sum (0-based index): ";
    cin >> colChoice;
    if (colChoice >= 0 && colChoice < cols)
    {
        cout << "Sum of column " << colChoice << " = " << sumOfColumn(arr, colChoice, rows) << endl;
    }
    else
    {
        cout << "Invalid column index!\n";
    }

    return 0;
}
