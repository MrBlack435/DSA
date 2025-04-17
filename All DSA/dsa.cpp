#include <iostream>
using namespace std;

// --------------------------- Linked List Section ---------------------------

struct Node
{
    int data;
    Node *next;
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList() : head(nullptr) {}

    void insertAtEnd(int val)
    {
        Node *newNode = new Node{val, nullptr};
        if (!head)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next)
                temp = temp->next;
            temp->next = newNode;
        }
        cout << "Inserted " << val << " into linked list.\n";
    }

    void deleteValue(int val)
    {
        if (!head)
        {
            cout << "List is empty.\n";
            return;
        }
        if (head->data == val)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            cout << "Deleted " << val << " from linked list.\n";
            return;
        }
        Node *temp = head;
        while (temp->next && temp->next->data != val)
            temp = temp->next;
        if (temp->next)
        {
            Node *toDelete = temp->next;
            temp->next = toDelete->next;
            delete toDelete;
            cout << "Deleted " << val << " from linked list.\n";
        }
        else
        {
            cout << "Value not found.\n";
        }
    }

    void display()
    {
        if (!head)
        {
            cout << "List is empty.\n";
            return;
        }
        Node *temp = head;
        cout << "Linked List: ";
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// --------------------------- Sorting Section ---------------------------

// Merge Sort
void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int *L = new int[n1], *R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Quick Sort
int partition(int arr[], int low, int high)
{
    int pivot = arr[high], i = (low - 1);
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
            swap(arr[++i], arr[j]);
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Binary Search
int binarySearch(int arr[], int l, int r, int target)
{
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}

// Display Array
void displayArray(int arr[], int size)
{
    cout << "Array: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// --------------------------- Main Program ---------------------------

int main()
{
    LinkedList list;
    const int MAX = 100;
    int arr[MAX], n = 0, choice;

    do
    {
        cout << "\n--- Menu ---\n";
        cout << "1. Insert into Linked List\n";
        cout << "2. Delete from Linked List\n";
        cout << "3. Display Linked List\n";
        cout << "4. Input Array\n";
        cout << "5. Merge Sort Array\n";
        cout << "6. Quick Sort Array\n";
        cout << "7. Display Array\n";
        cout << "8. Binary Search in Sorted Array\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        int val, index;
        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> val;
            list.insertAtEnd(val);
            break;
        case 2:
            cout << "Enter value to delete: ";
            cin >> val;
            list.deleteValue(val);
            break;
        case 3:
            list.display();
            break;
        case 4:
            cout << "Enter size of array: ";
            cin >> n;
            cout << "Enter " << n << " elements:\n";
            for (int i = 0; i < n; i++)
                cin >> arr[i];
            break;
        case 5:
            mergeSort(arr, 0, n - 1);
            cout << "Array sorted using Merge Sort.\n";
            break;
        case 6:
            quickSort(arr, 0, n - 1);
            cout << "Array sorted using Quick Sort.\n";
            break;
        case 7:
            displayArray(arr, n);
            break;
        case 8:
            cout << "Enter value to search: ";
            cin >> val;
            index = binarySearch(arr, 0, n - 1, val);
            if (index != -1)
                cout << "Element found at index: " << index << endl;
            else
                cout << "Element not found.\n";
            break;
        case 9:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 9);

    return 0;
}
