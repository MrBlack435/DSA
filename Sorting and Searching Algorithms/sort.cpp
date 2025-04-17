#include <iostream>
using namespace std;

// Function to print the array
void printArray(int arr[], int size)
{
    cout << "Array: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// 1. Selection Sort
void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
            if (arr[j] < arr[minIndex])
                minIndex = j;
        swap(arr[i], arr[minIndex]);
    }
    cout << "Array sorted using Selection Sort.\n";
}

// 2. Merge Sort
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = new int[n1];
    int *R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// 3. Linear Search
int linearSearch(int arr[], int size, int target)
{
    for (int i = 0; i < size; i++)
        if (arr[i] == target)
            return i;
    return -1;
}

// 4. Binary Search (array must be sorted)
int binarySearch(int arr[], int left, int right, int target)
{
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// Main menu-driven program
int main()
{
    const int MAX = 100;
    int arr[MAX], n, choice, target;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int originalArr[MAX];
    for (int i = 0; i < n; i++)
        originalArr[i] = arr[i]; // backup

    do
    {
        cout << "\n--- Menu ---\n";
        cout << "1. Selection Sort\n";
        cout << "2. Merge Sort\n";
        cout << "3. Linear Search\n";
        cout << "4. Binary Search (on sorted array)\n";
        cout << "5. Reset to Original Array\n";
        cout << "6. Display Array\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            selectionSort(arr, n);
            printArray(arr, n);
            break;
        case 2:
            mergeSort(arr, 0, n - 1);
            cout << "Array sorted using Merge Sort.\n";
            printArray(arr, n);
            break;
        case 3:
            cout << "Enter element to search: ";
            cin >> target;
            {
                int index = linearSearch(arr, n, target);
                if (index != -1)
                    cout << "Element found at index " << index << endl;
                else
                    cout << "Element not found.\n";
            }
            break;
        case 4:
            cout << "Enter element to search: ";
            cin >> target;
            {
                int index = binarySearch(arr, 0, n - 1, target);
                if (index != -1)
                    cout << "Element found at index " << index << endl;
                else
                    cout << "Element not found.\n";
            }
            break;
        case 5:
            for (int i = 0; i < n; i++)
                arr[i] = originalArr[i];
            cout << "Array reset to original.\n";
            break;
        case 6:
            printArray(arr, n);
            break;
        case 7:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 7);

    return 0;
}
